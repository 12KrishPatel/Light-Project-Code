# Light Matrix

Paint a 16×16 design in the browser, or pick one from the catalog, and send it over USB to a WS2812B matrix on an Arduino Nano.

The site is a React editor with a design catalog and Web Serial. The board runs firmware that takes a full RGB frame and shows it immediately. The original slideshow sketch is still in the repo as an archive.

## What’s in this repo

| Path | Purpose |
|------|---------|
| [`web/`](web/) | React app: landing page, pixel editor, catalog, Web Serial |
| [`firmware/pixel_matrix/`](firmware/pixel_matrix/) | Arduino Nano firmware that receives frames over USB Serial |
| [`charmander/charmander.ino`](charmander/charmander.ino) | Original slideshow sketch (archived) |
| [`scripts/convert-patterns.mjs`](scripts/convert-patterns.mjs) | Rebuilds catalog JSON from the archived sketch |

## Hardware

- Arduino **Nano** (ATmega328P)
- 16×16 WS2812B matrix, 256 LEDs
- Data pin **4**
- USB cable for power and Serial

Wiring is serpentine (even rows left to right, odd rows right to left) and the panel is mirrored horizontally relative to a normal screen. The editor shows a normal left-to-right canvas and maps pixels into LED order before sending.

## 1. Flash the firmware

Do this once, or again whenever `pixel_matrix.ino` changes.

1. Install the [Arduino IDE](https://www.arduino.cc/en/software) and the **FastLED** library.
2. Open [`firmware/pixel_matrix/pixel_matrix.ino`](firmware/pixel_matrix/pixel_matrix.ino).
3. Select:
   - **Board:** Arduino Nano
   - **Processor:** ATmega328P
     If upload fails on an older clone, try **ATmega328P (Old Bootloader)**.
4. Pick the Nano’s USB port and upload.

On boot the matrix shows a heart until a frame arrives from the site. Brightness is fixed at 64.

Some Nano clones need a **CH340** USB driver on the computer.

## 2. Run the website

```bash
cd web
npm install
npm run dev
```

Open the local URL Vite prints (usually `http://localhost:5173`) in **Chrome** or **Edge**. Safari and most mobile browsers do not support Web Serial.

`npm run build` typechecks and builds a production bundle. `npm run preview` serves that bundle locally.

## 3. Connect and customize

1. Plug the Nano into the computer with USB.
2. Click **Connect board** and choose the Arduino’s serial port.
3. Paint on the 16×16 canvas, or click a design in the catalog.
4. Click **Send to board**.

The editor and catalog work without a board. Sending and **Blank matrix** need a connection.

In the studio you can paint, erase, pick a color, use the quick palette, clear the canvas, or fill it with the current color. **Blank matrix** sends `CLEAR` and turns the LEDs off without changing the canvas.

## Serial protocol

Baud rate: **115200**.

| Command | Payload | Response |
|---------|---------|----------|
| `PX16` | 768 bytes, RGB for LEDs 0 through 255 | `OK` |
| `CLEAR` | none | `OK` |

`PX16` bytes are in LED-strip order, the same order stored in the catalog JSON. The site converts the visual canvas to that order before it writes the frame. A frame that does not finish within the firmware’s read timeout is dropped.

## Catalog

Nineteen designs live in [`web/src/catalog/`](web/src/catalog/) as 256-color frames, grouped into Characters, Emoji, Icons, Logos, and Minecraft. They were generated from the draw routines in the archived sketch. To regenerate them:

```bash
node scripts/convert-patterns.mjs
```

## Background

Built for Bartlett High School’s STEM Magnet Academy. The first version stored patterns in program memory and cycled them on the matrix. This repo is the follow-up: a catalog you can browse, a canvas you can paint, and live USB updates to the board.
