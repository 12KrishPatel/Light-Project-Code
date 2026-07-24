import { pixelsToRgbBytes } from "./pixels";

const BAUD_RATE = 115200;
const HEADER = new TextEncoder().encode("PX16");
const CLEAR = new TextEncoder().encode("CLEAR");

export type SerialPortLike = {
  open: (options: { baudRate: number }) => Promise<void>;
  close: () => Promise<void>;
  readable: ReadableStream<Uint8Array> | null;
  writable: WritableStream<Uint8Array> | null;
  getInfo?: () => { usbVendorId?: number; usbProductId?: number };
};

declare global {
  interface Navigator {
    serial?: {
      requestPort: () => Promise<SerialPortLike>;
      getPorts: () => Promise<SerialPortLike[]>;
    };
  }
}

export function isWebSerialSupported(): boolean {
  return typeof navigator !== "undefined" && !!navigator.serial;
}

export class BoardConnection {
  private port: SerialPortLike | null = null;
  private writer: WritableStreamDefaultWriter<Uint8Array> | null = null;
  private reader: ReadableStreamDefaultReader<Uint8Array> | null = null;
  private readBuffer = "";

  get connected(): boolean {
    return this.port !== null && this.writer !== null;
  }

  async connect(): Promise<void> {
    if (!navigator.serial) {
      throw new Error("Web Serial is not supported in this browser.");
    }
    if (this.connected) return;

    const port = await navigator.serial.requestPort();
    await port.open({ baudRate: BAUD_RATE });
    this.port = port;
    this.writer = port.writable?.getWriter() ?? null;
    this.reader = port.readable?.getReader() ?? null;

    if (!this.writer) {
      await this.disconnect();
      throw new Error("Could not open a writable serial stream.");
    }
  }

  async disconnect(): Promise<void> {
    try {
      this.reader?.releaseLock();
    } catch {
      /* ignore */
    }
    try {
      this.writer?.releaseLock();
    } catch {
      /* ignore */
    }
    try {
      await this.port?.close();
    } catch {
      /* ignore */
    }
    this.reader = null;
    this.writer = null;
    this.port = null;
    this.readBuffer = "";
  }

  async sendPixels(pixels: string[]): Promise<void> {
    if (!this.writer) {
      throw new Error("Board is not connected.");
    }
    const frame = pixelsToRgbBytes(pixels);
    const packet = new Uint8Array(HEADER.length + frame.length);
    packet.set(HEADER, 0);
    packet.set(frame, HEADER.length);
    await this.writer.write(packet);
    await this.waitForAck(2500);
  }

  async clearBoard(): Promise<void> {
    if (!this.writer) {
      throw new Error("Board is not connected.");
    }
    await this.writer.write(CLEAR);
    await this.waitForAck(1500);
  }

  private async waitForAck(timeoutMs: number): Promise<void> {
    if (!this.reader) {
      // Some environments may not expose readable; don't block forever.
      await delay(80);
      return;
    }

    const deadline = Date.now() + timeoutMs;
    while (Date.now() < deadline) {
      if (this.readBuffer.includes("OK")) {
        this.readBuffer = this.readBuffer.replace(/.*?OK\r?\n?/, "");
        return;
      }

      const remaining = deadline - Date.now();
      const result = await Promise.race([
        this.reader.read(),
        delay(remaining).then(() => null),
      ]);

      if (!result) {
        break;
      }
      if (result.done) {
        break;
      }
      this.readBuffer += new TextDecoder().decode(result.value);
      if (this.readBuffer.length > 256) {
        this.readBuffer = this.readBuffer.slice(-64);
      }
    }

    // Firmware may still have applied the frame even if ACK was missed.
  }
}

function delay(ms: number): Promise<void> {
  return new Promise((resolve) => {
    window.setTimeout(resolve, ms);
  });
}
