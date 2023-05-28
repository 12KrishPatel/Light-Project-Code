#include <FastLED.h>

#define NUM_LEDS            256
#define DATA_PIN            4
#define BRIGHTNESS          64
#define LED_TYPE            WS2812B
#define UPDATES_PER_SECOND  100
#define RED                 0xFF0000
#define ORANGE              0xFFA500
#define YELLOW              0xFFFF00
#define GREY                0x0F0F0F
#define WHITE               0xFFFFFF
#define BLACK               0x0F0F0F
#define BLUE                0x0000FF
#define BROWN               0x180C00
#define TAN                 0xF4A460
#define PINK                0xEF0BA7
#define MAGENTA             0xE810E2
#define LIGHTPINK           0xEA74D6
#define DARKRED             0x800000
#define MAROON              0xFF0000
#define NAVY                0x0F0F0F
#define TEAL                0x4EE3CA
#define DARKGREEN           0x036814
#define LIGHTBLUE           0x66CDAA
#define DARKBLUE            0x000080
#define DARKTEAL            0x186A3B
#define GREEN               0x008000
#define FORESTGREEN         0x00FF00
#define LIGHTGREEN          0x228B22
CRGB leds[NUM_LEDS];

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}
void loop() {
  FastLED.clear();
  charmander();
  delay(2000);
  FastLED.clear();
  mario();
  delay(2000);
  FastLED.clear();
  coolGuyEmoji();
  delay(2000);
  FastLED.clear();
  superMan();
  delay(2000);
  FastLED.clear();
  angrybird();
  delay(2000);
  FastLED.clear();
  amongUsRed();
  delay(2000);
  FastLED.clear();
  baby();
  delay(2000);
  FastLED.clear();
  beemo();
  delay(2000);
  FastLED.clear();
  cryingEmoji();
  delay(2000);
  FastLED.clear();
  heart();
  delay(2000);
  FastLED.clear();
  mike();
  delay(2000);
  FastLED.clear();
  mushroom();
  delay(2000);
  FastLED.clear();
  watermelon();
  delay(2000);
  FastLED.clear();
  steve();
  delay(2000);
  FastLED.clear();
  mudkip();
  delay(2000);
  FastLED.clear();
  strawberry();
  delay(2000);
  FastLED.clear();
  minecraftCow();
  delay(2000);
  FastLED.clear();
  minecraftPig();
  delay(2000);
  FastLED.clear();
  batman();
  delay(2000);
  FastLED.clear();
}
//Charmander
const int charRedLights[] PROGMEM = {
  34, 61, 62, 65, 66, 67, 92, 94
};
const int charOrangeLights[] PROGMEM = {
  42, 43, 44, 50, 51, 52, 53, 54, 73, 74, 75, 76, 77, 81, 82, 83, 86, 87, 93, 97, 
  104, 105, 108, 109, 110, 114, 115, 116, 117, 118, 119, 120, 125, 130, 131, 134, 
  135, 137, 138, 149, 151, 152, 153, 155, 156, 164, 166, 167, 183, 185, 199, 216
};
const int charYellowLights[] PROGMEM = {
  98, 148, 169, 170, 171, 182
};
const int charGreyLights[] PROGMEM = {
  19, 20, 21, 29, 33, 35, 41, 45, 49, 55, 60, 63, 64, 68, 72, 78, 80, 85, 88, 91, 
  95, 96, 99, 103, 106, 107, 111, 113, 121, 124, 126, 129, 132, 133, 136, 139, 140, 
  141, 147, 150, 154, 157, 163, 165, 168, 172, 178, 180, 181, 186, 187, 197, 198, 200,
   201, 202, 214, 218, 230, 231, 232
};
const int charWhiteLights[] PROGMEM = {
  84, 215, 217, 
};
//Mario LEDS
const int marBlackLeds[] PROGMEM = {
  37, 58, 68, 90, 91, 92, 93
};
const int marYellowLeds[] PROGMEM = {
  166, 169
};
const int marRedLeds[] PROGMEM = {
  5, 6, 7, 8, 9, 10, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 116, 117, 119, 120, 121, 
  122, 131, 132, 133, 135, 136, 138, 139, 140, 146, 147, 148, 149, 154, 155, 156, 157, 164
};
const int marBlueLeds[] PROGMEM = {
  118, 134, 137, 150, 151, 152, 153, 165, 167, 168, 170, 181, 182, 183, 184, 185, 186, 
  196, 197, 198, 199, 200, 201, 202, 203, 212, 213, 214, 217, 218, 219
};
const int marTanLeds[] PROGMEM = {
  36, 38, 39, 40, 52, 54, 55, 56, 57, 59, 60, 61, 65, 66, 67, 69, 70, 71, 72, 75, 85,
   86, 87, 88, 89, 99, 100, 101, 102, 103, 104, 105, 106, 162, 163, 172, 173, 178, 179, 
   180, 187, 188, 189, 194, 195, 204, 205
};
const int marBrownLeds[] PROGMEM = {
  41, 42, 43, 51, 53, 73, 74, 76, 83, 84, 227, 228, 229, 234, 235, 236, 242, 243, 244, 
  245, 250, 251, 252, 253
};
//Derpy Superman LEDS
const int superBlack[] PROGMEM = {
  5, 6, 7, 24
};
const int superTan [] PROGMEM = {
  25, 26, 37, 38, 39, 56, 150, 155
};
const int superBlue[] PROGMEM = {
  69, 70, 71, 72, 73, 85, 86, 87, 90, 91, 100, 103, 104, 106, 117, 119, 120, 121, 123, 
  132, 134, 135, 136, 138, 166, 168, 183, 185, 198, 200, 215, 217, 230, 232, 247, 249
};
const int superYellow[] PROGMEM = {
  88, 89, 102  
};
const int superRed[] PROGMEM = {
  105, 118, 137, 139, 148, 149, 151, 152, 153, 167, 170, 171, 181  
};
//Angry Bird LEDS
const int mainRedLights[] PROGMEM = {
  23, 24, 38, 39, 41, 42, 54, 55, 58, 68, 73, 74, 84, 85, 
  98, 99, 105, 106, 107, 115, 116, 117, 125, 130, 138, 140, 
  147, 149, 150, 157, 163, 164, 167, 168, 169, 170, 171, 183, 
  184, 185, 186, 187
};
const int darkRedLights[] PROGMEM = { 
  40, 56, 57, 69, 70, 71, 72, 88, 89, 90, 102, 118, 121, 124, 
  131, 137, 139, 148, 151
};
const int orangeLights[] PROGMEM = {
  133, 134, 152, 153, 154, 155, 156, 165, 166
};
const int whiteLights[] PROGMEM = {
  119, 123, 132, 135, 136
};
const int blackLights[] PROGMEM = {
  86, 87, 91, 92, 100, 101, 103, 104, 113, 120, 122, 141, 142, 146, 174
};
const int greyLights[] PROGMEM = {
  179, 180, 188, 194, 195, 196, 202, 203, 204, 205, 206, 212, 213, 214, 215, 
  216, 217, 218, 219, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233
};
const int tanLights[] PROGMEM = {
  181, 182, 197, 198, 199, 200, 201
};
//Cool guy LEDS
const int coolYellowLeds[] PROGMEM = {
  21, 22, 23, 24, 25, 36, 37, 38, 39, 40, 41, 42, 43, 44, 50, 51, 52, 53, 54, 
  55, 56, 57, 58, 59, 60, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 98, 110, 
  113, 119, 125, 130, 131, 135, 136, 137, 141, 142, 145, 146, 147, 148, 149, 150,
  151, 152, 153, 154, 155, 156, 157, 163, 164, 166, 167, 168, 169, 170, 171, 172,
  173, 178, 179, 180, 181, 186, 187, 188, 196, 197, 198, 199, 200, 201, 202, 203,
  204, 213, 214, 215, 216, 217
};
const int coolWhiteLeds[] PROGMEM = {
  101, 102, 107, 108, 115, 121
};
const int coolGreyLeds[] PROGMEM = {
  6, 7, 8, 9, 10, 19, 20, 26, 27, 35, 45, 49, 61, 66, 78, 80, 81, 82, 83, 84, 85, 
  86, 87, 88, 89, 90, 91, 92, 93, 94, 97, 99, 100, 103, 104, 105, 106, 109, 111,
   112, 114, 116, 117, 118, 120, 122, 123, 124, 126, 129, 132, 133, 134, 138, 139, 
   140, 143, 144, 158, 162, 165, 174, 177, 182, 183, 184, 185, 189, 195, 205, 211, 
   212, 218, 219, 230, 231, 232, 233, 234
};
//Among us LEDS
const int amongRed[] PROGMEM = {
  38, 39, 40, 41, 42, 52, 53, 54, 55, 56, 57, 58, 69, 70, 71, 72, 88, 89, 90, 92,
   93, 98, 99, 101, 102, 103, 119, 120, 121, 122, 124, 125, 130, 131, 133, 134, 135,
    136, 137, 138, 139, 148, 149, 150, 151, 152, 153, 154, 156, 157, 165, 166, 167,
     169, 170, 171, 180, 181, 185, 186, 197, 198, 202, 203
};
const int amongBlack[] PROGMEM = {
  21, 22, 23, 24, 25, 37, 43, 51, 59, 66, 67, 68, 73, 74, 75, 76, 82, 87, 91, 94, 97, 
  100, 104, 109, 115, 116, 117, 118, 123, 126, 129, 132, 140, 147, 155, 158, 162, 163,
   164, 168, 172, 179, 182, 184, 187, 196, 199, 201, 204, 212, 213, 217, 218
};
const int amongBlue[] PROGMEM = {
  86, 105, 106, 107, 108
};
const int amongTeal[] PROGMEM = {
  83, 85
};
const int amongWhite[] PROGMEM = {
  84
};
//Baby
const int babyTanLeds[] PROGMEM = {
  37, 38, 39, 40, 41, 42, 52, 53, 54, 55, 56, 57, 58, 59, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 83, 86, 87, 88, 89, 92, 99, 102, 103, 104, 105, 108, 115, 124, 133, 137, 138, 149, 150, 151, 152, 153, 154, 164, 171, 182, 183, 184, 185, 198, 199, 200, 201, 214, 217
};
const int babyBlackLeds[] PROGMEM = {
  21, 22, 23, 24, 25, 26, 36, 43, 51, 60, 66, 77, 82, 85, 91, 93, 98, 100, 101, 106, 107, 109, 114, 118, 119, 120, 121, 125, 131, 134, 135, 136, 137, 140, 148, 155, 163, 165, 166, 167, 168, 169, 170, 172, 179, 180, 181, 186, 187, 188, 197, 202, 213, 215, 216, 218, 229, 230, 233, 234
};
const int babyWhiteLeds[] PROGMEM = {
  84, 90
};
const int babyBlueLeds[] PROGMEM = {
  116, 117, 122, 123, 132, 139
};
//Beemo
const int beemoDarkTealLeds[] PROGMEM = {
  17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 33, 46, 49, 62, 65, 78, 81, 94, 97, 110, 113, 126, 129, 142, 145, 158, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 177, 184, 185, 186, 187, 189, 190, 193, 194, 195, 196, 197, 199, 200, 201, 202, 203, 204, 205, 206, 209, 210, 212, 213, 214, 215, 219, 220, 222, 225, 226, 229, 230, 231, 232, 233, 234, 238
};

