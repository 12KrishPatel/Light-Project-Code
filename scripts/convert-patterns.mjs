/**
 * Converts charmander.ino patterns by simulating the exact draw functions:
 * same layer order, same loop counts (first N indices only), same colors.
 */
import { readFileSync, writeFileSync, mkdirSync } from "node:fs";
import { dirname, join } from "node:path";
import { fileURLToPath } from "node:url";

const __dirname = dirname(fileURLToPath(import.meta.url));
const root = join(__dirname, "..");
const inoPath = join(root, "charmander/charmander.ino");
const outDir = join(root, "web/src/catalog");

const COLOR_HEX = {
  RED: "#FF0000",
  ORANGE: "#FFA500",
  YELLOW: "#FFFF00",
  GREY: "#0F0F0F",
  WHITE: "#FFFFFF",
  BLACK: "#0F0F0F", // original macro is 0x0F0F0F, not true black
  BLUE: "#0000FF",
  BROWN: "#180C00",
  TAN: "#F4A460",
  PINK: "#EF0BA7",
  MAGENTA: "#E810E2",
  LIGHTPINK: "#EA74D6",
  DARKRED: "#800000",
  MAROON: "#FF0000",
  NAVY: "#0F0F0F",
  TEAL: "#4EE3CA",
  DARKGREEN: "#036814",
  LIGHTBLUE: "#66CDAA",
  DARKBLUE: "#000080",
  DARKTEAL: "#186A3B",
  GREEN: "#008000",
  FORESTGREEN: "#00FF00",
  LIGHTGREEN: "#228B22",
  "CRGB::White": "#FFFFFF",
  "CRGB::Black": "#000000",
  "CRGB::Blue": "#0000FF",
  "CRGB::Green": "#008000",
};

/** Meta for catalog export — draw logic comes only from the .ino */
const META = {
  charmander: { id: "charmander", name: "Charmander", category: "Characters" },
  mario: { id: "mario", name: "Mario", category: "Characters" },
  coolGuyEmoji: { id: "cool-guy", name: "Cool Guy", category: "Emoji" },
  superMan: { id: "superman", name: "Superman", category: "Characters" },
  angrybird: { id: "angry-bird", name: "Angry Bird", category: "Characters" },
  amongUsRed: { id: "among-us", name: "Among Us", category: "Characters" },
  baby: { id: "baby", name: "Baby", category: "Emoji" },
  beemo: { id: "beemo", name: "BMO", category: "Characters" },
  cryingEmoji: { id: "crying-emoji", name: "Crying Emoji", category: "Emoji" },
  heart: { id: "heart", name: "Heart", category: "Icons" },
  mike: { id: "mike", name: "Mike Wazowski", category: "Characters" },
  mushroom: { id: "mushroom", name: "Mushroom", category: "Characters" },
  watermelon: { id: "watermelon", name: "Watermelon", category: "Icons" },
  steve: { id: "steve", name: "Steve", category: "Minecraft" },
  mudkip: { id: "mudkip", name: "Mudkip", category: "Characters" },
  strawberry: { id: "strawberry", name: "Strawberry", category: "Icons" },
  minecraftCow: { id: "minecraft-cow", name: "Minecraft Cow", category: "Minecraft" },
  minecraftPig: { id: "minecraft-pig", name: "Minecraft Pig", category: "Minecraft" },
  batman: { id: "batman", name: "Batman", category: "Logos" },
};

const DRAW_ORDER = [
  "charmander",
  "mario",
  "coolGuyEmoji",
  "superMan",
  "angrybird",
  "amongUsRed",
  "baby",
  "beemo",
  "cryingEmoji",
  "heart",
  "mike",
  "mushroom",
  "watermelon",
  "steve",
  "mudkip",
  "strawberry",
  "minecraftCow",
  "minecraftPig",
  "batman",
];

function parseArrays(src) {
  const arrays = {};
  const re =
    /const\s+int\s+(\w+)\s*\[\s*\]\s*PROGMEM\s*=\s*\{([^}]*)\}/g;
  let m;
  while ((m = re.exec(src))) {
    const name = m[1];
    const body = m[2];
    const nums = body
      .split(",")
      .map((s) => s.trim())
      .filter(Boolean)
      .map((s) => Number.parseInt(s, 10));
    if (nums.some((n) => Number.isNaN(n))) {
      throw new Error(`Bad numbers in array ${name}`);
    }
    arrays[name] = nums;
  }
  return arrays;
}

