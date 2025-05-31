#include <GameBoy.h>
#include "Arcanoid_blocks.h"
#include "Arcanoid.h"

GameBoy gb;

void setup() {
  gb.begin(2);
}

void loop() {
  gb.clearDisplay();
  fieldClear();
  drawPlatform();
  fieldDraw();
  movePlatform();
}

