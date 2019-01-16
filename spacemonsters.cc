using namespace std;

#include <stdio.h>
#include <iostream>

class Monster
{
public:

  int size;
  int *xpos;
  int *ypos;
  int red;
  int green;
  int blue;

  Monster (int s, int *x, int *y, int r, int g, int b)
  {
    size = s;
    xpos = x;
    ypos = y;
    red = r;
    green = g;
    blue = b;
    cout << "New monster created at " << *x << *y << "\n";
  }

  ~Monster ()
  {
    delete xpos;
    delete ypos;
  }

  void move ()
  {
    for (int i = 0; i < size; i++) {
      xpos[i] = xpos[i] + 1;
    }
  }

  void find()
  {
    cout << "Monster is at " << *xpos << *ypos << "\n";
  }
};


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
}
