#include <stdio.h>
#include <iostream>

#include "monster.h"

using namespace std;

Monster::Monster (int s, int *x, int *y, int r, int g, int b, int c, int d)
{
  size = s;
  xpos = x;
  ypos = y;
  red = r;
  green = g;
  blue = b;
  color = c;
  speed = 5;
  dir = d;
  alive = true;
  cout << "New monster created at (" << *xpos << "," << *ypos << ")\n";
}

Monster::~Monster ()
{
  //delete xpos;
  //delete ypos;
}

void Monster::move ()
{
  bool down = false;
  for (int i = 0; i < size; i++) {
    if (xpos[i] == 31) {
      dir = -1;
      down = true;
    } else if (xpos[i] == 0) 
    {
      dir = 1;
      down = true;
    }
  }
  
  for (int i = 0; i < size; i++) {
    if (down) {
      ypos[i] = ypos[i] + 1;
      if (ypos[i] >= 13) alive = false;
    }
    xpos[i] = xpos[i] + dir;
  }
}

void Monster::find()
{
  cout << "Monster is at (" << *xpos << "," << *ypos << ")\n";
}

void Monster::die()
{
  alive = false;
}

/*
int main()
{
  int s = 4;
  int *x = new int[s];
  int *y = new int[s];
  int r = 255;
  int g = 0;
  int b = 0;
  Monster monster(s, x, y, r, g, b);
  monster.move();
  monster.find();
  monster.move();
  monster.find();
}*/