const int beemoGreyLeds[] PROGMEM = {
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 31, 32, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 48, 50, 61, 63, 64, 66, 69, 74, 77, 79, 80, 82, 93, 95, 96, 98, 102, 103, 104, 105, 109, 111, 112, 114, 125, 127, 128, 130, 141, 143, 144, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 159, 160, 175, 176, 178, 179, 180, 181, 182, 183, 191, 192, 207, 208, 223, 224, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255
};
const int beemoDarkBlueLeds[] PROGMEM = {
  188
};
const int beemoWhiteLeds[] PROGMEM = {
  198, 216, 217, 218
};
const int beemoYellowLeds[] PROGMEM = {
  211, 235, 236, 237
};
const int beemoGreenLeds[] PROGMEM = {
  221
};
const int beemoRedLeds[] PROGMEM = {
  227, 228
};
const int beemoLightBlueLeds[] PROGMEM = {
  51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 67, 68, 70, 71, 72, 73, 75, 76, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 99, 100, 101, 106, 107, 108, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140
};
//Crying
const int cryYellowLeds[] PROGMEM = {
  22, 23, 24, 25, 26,35,36,37,38,39,40,40,41,42,43,51,52,53,54,55,56,57,58,59,60,61,65,66,68,69,70,71,72,73,74,76,77,82,84,85,86,87,88,89,90,91,92,94,96,97,98,99,102,103,104,107,108,109,110,113,114,115,118,120,122,125,126,127,128,129,130,133,134,135,136,137,140,141,142,145,146,147,150,151,152,153,154,157,158,159,160,162,161,162,165,166,167,168,169,172,173,174,178,179,182,186,189,190,193,194,197,201,204,205,211,214,218,221,229,230,231,232,233,246,247,248,249,250};
