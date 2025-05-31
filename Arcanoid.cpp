#include <GameBoy.h>
#include "Arduino.h"
#include "Arcanoid.h"

extern GameBoy gb;

byte arcField[8][16];
int platformX = 2;
int platformY = 13;

long clickTime;

void drawPlatform() {
  for (int x = 0; x < 3; x++) {
    arcField[x + platformX][platformY] = 1;
  }
}
void movePlatform() {
  if (millis() - clickTime > 100) {
    if (gb.getKey() == 5) {
      platformX++;
    } else if (gb.getKey() == 4) {
      platformX--;
    }
    clickTime = millis();
  }
}
void fieldDraw() {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 16; y++) {
      if (arcField[x][y] == 1) {
        gb.drawPoint(x, y);
      }
    }
  }
}
void fieldClear() {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 16; y++) {
      arcField[x][y] == 0;
    }
  }
}