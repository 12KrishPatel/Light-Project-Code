# Light Matrix

A 16×16 WS2812B LED matrix driven by an Arduino Nano, plus a web app so you can plug in over USB, paint pixel art, or pick a design from the catalog and send it to the board live.

## What’s in this repo

| Path | Purpose |
|------|---------|
| [`firmware/pixel_matrix/`](firmware/pixel_matrix/) | New firmware — receives frames over USB Serial |
| [`web/`](web/) | React app (editor + catalog + Web Serial) |
| [`charmander/charmander.ino`](charmander/charmander.ino) | Original slideshow sketch (archived) |
| [`scripts/convert-patterns.mjs`](scripts/convert-patterns.mjs) | Regenerates catalog JSON from pattern data |

## Hardware

- Arduino **Nano** (ATmega328P)
- 16×16 WS2812B matrix
- Data pin **4** (same as the original project)
- USB cable for power + Serial

## 1. Flash the firmware (one time)

1. Install [Arduino IDE](https://www.arduino.cc/en/software) and the **FastLED** library.
2. Open [`firmware/pixel_matrix/pixel_matrix.ino`](firmware/pixel_matrix/pixel_matrix.ino).
3. Select:
   - **Board:** Arduino Nano
   - **Processor:** ATmega328P  
     If upload fails on an older clone, try **ATmega328P (Old Bootloader)**.
4. Pick the correct USB port and upload.

On boot the matrix shows a heart until a frame arrives from the website.

Some Nano clones need a **CH340** USB driver on your computer.

## 2. Run the website

```bash
cd web
npm install
npm run dev
```

Open the local URL Vite prints (usually `http://localhost:5173`) in **Chrome** or **Edge**.

Safari and most mobile browsers do **not** support Web Serial.

## 3. Connect and customize

1. Plug the Nano into your computer with USB.
2. Click **Connect board** and choose the Arduino’s serial port.
3. Paint on the 16×16 canvas, or click a design in the catalog.
4. Click **Send to board**.

You can use the editor and catalog without a board; sending requires a connection.

## Serial protocol

| Command | Payload | Response |
|---------|---------|----------|
| `PX16` | 768 bytes RGB (LED 0→255) | `OK` |
| `CLEAR` | (none) | `OK` |

Baud rate: **115200**.

## Catalog

Nineteen designs from the original project live in [`web/src/catalog/`](web/src/catalog/) as full 256-color frames. To regenerate them:

```bash
node scripts/convert-patterns.mjs
```

## Original project

Built for Bartlett High School’s STEM Magnet Academy. The first version cycled hard-coded patterns from program memory. This update adds the catalog site and live USB updates that were the long-term goal.