function parseDrawLayers(src, fnName) {
  const fnRe = new RegExp(`void\\s+${fnName}\\s*\\(\\)\\s*\\{([\\s\\S]*?)\\n\\}`);
  const fnMatch = src.match(fnRe);
  if (!fnMatch) throw new Error(`Missing function ${fnName}`);
  const body = fnMatch[1];

  const layers = [];
  // for (... i < N ...) { leds[pgm_read_word|byte(&ARRAY[i])] = COLOR; }
  const layerRe =
    /for\s*\(\s*(?:int\s+)?i\s*=\s*0\s*;\s*i\s*<\s*(\d+)\s*;\s*i\+\+\s*\)\s*\{\s*leds\s*\[\s*pgm_read_(?:word|byte)\s*\(\s*&\s*(\w+)\s*\[\s*i\s*\]\s*\)\s*\]\s*=\s*([A-Za-z0-9_:]+)\s*;\s*\}/g;

  let m;
  while ((m = layerRe.exec(body))) {
    layers.push({
      count: Number.parseInt(m[1], 10),
      array: m[2],
      colorToken: m[3],
    });
  }

  if (layers.length === 0) {
    throw new Error(`No layers parsed for ${fnName}`);
  }
  return layers;
}

function simulate(arrays, layers) {
  const pixels = Array(256).fill("#000000");
  const report = [];

  for (const layer of layers) {
    const arr = arrays[layer.array];
    if (!arr) throw new Error(`Unknown array ${layer.array}`);
    const hex = COLOR_HEX[layer.colorToken];
    if (!hex) throw new Error(`Unknown color ${layer.colorToken}`);

    const used = Math.min(layer.count, arr.length);
    const extrasInArray = Math.max(0, arr.length - layer.count);
    const shortfall = Math.max(0, layer.count - arr.length);

    for (let i = 0; i < used; i++) {
      const idx = arr[i];
      if (idx < 0 || idx > 255) {
        throw new Error(`Index out of range in ${layer.array}: ${idx}`);
      }
      pixels[idx] = hex;
    }

    report.push({
      array: layer.array,
      color: layer.colorToken,
      hex,
      loopCount: layer.count,
      arrayLen: arr.length,
      painted: used,
      extrasInArray,
      shortfall,
    });
  }

  return { pixels, report };
}

function camel(id) {
  return id.replace(/-([a-z])/g, (_, c) => c.toUpperCase());
}

const src = readFileSync(inoPath, "utf8");
const arrays = parseArrays(src);
mkdirSync(outDir, { recursive: true });

const patterns = [];
const verification = [];

for (const fn of DRAW_ORDER) {
  const meta = META[fn];
  if (!meta) throw new Error(`No meta for ${fn}`);
  const layers = parseDrawLayers(src, fn);
  const { pixels, report } = simulate(arrays, layers);

  const design = {
    id: meta.id,
    name: meta.name,
    category: meta.category,
    pixels,
  };
  patterns.push(design);
  writeFileSync(join(outDir, `${meta.id}.json`), JSON.stringify(design, null, 2) + "\n");

  const mismatches = report.filter((r) => r.extrasInArray || r.shortfall);
  verification.push({ id: meta.id, fn, layers: report, mismatches });

  console.log(`\n=== ${meta.id} (${fn}) ===`);
  for (const r of report) {
    const flag =
      r.extrasInArray || r.shortfall
        ? `  !! arrayLen=${r.arrayLen} loop=${r.loopCount} (extras=${r.extrasInArray}, shortfall=${r.shortfall})`
        : "  OK";
    console.log(
      `  ${r.array}: paint ${r.painted} as ${r.color} (${r.hex})${flag}`
    );
  }
}

// Second pass: re-simulate and compare written JSON byte-for-byte to simulation
let allMatch = true;
for (const fn of DRAW_ORDER) {
  const meta = META[fn];
  const layers = parseDrawLayers(src, fn);
  const { pixels } = simulate(arrays, layers);
  const written = JSON.parse(readFileSync(join(outDir, `${meta.id}.json`), "utf8"));
  const same =
    written.pixels.length === 256 &&
    written.pixels.every((c, i) => c === pixels[i]);
  if (!same) {
    allMatch = false;
    console.error(`VERIFY FAIL: ${meta.id} JSON != simulation`);
  } else {
    console.log(`VERIFY OK: ${meta.id}`);
  }
}

writeFileSync(
  join(outDir, "index.ts"),
  `import type { Design } from "../types";

${patterns.map((p) => `import ${camel(p.id)} from "./${p.id}.json";`).join("\n")}

export const catalog: Design[] = [
${patterns.map((p) => `  ${camel(p.id)} as Design,`).join("\n")}
];

export const categories = [
  "All",
  ...Array.from(new Set(catalog.map((d) => d.category))).sort(),
];
`
);

writeFileSync(
  join(outDir, "verification-report.json"),
  JSON.stringify({ allMatch, verification }, null, 2) + "\n"
);

console.log(`\nConverted ${patterns.length} designs. JSON==simulation: ${allMatch}`);
if (!allMatch) process.exit(1);
