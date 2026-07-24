import { useCallback, useEffect, useMemo, useRef, useState } from "react";
import { CatalogPanel } from "./components/CatalogPanel";
import { PixelGrid } from "./components/PixelGrid";
import { catalog } from "./catalog";
import { toLed, toVisual } from "./lib/matrixMap";
import { createBlankPixels } from "./lib/pixels";
import { BoardConnection, isWebSerialSupported } from "./lib/serial";
import type { ConnectionState, Design } from "./types";
import "./App.css";

const PALETTE = [
  "#FF0000",
  "#FFA500",
  "#FFFF00",
  "#00FF00",
  "#008000",
  "#66CDAA",
  "#0000FF",
  "#000080",
  "#EF0BA7",
  "#E810E2",
  "#F4A460",
  "#180C00",
  "#FFFFFF",
  "#0F0F0F",
  "#800000",
  "#000000",
];

export default function App() {
  const boardRef = useRef(new BoardConnection());
  const [view, setView] = useState<"landing" | "studio">("landing");
  // Editor pixels are visual row-major; catalog/board use serpentine LED order.
  const [pixels, setPixels] = useState(() => {
    const heart = catalog.find((d) => d.id === "heart");
    return heart ? toVisual(heart.pixels) : createBlankPixels();
  });
  const [color, setColor] = useState("#FF5A5F");
  const [tool, setTool] = useState<"paint" | "eraser">("paint");
  const [category, setCategory] = useState("All");
  const [selectedId, setSelectedId] = useState<string | null>("heart");
  const [connection, setConnection] = useState<ConnectionState>(() =>
    isWebSerialSupported() ? "disconnected" : "unsupported"
  );
  const [status, setStatus] = useState("Draw freely, or pick a design from the catalog.");
  const [busy, setBusy] = useState(false);

  useEffect(() => {
    return () => {
      void boardRef.current.disconnect();
    };
  }, []);

  const connected = connection === "connected";

  const statusTone = useMemo(() => {
    if (connection === "unsupported") return "warn";
    if (connection === "connected") return "ok";
    return "neutral";
  }, [connection]);

  const showingName = useMemo(() => {
    if (selectedId) {
      const design = catalog.find((d) => d.id === selectedId);
      return design ? `${design.id}.pixel` : "custom.pixel";
    }
    return "custom.pixel";
  }, [selectedId]);

  async function handleConnect() {
    if (!isWebSerialSupported()) {
      setConnection("unsupported");
      setStatus("Use Chrome or Edge on desktop to connect over USB.");
      return;
    }
    setBusy(true);
    setConnection("connecting");
    setStatus("Select your Arduino Nano in the browser dialog…");
    try {
      await boardRef.current.connect();
      setConnection("connected");
      setStatus("Connected. Paint or pick a design, then send it to the matrix.");
      setView("studio");
    } catch (err) {
      setConnection("disconnected");
      setStatus(err instanceof Error ? err.message : "Could not connect to the board.");
    } finally {
      setBusy(false);
    }
  }

  async function handleDisconnect() {
    setBusy(true);
    await boardRef.current.disconnect();
    setConnection("disconnected");
    setStatus("Disconnected. You can still edit and browse the catalog.");
    setBusy(false);
  }

  async function handleSend() {
    if (!connected) {
      setStatus("Connect the board first to send a frame.");
      return;
    }
    setBusy(true);
    setStatus("Sending frame…");
    try {
      await boardRef.current.sendPixels(toLed(pixels));
      setStatus("Frame sent to the matrix.");
    } catch (err) {
      setStatus(err instanceof Error ? err.message : "Failed to send frame.");
    } finally {
      setBusy(false);
    }
  }

  async function handleClearBoard() {
    if (!connected) return;
    setBusy(true);
    try {
      await boardRef.current.clearBoard();
      setStatus("Matrix cleared.");
    } catch (err) {
      setStatus(err instanceof Error ? err.message : "Failed to clear matrix.");
    } finally {
      setBusy(false);
    }
  }

  const loadDesign = useCallback((design: Design) => {
    setPixels(toVisual(design.pixels));
    setSelectedId(design.id);
    setStatus(`Loaded “${design.name}”.`);
  }, []);

  const handlePixelsChange = useCallback((next: string[]) => {
    setPixels(next);
    setSelectedId(null);
  }, []);

  if (view === "landing") {
    return (
      <div className="shell landing">
        <div className="landing__wrap">
          <div>
            <div className="eyebrow">● hardware toy · diy</div>
            <h1>
              Light
              <br />
              Matrix
            </h1>
            <p className="landing__tagline">Draw it. Plug in. Light up.</p>
            <p className="landing__subtitle">
              Customize your 16×16 LED matrix — paint pixel by pixel, or pick a
              design from the catalog and beam it straight to the board.
            </p>
            <div className="landing__actions">
              <button
                type="button"
                className="btn btn--primary"
                onClick={() => void handleConnect()}
                disabled={busy || connection === "unsupported"}
              >
                Connect board
              </button>
              <button
                type="button"
                className="btn btn--secondary"
                onClick={() => setView("studio")}
              >
                Open editor
              </button>
            </div>
            {connection === "unsupported" && (
              <p className="banner banner--warn">
                Web Serial needs Chrome or Edge on a desktop computer.
              </p>
            )}
          </div>

          <div className="landing__preview-col">
            <div className="grid-window">
              <PixelGrid
                pixels={pixels}
                color={color}
                tool="paint"
                interactive={false}
                label="Preview of current design"
              />
            </div>
            <p className="caption">currently showing: {showingName}</p>
          </div>
        </div>
      </div>
    );
  }

  return (
    <div className="shell studio">
      <header className="topbar">
        <div className="topbar__brand">
          <button type="button" className="brand-link" onClick={() => setView("landing")}>
            Light Matrix
          </button>
          <span className={`status status--${statusTone}`}>{status}</span>
        </div>
        <div className="topbar__actions">
          {connection === "unsupported" ? (
            <span className="banner banner--warn banner--inline">Chrome / Edge required</span>
          ) : connected ? (
            <button
              type="button"
              className="btn btn--secondary"
              onClick={() => void handleDisconnect()}
              disabled={busy}
            >
              Disconnect
            </button>
          ) : (
            <button
              type="button"
              className="btn btn--secondary"
              onClick={() => void handleConnect()}
              disabled={busy}
            >
              Connect board
            </button>
          )}
          <button
            type="button"
            className="btn btn--primary"
            onClick={() => void handleSend()}
            disabled={busy || !connected}
          >
            Send to board
          </button>
        </div>
      </header>

      <main className="studio__layout">
        <CatalogPanel
          activeCategory={category}
          selectedId={selectedId}
          onCategoryChange={setCategory}
          onSelect={loadDesign}
        />

        <section className="canvas-panel">
          <div className="grid-window grid-window--studio canvas-panel__frame">
            <PixelGrid
              pixels={pixels}
              color={color}
              tool={tool}
              onChange={handlePixelsChange}
            />
          </div>
          <p className="canvas-panel__hint">click + drag to paint · {showingName}</p>
        </section>

        <aside className="tools">
          <h2>Tools</h2>
          <div className="tools__row">
            <button
              type="button"
              className={tool === "paint" ? "chip chip--active" : "chip"}
              onClick={() => setTool("paint")}
            >
              Paint
            </button>
            <button
              type="button"
              className={tool === "eraser" ? "chip chip--active" : "chip"}
              onClick={() => setTool("eraser")}
            >
              Eraser
            </button>
          </div>

          <label className="color-field">
            <span>Color</span>
            <input
              type="color"
              value={color.length === 7 ? color : "#ff5a5f"}
              onChange={(e) => {
                setColor(e.target.value.toUpperCase());
                setTool("paint");
              }}
            />
          </label>

          <div className="palette" role="list" aria-label="Quick colors">
            {PALETTE.map((swatch) => (
              <button
                key={swatch}
                type="button"
                className={color.toUpperCase() === swatch ? "swatch swatch--active" : "swatch"}
                style={{ backgroundColor: swatch === "#000000" ? "var(--socket)" : swatch }}
                aria-label={`Use ${swatch}`}
                onClick={() => {
                  setColor(swatch);
                  setTool("paint");
                }}
              />
            ))}
          </div>

          <div className="tools__stack">
            <button
              type="button"
              className="btn btn--secondary"
              onClick={() => {
                setPixels(createBlankPixels());
                setSelectedId(null);
                setStatus("Canvas cleared.");
              }}
            >
              Clear canvas
            </button>
            <button
              type="button"
              className="btn btn--secondary"
              onClick={() => {
                setPixels(Array.from({ length: 256 }, () => color));
                setSelectedId(null);
                setStatus("Canvas filled.");
              }}
            >
              Fill canvas
            </button>
            <button
              type="button"
              className="btn btn--secondary"
              onClick={() => void handleClearBoard()}
              disabled={busy || !connected}
            >
              Blank matrix
            </button>
          </div>
        </aside>
      </main>
    </div>
  );
}
