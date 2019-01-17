#ifndef DRAW_H
#define DRAW_H

#include "rpi-rgb-led-matrix-master/include/led-matrix.h"

using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;


void InterruptHandler(int);
void DrawOnCanvas(Canvas*, std::list<Monster>, Gunner, std::list<Bullet>);
Canvas* setupLED(int, char*[]);
void clearLED(Canvas*);

#endif