const int cryGreyLeds[] PROGMEM = {
67,75,83,93,100,101,105,106,116,119,121,124,198,199,200,215,216,217
};
const int cryWhiteLeds[] PROGMEM = {
  166, 167, 168, 183, 184, 185};
const int cryBlueLeds[] PROGMEM = {
  117, 123, 131, 132, 138, 139, 148, 149, 155, 156, 163, 164, 170, 171, 180, 181, 187, 188, 195, 196, 202, 203, 212, 213, 219, 220, 227, 228, 234, 235
};
//Heart
const int border[] PROGMEM = {
  34, 35, 36, 37, 42, 43, 44, 45, 49, 50, 54, 57, 61, 62, 65, 71, 72, 78, 
  81, 94, 97, 110, 113, 126, 129, 130, 141, 142, 146, 147, 156, 
  157, 163, 164, 171, 172, 180, 181, 186, 187, 197, 198,201, 202, 
  214, 215, 216, 217
};
const int body[] PROGMEM = {
  51, 52, 53, 58, 59, 60, 66, 67, 68, 69, 70, 73, 74, 75, 76, 77, 
  82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 98, 99, 100, 101, 
  102, 103, 104, 105, 106, 107, 108, 109, 114, 115, 116, 117, 118, 
  119, 120, 121, 122, 123, 124, 125, 131, 132, 133, 134, 135, 136, 137, 
  138, 139, 140, 148, 149, 150, 151, 152, 153, 154, 155, 165, 166, 
  167, 168, 169, 170, 182, 183, 184, 185, 199, 200
};
//Mike
const int mikeGreenParts[] PROGMEM = {
  22, 23, 24, 25, 26, 36, 37, 41, 42, 52, 53, 59, 60, 67,
  68, 74, 75, 83, 84, 85, 91, 92, 93, 96, 98, 99, 100,
  101, 105, 106, 107, 108, 110, 113, 115, 116, 118, 119,
  120, 121, 122, 124, 125, 127, 128, 130, 131, 132, 138,
  139, 140, 142, 145, 148, 149, 150, 151, 152, 153, 154,
  155, 156, 159, 160, 164, 165, 166, 167, 168, 169, 170,
  174, 178, 190, 198, 200, 215, 217, 229, 230, 232, 233
};
const int mikeBlackParts[] PROGMEM = {
  5, 6, 7, 8, 9, 21, 27, 35, 43, 51, 61, 66,
  76, 82, 94, 97, 109, 114, 117, 123, 126, 129, 133,
  134, 135, 136, 137, 141, 147, 157, 163, 171, 181, 182,
  183, 184, 185, 186, 187
};
const int mikeBlueParts[] PROGMEM = {
  55, 56, 57, 70, 72, 87, 88, 89
};
const int mikeEyeOutside[] PROGMEM = {
  38, 39, 40, 54, 58, 69, 73, 86,
  90, 102, 103, 104
};
const int mikeEyeColor[] PROGMEM = {
  71
};
//Mushroom
const int toadRedLeds[] PROGMEM = {
  23, 24, 38, 39, 40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 82, 83, 84, 85, 90, 91, 92, 93, 99, 100, 107, 108, 115, 116, 123, 124, 130, 131, 132, 133, 138, 139, 140, 141, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 161, 162, 163, 172, 173, 174
};
const int roadBlackLeds[] PROGMEM = {
  5, 6, 7, 8, 9, 10, 19, 20, 27, 28, 34, 45, 49, 62, 65, 78, 80, 95, 96, 111, 112, 127, 128, 143, 144, 159, 160, 164, 165, 166, 167, 168, 169, 170, 171, 175, 177, 178, 179, 182, 185, 188, 189, 190, 194, 198, 201, 205, 210, 221, 227, 236, 244, 245, 246, 247, 248, 249, 250, 251
};
const int toadTanLeds[] PROGMEM = {
  180, 181, 183, 184, 186, 187, 195, 196, 197, 199, 200, 202, 203, 204, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 228, 229, 230, 231, 232, 233, 234, 235
};
const int toadWhiteLeds[] PROGMEM = {
  21, 22, 25, 26, 35, 36, 37, 42, 43, 44, 81, 86, 87, 88, 89, 94, 97, 98, 101, 102, 103, 104, 105, 106, 109, 110, 113, 114, 117, 118, 119, 120, 121, 122, 125, 126, 129, 134, 135, 136, 137, 142
};
//Watermelon
const int waterForestGreenLeds[] PROGMEM = {
  35, 61, 65, 94, 97, 126, 129, 158, 162, 188, 189, 195, 196, 205, 211, 218, 219, 230, 231, 232, 233, 234
};
const int waterLightGreenLeds[] PROGMEM = {
  36, 60, 66, 93, 98, 125, 130, 157, 163, 178, 187, 197, 204, 212, 213, 214, 215, 216, 217
};
const int waterRedLeds[] PROGMEM = {
  58, 69, 70, 88, 89, 91, 100, 101, 102, 103, 104, 118, 119, 120, 122, 123, 132, 133, 134, 135, 136, 137, 138, 148, 149, 150, 152, 153, 154, 165, 166, 167, 168, 169, 171, 172, 181, 182, 183, 184
};
const int waterPinkLeds[] PROGMEM = {
  59, 67, 68, 92, 99, 124, 131, 155, 156, 164, 179, 180, 185, 186, 198, 199, 200, 201, 202, 203
};
const int waterGreyLeds[] PROGMEM = {
  90, 121, 151, 170
};
//Steve
const int steveBrown[] PROGMEM = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 78, 79, 80, 81, 94, 95, 196, 197, 202, 203, 212, 213, 218, 219, 228, 229, 230, 231, 232, 233, 234, 235, 244, 245, 246, 247, 248, 249, 250, 251
};
const int steveTan[] PROGMEM = {
  66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 142, 143, 144, 145, 150, 151, 152, 153, 158, 159, 160, 161, 162, 163, 164, 165, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 198, 199, 200, 201, 204,
  205, 206, 207, 208, 209, 210, 211, 214, 215, 216, 217, 220, 221, 222, 223, 224, 225, 226, 227, 236, 237, 238, 239, 240, 241, 242, 243, 252, 253, 254, 255
};
const int steveBlue[] PROGMEM = {
  132, 133, 138, 139, 148, 149, 154, 155
};
const int steveWhite[] PROGMEM = {
  130, 131, 140, 141, 146, 147, 156, 157
};
const int steveLightBrown[] PROGMEM = {
  166, 167, 168, 169, 182, 183, 184, 185
};
//Mudkip
const int mudBlack[] PROGMEM = {
  7, 23, 25, 38, 40, 54, 55, 57, 58, 67, 68, 70, 72, 74, 75, 83, 88, 93, 103, 133, 137, 150, 154, 180, 181, 182, 183, 184, 185, 186, 187, 188, 195, 196, 202, 203, 212, 220, 227, 230, 231, 232, 235, 245, 246, 250, 251
};
const int mudLightBlue[] PROGMEM = {
  24, 39, 69, 73, 85, 86, 87, 89, 90, 91, 99, 100, 101, 102, 104, 105, 106, 107, 116, 117, 119, 120, 121, 123, 124, 131, 132, 134, 135, 136, 138, 139, 149, 151, 152, 153, 155, 164, 165, 166, 167, 168, 169, 170, 228, 229, 233, 234
};
const int mudBlue[] PROGMEM = {
  56, 71, 84, 92, 163, 171, 197, 198, 199, 200, 201, 213, 214, 215, 216, 217, 218, 219
};
const int mudRed[] PROGMEM = {
  114, 115, 125, 126, 130, 140, 146, 147, 148, 156, 157, 158
};
const int mudGrey[] PROGMEM = {
  97, 98, 108, 109, 113, 127, 129, 141, 145, 159, 161, 162, 172, 173
};
const int mudWhite[] PROGMEM = {
  118, 122
};
//Strawberry
const int strawGreen[] PROGMEM = {
  39, 56, 57, 58
};
const int strawYellowGreen[] PROGMEM = {
  54, 55, 71
};
const int strawBlack[] PROGMEM = {
  24, 37, 38, 40, 41, 52, 53, 59, 60, 66, 69, 70, 72, 73, 76, 82, 88, 94, 97, 109, 114, 118, 123, 126, 129, 132, 133, 135, 137, 138, 141, 147, 157, 162, 172, 180, 188, 196, 202, 214, 218, 230, 231, 232
};
const int strawRed[] PROGMEM =  {
  85, 91, 98, 102, 108, 119, 131, 150, 153, 164, 171, 184, 197, 201, 216
};
const int strawPink[] PROGMEM = {
  67, 68, 74, 75, 83, 84, 86, 87, 89, 90, 92, 93, 99, 100, 101, 103, 104, 105, 106, 107, 115, 116, 120, 121, 124, 125, 130, 134, 136, 139, 140, 148, 149, 151, 152, 154, 155, 156, 163, 165, 166, 167, 168, 169, 170, 181, 182, 183, 185, 186, 187, 198, 199, 200, 215, 217
};
//Batman
const int batBlue[] PROGMEM = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 43, 44, 45, 46, 47, 48, 49, 50, 51, 61, 62, 63, 64, 65, 77, 78, 79, 80, 81, 82, 94, 95, 96, 97, 109, 110, 111, 112, 113, 114,
   126, 127, 128, 129, 143, 144, 145, 158, 159, 160, 161, 174, 175, 176, 177, 178, 189, 190, 191, 192, 193, 194, 195, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228,
  229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255
};
const int batYellow[] PROGMEM = {
  36, 37, 38, 39, 40, 41, 42, 52, 53, 54, 55, 56, 57, 58, 59, 60, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 115, 116, 118, 120, 121, 125, 130, 131, 134, 135, 139, 140, 155, 156, 157, 162, 163, 164, 165, 186, 187, 188, 196, 197, 198, 199
};
const int batBlack[] PROGMEM = {
  112, 113, 114, 117, 119, 122, 123, 124, 132, 133, 136, 137, 138, 141, 142, 146, 147, 148, 149, 150, 151, 152, 153, 154, 166, 167, 168, 169, 170, 171, 172, 173, 179, 180, 181, 182, 183, 184, 185, 200, 201, 202, 214
};
//Minecraft Cow
const int cowBrown[] PROGMEM = {
  0, 1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 30, 31, 32, 33, 34, 35, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 60, 61, 62, 63, 68, 69, 74, 75, 84, 85, 90, 91, 100, 101, 102, 103, 106, 107, 116, 117, 120, 121, 122, 123, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 
  159, 160, 161, 162, 163, 172, 173, 174, 175, 176, 177, 178, 179, 188, 189, 190, 191, 192, 193, 206, 207, 208, 209, 222, 223, 224, 225, 238, 239, 240, 241, 254, 255
};
const int cowGrey[] PROGMEM = {
  2, 3, 4, 5, 6, 7, 8, 9, 22, 23, 24, 25, 26, 27, 28, 29, 36, 37, 38, 39, 40, 41, 54, 55, 56, 57, 58, 59, 70, 71, 72, 73, 86, 87, 88, 89, 104, 105, 118, 119, 198, 199, 200, 201, 214, 215, 216, 217, 228, 229, 230, 231, 232, 233, 234, 235, 244, 245, 246, 247, 248, 249, 250, 251
};
const int cowWhite[] PROGMEM = {
  64, 65, 66, 67, 76, 77, 78, 79, 80, 81, 82, 83, 92, 93, 94, 95, 98, 99, 108, 109, 114, 115, 124, 125, 164, 165, 166, 167, 168, 169, 170, 171, 180, 181, 182, 183, 184, 185, 186, 187, 194, 195, 204, 205, 210, 211, 220, 221, 226, 227, 236, 237, 242, 243, 252, 253
};
const int cowBlack[] PROGMEM = {
  96, 97, 110, 111, 112, 113, 126, 127, 196, 197, 202, 203, 212, 213, 218, 219
};
//Minecraft Pig
const int pigPink[] PROGMEM = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 100, 101, 102, 103, 104, 105, 106, 107, 116, 117, 118, 119, 120, 121, 122, 123, 128, 129, 130, 131,
  140, 141, 142, 143, 144, 145, 146, 147, 156, 157, 158, 159, 160, 161, 162, 163, 166, 167, 168, 169, 172, 173, 174, 175, 176, 177, 178, 179, 182, 183, 184, 185, 188, 189, 190, 191, 192, 193, 194, 195, 204, 205, 206, 207, 208, 209, 210, 211,
  220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255
};
const int pigMagenta[] PROGMEM = {
  164, 165, 170, 171, 180, 181, 186, 187
};
const int pigLightPink[] PROGMEM = {
  132, 133, 134, 135, 136, 137, 138, 139, 148, 149, 150, 151, 152, 153, 154, 155, 196, 197, 198, 199, 200, 201, 202, 203, 212, 213, 214, 215, 216, 217, 218, 219
};
const int pigBlack[] PROGMEM = {
  96, 97, 110, 111, 112, 113, 126, 127
};
const int pigWhite[] PROGMEM = {
  98, 99, 108, 109, 114, 115, 124, 125
};
void charmander() {
  for (int i = 0; i < 8; i++) {
  leds[pgm_read_word(&charRedLights[i])] = RED;
  }
  for (int i = 0; i < 52; i++) {
    leds[pgm_read_word(&charOrangeLights[i])] = ORANGE;
  }
  for (int i = 0; i < 3; i++) {
    leds[pgm_read_word(&charWhiteLights[i])] = WHITE;
  }
  for (int i = 0; i < 61; i++) {
    leds[pgm_read_word(&charGreyLights[i])] = GREY;
  }
  for (int i = 0; i < 6; i++) {
    leds[pgm_read_word(&charYellowLights[i])] = YELLOW;
  }
  FastLED.show();
}
void mario() {
  for (int i = 0; i < 7; i++) {
  leds[pgm_read_word(&marBlackLeds[i])] = BLACK;
  }
  for (int i = 0; i < 2; i++) {
    leds[pgm_read_word(&marYellowLeds[i])] = BLACK;
  }
  for (int i = 0; i < 39; i++) {
    leds[pgm_read_word(&marRedLeds[i])] = RED;
  }
  for (int i = 0; i < 31; i++) {
    leds[pgm_read_word(&marBlueLeds[i])] = BLUE;
  }
  for (int i = 0; i < 47; i++) {
    leds[pgm_read_word(&marTanLeds[i])] = TAN;
  }
  for (int i = 0; i < 24; i++) {
    leds[pgm_read_word(&marBrownLeds[i])] = BROWN;
  }
    FastLED.show();
}
void superMan() {
  for (int i = 0; i < 4; i++) {
  leds[pgm_read_word(&superBlack[i])] = BLACK;
  }
  for (int i = 0; i < 2; i++) {
    leds[pgm_read_word(&superYellow[i])] = YELLOW;
  }
  for (int i = 0; i < 13; i++) {
    leds[pgm_read_word(&superRed[i])] = RED;
  }
  for (int i = 0; i < 36; i++) {
    leds[pgm_read_word(&superBlue[i])] = BLUE;
  }
  for (int i = 0; i < 8; i++) {
    leds[pgm_read_word(&superTan[i])] = TAN;
  }
  FastLED.show();
}
void angrybird(){
  for (int i = 0; i < 42; i++) {
  leds[pgm_read_word(&mainRedLights[i])] = DARKRED;
  }
  for (int i = 0; i < 19; i++) {
    leds[pgm_read_word(&darkRedLights[i])] = MAROON;
  }
  for (int i = 0; i < 9; i++) {
    leds[pgm_read_word(&orangeLights[i])] = ORANGE;
  }
  for (int i = 0; i < 5; i++) {
    leds[pgm_read_word(&whiteLights[i])] = WHITE;
  }
  for (int i = 0; i < 29; i++) {
    leds[pgm_read_word(&greyLights[i])] = GREY;
  }
  for (int i = 0; i < 7; i++) {
    leds[pgm_read_word(&tanLights[i])] = TAN;
  }
  for (int i = 0; i < 15; i++) {
    leds[pgm_read_word(&blackLights[i])] = NAVY;
  }
  FastLED.show();
}
void coolGuyEmoji() {
  for (int i = 0; i < 92; i++) {
  leds[pgm_read_word(&coolYellowLeds[i])] = YELLOW;
  }
  for (int i = 0; i < 6; i++) {
    leds[pgm_read_word(&coolWhiteLeds[i])] = WHITE;
  }
  for (int i = 0; i < 79; i++) {
    leds[pgm_read_word(&coolGreyLeds[i])] = GREY;
  }
    FastLED.show(); 
}
void amongUsRed(){
  for (int i = 0; i < 64; i++) {
  leds[pgm_read_word(&amongRed[i])] = MAGENTA;
  }
  for (int i = 0; i < 53; i++) {
    leds[pgm_read_word(&amongBlack[i])] = BLACK;
  }
  for (int i = 0; i < 5; i++) {
    leds[pgm_read_word(&amongBlue[i])] = BLUE;
  }
  for (int i = 0; i < 2; i++) {
    leds[pgm_read_word(&amongTeal[i])] = TEAL;
  }
  for (int i = 0; i < 1; i++) {
    leds[pgm_read_word(&amongWhite[i])] = WHITE;
  }
    FastLED.show();
}
void baby(){
  for(int i = 0; i < 59; i++){
  leds[pgm_read_word(&babyTanLeds[i])] = TAN;
  }
  for(int i = 0; i < 60; i++){
    leds[pgm_read_word(&babyBlackLeds[i])] = GREY;
  }
  for(int i = 0; i < 2; i++){
    leds[pgm_read_word(&babyWhiteLeds[i])] = WHITE;
  }
  for(int i = 0; i < 6; i++){
    leds[pgm_read_word(&babyBlueLeds[i])] = BLUE;
  }
    FastLED.show();
}
void beemo() {
  for (int i = 0; i < 82; i++) {
    leds[pgm_read_word(&beemoDarkTealLeds[i])] = DARKTEAL;
  }
  for (int i = 0; i < 106; i++) {
    leds[pgm_read_word(&beemoGreyLeds[i])] = GREY;
  }
  for (int i = 0; i < 1; i++) {
    leds[pgm_read_word(&beemoDarkBlueLeds[i])] = DARKBLUE;
  }
  for (int i = 0; i < 4; i++) {
    leds[pgm_read_word(&beemoWhiteLeds[i])] = WHITE;
  }
  for (int i = 0; i < 4; i++) {
    leds[pgm_read_word(&beemoYellowLeds[i])] = YELLOW;
  }
  for (int i = 0; i < 1; i++) {
    leds[pgm_read_word(&beemoGreenLeds[i])] = GREEN;
  }
  for (int i = 0; i < 2; i++) {
    leds[pgm_read_word(&beemoRedLeds[i])] = RED;
  }
  for (int i = 0; i < 54; i++) {
    leds[pgm_read_word(&beemoLightBlueLeds[i])] = LIGHTBLUE;
  }
    FastLED.show();
}
void cryingEmoji() {
  for(int i = 0; i < 128; i++){
    leds[pgm_read_word(&cryYellowLeds[i])] = YELLOW;
  }
  for(int i = 0; i < 18; i++){
    leds[pgm_read_word(&cryGreyLeds[i])] = GREY;
  }
  for(int i = 0; i < 6; i++){
    leds[pgm_read_word(&cryWhiteLeds[i])] = WHITE;
  }
  for(int i = 0; i < 30; i++){
    leds[pgm_read_word(&cryBlueLeds[i])] = BLUE;
  }
  FastLED.show();
}
void heart(){
  for (int i = 0; i < 48; i++){
    leds[pgm_read_word(&border[i])] = WHITE;
  }
  for (int i = 0; i < 82; i++){
    leds[pgm_read_word(&body[i])] = RED;
  }
  FastLED.show();
}
void mike() {
  for (int i = 0; i < 39; i++) {
    leds[pgm_read_byte(&mikeBlackParts[i])] = GREY;
  }
  for (int i = 0; i < 12; i++) {
    leds[pgm_read_byte(&mikeEyeOutside[i])] = CRGB::White;
  }
  for (int i = 0; i < 1; i++) {
    leds[pgm_read_byte(&mikeEyeColor[i])] = CRGB::Black;
  }
  for (int i = 0; i < 8; i++) {
    leds[pgm_read_byte(&mikeBlueParts[i])] = CRGB::Blue;
  }
  for (int i = 0; i < 82; i++) {
    leds[pgm_read_byte(&mikeGreenParts[i])] = CRGB::Green;
  }
  FastLED.show();
}
void mushroom(){
  for (int i = 0; i < 74; i++) {
    leds[pgm_read_word(&toadRedLeds[i])] = RED;
  }
  for (int i = 0; i < 42; i++) {
    leds[pgm_read_word(&toadWhiteLeds[i])] = WHITE;
  }
  for (int i = 0; i < 60; i++) {
    leds[pgm_read_word(&roadBlackLeds[i])] = BLACK;
  }
  for (int i = 0; i < 32; i++) {
    leds[pgm_read_word(&toadTanLeds[i])] = TAN;
  }
  FastLED.show();
}
void watermelon() {
  for(int i = 0; i < 22; i++){
    leds[pgm_read_word(&waterForestGreenLeds[i])] = FORESTGREEN;
  }
  for(int i = 0; i < 19; i++){
    leds[pgm_read_word(&waterLightGreenLeds[i])] = LIGHTGREEN;
  }
  for(int i = 0; i < 40; i++){
    leds[pgm_read_word(&waterRedLeds[i])] = RED;
  }
  for(int i = 0; i < 20; i++){
    leds[pgm_read_word(&waterPinkLeds[i])] = PINK;
  }
  for(int i = 0; i < 4; i++){
    leds[pgm_read_word(&waterGreyLeds[i])] = GREY;
  }
  FastLED.show();
}
void steve() {
  for(int i = 0; i < 96; i++){
    leds[pgm_read_word(&steveBrown[i])] = BROWN;
  }
  for(int i = 0; i < 136; i++){
    leds[pgm_read_word(&steveTan[i])] = TAN;
  }
  for(int i = 0; i < 8; i++){
    leds[pgm_read_word(&steveBlue[i])] = BLUE;
  }
  for(int i = 0; i < 8; i++){
    leds[pgm_read_word(&steveWhite[i])] = WHITE;
  }
  for(int i = 0; i < 8; i++){
    leds[pgm_read_word(&steveLightBrown[i])] = ORANGE;
  }
  FastLED.show();
}
void mudkip() {
  for(int i = 0; i < 48; i++){
    leds[pgm_read_word(&mudBlack[i])] = BLACK;
  }
  for(int i = 0; i < 48; i++){
    leds[pgm_read_word(&mudLightBlue[i])] = LIGHTBLUE;
  }
  for(int i = 0; i < 18; i++){
    leds[pgm_read_word(&mudBlue[i])] = BLUE;
  }
  for(int i = 0; i < 12; i++){
    leds[pgm_read_word(&mudRed[i])] = RED;
  }
  for(int i = 0; i < 14; i++){
    leds[pgm_read_word(&mudGrey[i])] = GREY;
  }
  for(int i = 0; i < 2; i++){
    leds[pgm_read_word(&mudWhite[i])] = WHITE;
  }
  FastLED.show();
}
void strawberry() {
  for(int i = 0; i < 4; i++){
    leds[pgm_read_word(&strawGreen[i])] = GREEN;
  }
  for(int i = 0; i < 3; i++){
    leds[pgm_read_word(&strawYellowGreen[i])] = YELLOW;
  }
  for(int i = 0; i < 44; i++){
    leds[pgm_read_word(&strawBlack[i])] = BLACK;
  }
  for(int i = 0; i < 15; i++){
    leds[pgm_read_word(&strawRed[i])] = RED;
  }
  for(int i = 0; i < 58; i++){
    leds[pgm_read_word(&strawPink[i])] = PINK;
  }
  FastLED.show();
}
void batman() {
   for (int i = 0; i < 43; i++){
    leds[pgm_read_word(&batBlack[i])] = GREY;
  }
  for(int i = 0; i < 143; i++){
    leds[pgm_read_word(&batBlue[i])] = BLUE;
  }
   for(int i = 0; i < 75; i++){
    leds[pgm_read_word(&batYellow[i])] = YELLOW;
  }
  FastLED.show();
}
void minecraftCow() {
  for(int i = 0; i < 104; i++){
    leds[pgm_read_word(&cowBrown[i])] = BROWN;
  }
  for(int i = 0; i < 56; i++){
    leds[pgm_read_word(&cowWhite[i])] = WHITE;
  }
  for(int i = 0; i < 64; i++){
    leds[pgm_read_word(&cowGrey[i])] = GREY;
  }
  for(int i = 0; i < 16; i++){
    leds[pgm_read_word(&cowBlack[i])] = BLACK;
  }
  FastLED.show();
}
void minecraftPig() {
  for(int i = 0; i < 200; i++){
    leds[pgm_read_word(&pigPink[i])] = PINK;
  }
  for(int i = 0; i < 8; i++){
    leds[pgm_read_word(&pigMagenta[i])] = MAGENTA;
  }
  for(int i = 0; i < 32; i++){
    leds[pgm_read_word(&pigLightPink[i])] = LIGHTPINK;
  }
  for(int i = 0; i < 8; i++){
    leds[pgm_read_word(&pigBlack[i])] = BLACK;
  }
  for(int i = 0; i < 8; i++){
    leds[pgm_read_word(&pigWhite[i])] = WHITE;
  }
  FastLED.show();
}
