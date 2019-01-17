#include <stdio.h>
#include <iostream>

#include "monster.h"

using namespace std;

Monster::Monster (int s, int *x, int *y, int r, int g, int b)
{
  size = s;
  xpos = x;
  ypos = y;
  red = r;
  green = g;
  blue = b;
  cout << "New monster created at (" << *xpos << "," << *ypos << ")\n";
}

Monster::~Monster ()
{
  //delete xpos;
  //delete ypos;
}

void Monster::move ()
{
  for (int i = 0; i < size; i++) {
    xpos[i] = xpos[i] + 1;
  }
}

void Monster::find()
{
  cout << "Monster is at (" << *xpos << "," << *ypos << ")\n";
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
