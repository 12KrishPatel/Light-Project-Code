import { useEffect, useRef } from "react";
import { GRID_SIZE, PIXEL_COUNT, indexFromCoords } from "../lib/pixels";

type Props = {
  pixels: string[];
  color: string;
  tool: "paint" | "eraser";
  interactive?: boolean;
  onChange?: (next: string[]) => void;
  className?: string;
  label?: string;
};

function isOff(hex: string): boolean {
  const n = hex.replace("#", "").toLowerCase();
  return n === "000000" || n === "000";
}

function paintCell(el: HTMLElement, hex: string) {
  if (isOff(hex)) {
    el.className = "pixel pixel--off";
    el.style.backgroundColor = "";
  } else {
    el.className = "pixel pixel--on";
    el.style.backgroundColor = hex;
  }
}

export function PixelGrid({
  pixels,
  color,
  tool,
  interactive = true,
  onChange,
  className = "",
  label = "16 by 16 pixel canvas",
}: Props) {
  const rootRef = useRef<HTMLDivElement>(null);
  const draftRef = useRef<string[]>(pixels);
  const paintingRef = useRef(false);
  const lastIndexRef = useRef<number | null>(null);
  const colorRef = useRef(color);
  const toolRef = useRef(tool);
  const onChangeRef = useRef(onChange);

  colorRef.current = color;
  toolRef.current = tool;
  onChangeRef.current = onChange;

  // Sync from parent when a new design is loaded / canvas cleared / etc.
  useEffect(() => {
    if (paintingRef.current) return;
    draftRef.current = pixels.slice();
    const root = rootRef.current;
    if (!root) return;
    const cells = root.children;
    for (let i = 0; i < PIXEL_COUNT && i < cells.length; i++) {
      paintCell(cells[i] as HTMLElement, pixels[i] ?? "#000000");
    }
  }, [pixels]);

  function applyAt(index: number) {
    if (!interactive) return;
    if (lastIndexRef.current === index) return;
    lastIndexRef.current = index;

    const paintColor = toolRef.current === "eraser" ? "#000000" : colorRef.current;
    if (draftRef.current[index] === paintColor) return;

    draftRef.current[index] = paintColor;
    const cell = rootRef.current?.children[index] as HTMLElement | undefined;
    if (cell) paintCell(cell, paintColor);
  }

  function coordsFromEvent(target: HTMLElement, clientX: number, clientY: number) {
    const rect = target.getBoundingClientRect();
    const x = Math.floor(((clientX - rect.left) / rect.width) * GRID_SIZE);
    const y = Math.floor(((clientY - rect.top) / rect.height) * GRID_SIZE);
    if (x < 0 || y < 0 || x >= GRID_SIZE || y >= GRID_SIZE) return null;
    return indexFromCoords(x, y);
  }

  function commit() {
    if (!paintingRef.current) return;
    paintingRef.current = false;
    lastIndexRef.current = null;
    onChangeRef.current?.([...draftRef.current]);
  }

  return (
    <div
      ref={rootRef}
      className={`pixel-grid ${interactive ? "pixel-grid--interactive" : ""} ${className}`}
      role={interactive ? "application" : "img"}
      aria-label={label}
      onPointerDown={(e) => {
        if (!interactive) return;
        e.preventDefault();
        paintingRef.current = true;
        lastIndexRef.current = null;
        // Own a mutable copy for this stroke — never mutate React state in place.
        draftRef.current = draftRef.current.slice();
        (e.currentTarget as HTMLElement).setPointerCapture(e.pointerId);
        const idx = coordsFromEvent(e.currentTarget, e.clientX, e.clientY);
        if (idx !== null) applyAt(idx);
      }}
      onPointerMove={(e) => {
        if (!interactive || !paintingRef.current) return;
        const idx = coordsFromEvent(e.currentTarget, e.clientX, e.clientY);
        if (idx !== null) applyAt(idx);
      }}
      onPointerUp={commit}
      onPointerCancel={commit}
    >
      {Array.from({ length: PIXEL_COUNT }, (_, i) => {
        const pixel = pixels[i] ?? "#000000";
        const off = isOff(pixel);
        return (
          <span
            key={i}
            className={off ? "pixel pixel--off" : "pixel pixel--on"}
            style={off ? undefined : { backgroundColor: pixel }}
          />
        );
      })}
    </div>
  );
}
