export const GRID_SIZE = 16;
export const PIXEL_COUNT = GRID_SIZE * GRID_SIZE;

export function createBlankPixels(color = "#000000"): string[] {
  return Array.from({ length: PIXEL_COUNT }, () => color);
}

export function clonePixels(pixels: string[]): string[] {
  return [...pixels];
}

export function hexToRgb(hex: string): [number, number, number] {
  const normalized = hex.replace("#", "").trim();
  const full =
    normalized.length === 3
      ? normalized
          .split("")
          .map((c) => c + c)
          .join("")
      : normalized.padStart(6, "0").slice(0, 6);
  const value = Number.parseInt(full, 16);
  return [(value >> 16) & 0xff, (value >> 8) & 0xff, value & 0xff];
}

export function pixelsToRgbBytes(pixels: string[]): Uint8Array {
  const bytes = new Uint8Array(PIXEL_COUNT * 3);
  for (let i = 0; i < PIXEL_COUNT; i++) {
    const [r, g, b] = hexToRgb(pixels[i] ?? "#000000");
    const o = i * 3;
    bytes[o] = r;
    bytes[o + 1] = g;
    bytes[o + 2] = b;
  }
  return bytes;
}

export function indexFromCoords(x: number, y: number): number {
  return y * GRID_SIZE + x;
}
