#include "bullet.h"
#include <iostream>

using namespace std;

/*
class Bullet {
  public:
    int size;
    int x;
    int  y;
    int R;
    int G;
    int B;
    int x_vel;
    int y_vel;

    Bullet(int, int, int, int, int, int, int);
    int get_x();
    int get_y();
    void move();
};*/

Bullet::Bullet(int R_new, int G_new, int B_new, int color_new,
               int x_init, int y_init,
               int x_vel_init, int y_vel_init) {
  R = R_new;
  G = G_new;
  B = B_new;
  color = color_new;
  size = 1;
  x = x_init;
  y = y_init;
  x_vel = x_vel_init;
  y_vel = y_vel_init;
  cout << "created new bullet at (" << x << "," << y << ") with color (" << R << "," << G << "," << B << ")\n\t"
          << "and velocity (" << x_vel << "," << y_vel << ")\n";
}

void Bullet::move() {
  x = x+x_vel;
  y = y+y_vel;
  cout << "Moved bullet to (" << x << "," << y << ")\n";
};

int Bullet::get_x() {
  return x;
}

int Bullet::get_y() {
  return y;
}

/*
int main() {
  Bullet myfirstbullet(255, 0, 12, 5,3, 1,1);
  myfirstbullet.move();
  myfirstbullet.move();
  myfirstbullet.move();
}*/
