#include <Adafruit_NeoPixel.h>

#define R 0
#define G 1
#define B 2

#define NUMPIXELS 11

Adafruit_NeoPixel pixels[] = {
  Adafruit_NeoPixel(NUMPIXELS, 2, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(NUMPIXELS, 3, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(NUMPIXELS, 4, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(NUMPIXELS, 5, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(NUMPIXELS, 6, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(NUMPIXELS, 7, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(NUMPIXELS, 8, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(NUMPIXELS, 9, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(NUMPIXELS, 10, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(NUMPIXELS, 11, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(NUMPIXELS,  12, NEO_GRB + NEO_KHZ800)
};

int nowtime[2];
int oldtime[2];
int color0[3] = {0, 0, 255};
int color1[3] = {255, 0, 0};
int color2[3] = {255, 255, 0};
int color3[3] = {0, 255, 0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels[i].begin(); // This initializes the NeoPixel library.
  }
  serialRead();
  oldtime[0] = nowtime[0];
  oldtime[1] = nowtime[1];
}

void loop() {
  // put your main code here, to run repeatedly:
  serialRead();
  if (oldtime[0] != nowtime[0]) {
    setColor(0, nowtime[0] / 10);
    setColor(1, nowtime[0] % 10);
  }
  if (oldtime[1] != nowtime[1]) {
    setColor(2, nowtime[1] / 10);
    setColor(3, nowtime[1] % 10);
  }
  oldtime[0] = nowtime[0];
  oldtime[1] = nowtime[1];
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels[i].show();
  }
}

void serialRead() {
  if (Serial.available() > 0) {
    for (int i = 0; i < 2; i++) {
      nowtime[i] = Serial.readStringUntil('\n').toInt();
    }
  }
}

void setColor(int pos, int num) {
  int x, y, colors[3];
  switch (pos) {
    case 0:
      x = 0;
      y = 0;
      colors[0] = color0[0];
      colors[1] = color0[1];
      colors[2] = color0[2];
      break;
    case 1:
      x = 6;
      y = 0;
      colors[0] = color1[0];
      colors[1] = color1[1];
      colors[2] = color1[2];
      break;
    case 2:
      x = 0;
      y = 6;
      colors[0] = color2[0];
      colors[1] = color2[1];
      colors[2] = color2[2];
      break;
    case 3:
      x = 6;
      y = 6;
      colors[0] = color3[0];
      colors[1] = color3[1];
      colors[2] = color3[2];
      break;
  }
  switch (num) {
    case 0:
      pixels[y].setPixelColor(x, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 1, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 2, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 3, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 4, pixels[y].Color(colors[R], colors[G], colors[B]));

      pixels[y + 1].setPixelColor(x, pixels[y + 1].Color(colors[R], colors[G], colors[B]));
      pixels[y + 1].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 4, pixels[y + 1].Color(colors[R], colors[G], colors[B]));

      pixels[y + 2].setPixelColor(x, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 1, pixels[y + 2].Color(0, 0, 0));
      pixels[y + 2].setPixelColor(x + 2, pixels[y + 2].Color(0, 0, 0));
      pixels[y + 2].setPixelColor(x + 3, pixels[y + 2].Color(0, 0, 0));
      pixels[y + 2].setPixelColor(x + 4, pixels[y + 2].Color(colors[R], colors[G], colors[B]));

      pixels[y + 3].setPixelColor(x, pixels[y + 3].Color(colors[R], colors[G], colors[B]));
      pixels[y + 3].setPixelColor(x + 1, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 2, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 3, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 4, pixels[y + 3].Color(colors[R], colors[G], colors[B]));

      pixels[y + 4].setPixelColor(x, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 1, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 2, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 3, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 4, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      break;

    case 1:
      pixels[y].setPixelColor(x, pixels[y + 1].Color(0, 0, 0));
      pixels[y].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y].setPixelColor(x + 4, pixels[y].Color(colors[R], colors[G], colors[B]));

      pixels[y + 1].setPixelColor(x, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 4, pixels[y + 1].Color(colors[R], colors[G], colors[B]));

      pixels[y + 2].setPixelColor(x, pixels[y + 2].Color(0, 0, 0));
      pixels[y + 2].setPixelColor(x + 1, pixels[y + 2].Color(0, 0, 0));
      pixels[y + 2].setPixelColor(x + 2, pixels[y + 2].Color(0, 0, 0));
      pixels[y + 2].setPixelColor(x + 3, pixels[y + 2].Color(0, 0, 0));
      pixels[y + 2].setPixelColor(x + 4, pixels[y + 2].Color(colors[R], colors[G], colors[B]));

      pixels[y + 3].setPixelColor(x, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 1, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 2, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 3, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 4, pixels[y + 3].Color(colors[R], colors[G], colors[B]));

      pixels[y + 4].setPixelColor(x, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 1, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 2, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 3, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 4, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      break;

    case 2:
      pixels[y].setPixelColor(x, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 1, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 2, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 3, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 4, pixels[y].Color(colors[R], colors[G], colors[B]));

      pixels[y + 1].setPixelColor(x, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 4, pixels[y + 1].Color(colors[R], colors[G], colors[B]));

      pixels[y + 2].setPixelColor(x, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 1, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 2, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 3, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 4, pixels[+2].Color(colors[R], colors[G], colors[B]));

      pixels[y + 3].setPixelColor(x, pixels[y + 3].Color(colors[R], colors[G], colors[B]));
      pixels[y + 3].setPixelColor(x + 1, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 2, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 3, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 4, pixels[y + 3].Color(0, 0, 0));

      pixels[y + 4].setPixelColor(x, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 1, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 2, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 3, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 4, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      break;

    case 3:
      pixels[y].setPixelColor(x, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 1, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 2, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 3, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 4, pixels[y].Color(colors[R], colors[G], colors[B]));

      pixels[y + 1].setPixelColor(x, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 4, pixels[y + 1].Color(colors[R], colors[G], colors[B]));

      pixels[y + 2].setPixelColor(x, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 1, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 2, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 3, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 4, pixels[+2].Color(colors[R], colors[G], colors[B]));

      pixels[y + 3].setPixelColor(x + 0, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 1, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 2, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 3, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 4, pixels[y + 3].Color(colors[R], colors[G], colors[B]));

      pixels[y + 4].setPixelColor(x, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 1, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 2, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 3, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 4, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      break;

    case 4:
      pixels[y].setPixelColor(x, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y].setPixelColor(x + 4, pixels[y].Color(colors[R], colors[G], colors[B]));

      pixels[y + 1].setPixelColor(x, pixels[y + 1].Color(colors[R], colors[G], colors[B]));
      pixels[y + 1].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 4, pixels[y].Color(colors[R], colors[G], colors[B]));

      pixels[y + 2].setPixelColor(x, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 1, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 2, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 3, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 4, pixels[+2].Color(colors[R], colors[G], colors[B]));

      pixels[y + 3].setPixelColor(x, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 1, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 2, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 3, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 4, pixels[y + 3].Color(colors[R], colors[G], colors[B]));

      pixels[y + 4].setPixelColor(x, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 1, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 2, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 3, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 4, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      break;

    case 5:
      pixels[y].setPixelColor(x, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 1, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 2, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 3, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 4, pixels[y].Color(colors[R], colors[G], colors[B]));

      pixels[y + 1].setPixelColor(x, pixels[y + 1].Color(colors[R], colors[G], colors[B]));
      pixels[y + 1].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 4, pixels[y + 1].Color(0, 0, 0));

      pixels[y + 2].setPixelColor(x, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 1, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 2, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 3, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 4, pixels[+2].Color(colors[R], colors[G], colors[B]));

      pixels[y + 3].setPixelColor(x, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 1, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 2, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 3, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 4, pixels[y + 3].Color(colors[R], colors[G], colors[B]));

      pixels[y + 4].setPixelColor(x, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 1, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 2, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 3, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 4, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      break;

    case 6:
      pixels[y].setPixelColor(x, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 1, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 2, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 3, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 4, pixels[y].Color(colors[R], colors[G], colors[B]));

      pixels[y + 1].setPixelColor(x, pixels[y + 1].Color(colors[R], colors[G], colors[B]));
      pixels[y + 1].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 4, pixels[y + 1].Color(0, 0, 0));

      pixels[y + 2].setPixelColor(x, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 1, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 2, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 3, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 4, pixels[+2].Color(colors[R], colors[G], colors[B]));

      pixels[y + 3].setPixelColor(x, pixels[y + 3].Color(colors[R], colors[G], colors[B]));
      pixels[y + 3].setPixelColor(x + 1, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 2, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 3, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 4, pixels[y + 3].Color(colors[R], colors[G], colors[B]));

      pixels[y + 4].setPixelColor(x, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 1, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 2, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 3, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 4, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      break;

    case 7:
      pixels[y].setPixelColor(x, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 1, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 2, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 3, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 4, pixels[y].Color(colors[R], colors[G], colors[B]));

      pixels[y + 1].setPixelColor(x, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 4, pixels[y + 1].Color(colors[R], colors[G], colors[B]));

      pixels[y + 2].setPixelColor(x, pixels[y + 2].Color(0, 0, 0));
      pixels[y + 2].setPixelColor(x + 1, pixels[y + 2].Color(0, 0, 0));
      pixels[y + 2].setPixelColor(x + 2, pixels[y + 2].Color(0, 0, 0));
      pixels[y + 2].setPixelColor(x + 3, pixels[y + 2].Color(0, 0, 0));
      pixels[y + 2].setPixelColor(x + 4, pixels[y + 2].Color(colors[R], colors[G], colors[B]));

      pixels[y + 3].setPixelColor(x + 0, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 1, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 2, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 3, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 4, pixels[y + 3].Color(colors[R], colors[G], colors[B]));

      pixels[y + 4].setPixelColor(x, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 1, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 2, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 3, pixels[y + 4].Color(0, 0, 0));
      pixels[y + 4].setPixelColor(x + 4, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      break;

    case 8:
      pixels[y].setPixelColor(x, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 1, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 2, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 3, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 4, pixels[y].Color(colors[R], colors[G], colors[B]));

      pixels[y + 1].setPixelColor(x, pixels[y + 1].Color(colors[R], colors[G], colors[B]));
      pixels[y + 1].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 4, pixels[y + 1].Color(colors[R], colors[G], colors[B]));

      pixels[y + 2].setPixelColor(x, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 1, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 2, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 3, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 4, pixels[+2].Color(colors[R], colors[G], colors[B]));

      pixels[y + 3].setPixelColor(x, pixels[y + 3].Color(colors[R], colors[G], colors[B]));
      pixels[y + 3].setPixelColor(x + 1, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 2, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 3, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 4, pixels[y + 3].Color(colors[R], colors[G], colors[B]));

      pixels[y + 4].setPixelColor(x, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 1, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 2, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 3, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 4, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      break;

    case 9:

      pixels[y].setPixelColor(x, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 1, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 2, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 3, pixels[y].Color(colors[R], colors[G], colors[B]));
      pixels[y].setPixelColor(x + 4, pixels[y].Color(colors[R], colors[G], colors[B]));

      pixels[y + 1].setPixelColor(x, pixels[y + 1].Color(colors[R], colors[G], colors[B]));
      pixels[y + 1].setPixelColor(x + 1, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 2, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 3, pixels[y + 1].Color(0, 0, 0));
      pixels[y + 1].setPixelColor(x + 4, pixels[y + 1].Color(colors[R], colors[G], colors[B]));

      pixels[y + 2].setPixelColor(x, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 1, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 2, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 3, pixels[y + 2].Color(colors[R], colors[G], colors[B]));
      pixels[y + 2].setPixelColor(x + 4, pixels[+2].Color(colors[R], colors[G], colors[B]));

      pixels[y + 3].setPixelColor(x + 0, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 1, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 2, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 3, pixels[y + 3].Color(0, 0, 0));
      pixels[y + 3].setPixelColor(x + 4, pixels[y + 3].Color(colors[R], colors[G], colors[B]));

      pixels[y + 4].setPixelColor(x, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 1, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 2, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 3, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      pixels[y + 4].setPixelColor(x + 4, pixels[y + 4].Color(colors[R], colors[G], colors[B]));
      break;

    default:
      break;
  }
}
