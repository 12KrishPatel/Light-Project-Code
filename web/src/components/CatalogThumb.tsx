import { useEffect, useRef } from "react";
import { ledIndexToXY } from "../lib/matrixMap";
import { GRID_SIZE, PIXEL_COUNT } from "../lib/pixels";

type Props = {
  /** LED-strip index order (same as catalog / board). */
  pixels: string[];
  label: string;
  className?: string;
};

function parseRgb(hex: string): [number, number, number] {
  const n = hex.replace("#", "");
  const full =
    n.length === 3
      ? n
          .split("")
          .map((c) => c + c)
          .join("")
      : n.padStart(6, "0").slice(0, 6);
  const v = Number.parseInt(full, 16);
  return [(v >> 16) & 255, (v >> 8) & 255, v & 255];
}

/** Tiny static preview — one canvas instead of 256 DOM nodes. */
export function CatalogThumb({ pixels, label, className = "" }: Props) {
  const canvasRef = useRef<HTMLCanvasElement>(null);

  useEffect(() => {
    const canvas = canvasRef.current;
    if (!canvas) return;
    const ctx = canvas.getContext("2d");
    if (!ctx) return;

    const image = ctx.createImageData(GRID_SIZE, GRID_SIZE);
    // Fill socket cream, then place LEDs into visual (x,y).
    for (let i = 0; i < PIXEL_COUNT; i++) {
      const o = i * 4;
      image.data[o] = 240;
      image.data[o + 1] = 228;
      image.data[o + 2] = 208;
      image.data[o + 3] = 255;
    }
    for (let led = 0; led < PIXEL_COUNT; led++) {
      const hex = pixels[led] ?? "#000000";
      if (hex.replace("#", "").toLowerCase() === "000000") continue;
      const { x, y } = ledIndexToXY(led);
      const [r, g, b] = parseRgb(hex);
      const o = (y * GRID_SIZE + x) * 4;
      image.data[o] = r;
      image.data[o + 1] = g;
      image.data[o + 2] = b;
      image.data[o + 3] = 255;
    }
    ctx.putImageData(image, 0, 0);
  }, [pixels]);

  return (
    <canvas
      ref={canvasRef}
      className={`catalog-thumb ${className}`}
      width={GRID_SIZE}
      height={GRID_SIZE}
      aria-label={label}
      role="img"
    />
  );
}
