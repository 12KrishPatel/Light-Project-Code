import type { Design } from "../types";

import charmander from "./charmander.json";
import mario from "./mario.json";
import coolGuy from "./cool-guy.json";
import superman from "./superman.json";
import angryBird from "./angry-bird.json";
import amongUs from "./among-us.json";
import baby from "./baby.json";
import beemo from "./beemo.json";
import cryingEmoji from "./crying-emoji.json";
import heart from "./heart.json";
import mike from "./mike.json";
import mushroom from "./mushroom.json";
import watermelon from "./watermelon.json";
import steve from "./steve.json";
import mudkip from "./mudkip.json";
import strawberry from "./strawberry.json";
import minecraftCow from "./minecraft-cow.json";
import minecraftPig from "./minecraft-pig.json";
import batman from "./batman.json";

export const catalog: Design[] = [
  charmander as Design,
  mario as Design,
  coolGuy as Design,
  superman as Design,
  angryBird as Design,
  amongUs as Design,
  baby as Design,
  beemo as Design,
  cryingEmoji as Design,
  heart as Design,
  mike as Design,
  mushroom as Design,
  watermelon as Design,
  steve as Design,
  mudkip as Design,
  strawberry as Design,
  minecraftCow as Design,
  minecraftPig as Design,
  batman as Design,
];

export const categories = [
  "All",
  ...Array.from(new Set(catalog.map((d) => d.category))).sort(),
];
