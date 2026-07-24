import { GRID_SIZE, PIXEL_COUNT } from "./pixels";

/**
 * Physical WS2812 matrix wiring:
 * - serpentine rows: even L→R, odd R→L
 * - panel is mirrored horizontally vs a normal screen
 *
 * Catalog + Serial use LED-strip index order.
 * Editor/UI use visual row-major (x left→right, y top→bottom).
 */

function flipX(x: number): number {
  return GRID_SIZE - 1 - x;
}

export function ledIndexToXY(ledIndex: number): { x: number; y: number } {
  const y = Math.floor(ledIndex / GRID_SIZE);
  const xInRow = ledIndex % GRID_SIZE;
  const serpX = y % 2 === 0 ? xInRow : flipX(xInRow);
  return { x: flipX(serpX), y };
}

export function xyToLedIndex(x: number, y: number): number {
  const serpX = flipX(x);
  const xInRow = y % 2 === 0 ? serpX : flipX(serpX);
  return y * GRID_SIZE + xInRow;
}

/** LED-strip order → visual row-major for on-screen editing. */
export function toVisual(ledPixels: string[]): string[] {
  const visual = Array.from({ length: PIXEL_COUNT }, () => "#000000");
  for (let led = 0; led < PIXEL_COUNT; led++) {
    const { x, y } = ledIndexToXY(led);
    visual[y * GRID_SIZE + x] = ledPixels[led] ?? "#000000";
  }
  return visual;
}

/** Visual row-major → LED-strip order for sending to the board. */
export function toLed(visualPixels: string[]): string[] {
  const led = Array.from({ length: PIXEL_COUNT }, () => "#000000");
  for (let y = 0; y < GRID_SIZE; y++) {
    for (let x = 0; x < GRID_SIZE; x++) {
      led[xyToLedIndex(x, y)] = visualPixels[y * GRID_SIZE + x] ?? "#000000";
    }
  }
  return led;
}
