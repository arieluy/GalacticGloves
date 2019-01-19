// -*- mode: c++; c-basic-offset: 2; indent-tabs-mode: nil; -*-
// Small example how to use the library.
// For more examples, look at demo-main.cc
//
// This code is public domain
// (but note, that the led-matrix library this depends on is GPL v2)

#include "rpi-rgb-led-matrix-master/include/led-matrix.h"

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>
#include <iostream>
#include <list>
#include <unistd.h>

#include "bullet.h"
#include "gunner.h"
#include "monster.h"
#include "draw.h"

using namespace std;
using std::list;

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

volatile bool interrupt_received = false;
void InterruptHandler(int signo) {
  interrupt_received = true;
}

void DrawOnCanvas(Canvas *canvas, std::list<Monster> monsters,
                         Gunner gunner, std::list<Bullet> bullets) {
  canvas->Fill(0,0,0);

  // draw floor
  for (int i = 0; i < 32; i++) {
    for (int j = 14; j < 16; j++) {
      canvas->SetPixel(i, j, 10, 10, 20);
    }
  }

  // Draw monsters
  for(std::list<Monster>::iterator it = monsters.begin(); it != monsters.end();
      it++) {
    for (int i = 0; i < it->size; i++) {
      canvas->SetPixel((it->xpos)[i], (it->ypos)[i],
                       it->red, it->green, it->blue);
    }
  }

  // Draw gunner
  canvas->SetPixel(gunner.x0, gunner.y0,
                   gunner.R, gunner.G, gunner.B);
  canvas->SetPixel(gunner.x1, gunner.y1,
                   gunner.R, gunner.G, gunner.B);

  // Draw bullets
  for(std::list<Bullet>::iterator it = bullets.begin(); it != bullets.end();
      it++) {
    canvas->SetPixel(it->x, it->y, it->R, it->G, it->B);
  }
}

Canvas* setupLED(int argc, char *argv[]) {
  RGBMatrix::Options defaults;
  defaults.hardware_mapping = "regular";  // or e.g. "adafruit-hat"
  defaults.rows = 16;
  defaults.chain_length = 1;
  defaults.parallel = 1;
  defaults.show_refresh_rate = true;
  Canvas *canvas = rgb_matrix::CreateMatrixFromFlags(&argc, &argv, &defaults);
  if (canvas == NULL)
    return NULL;

  // It is always good to set up a signal handler to cleanly exit when we
  // receive a CTRL-C for instance. The DrawOnCanvas() routine is looking
  // for that.
  signal(SIGTERM, InterruptHandler);
  signal(SIGINT, InterruptHandler);
  return canvas;
}


  // DrawOnCanvas(canvas);    // Using the canvas.
  // usleep(5000000);  // wait a little to slow down things.

void clearLED(Canvas *canvas) {
  // Animation finished. Shut down the RGB matrix.
  canvas->Clear();
  delete canvas;
}
