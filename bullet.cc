#include <iostream> 

using namespace std; 

class bullet {
  public: 
    int size; 
    int x; 
    int  y; 
    int R; 
    int G; 
    int B; 
    int x_vel; 
    int y_vel; 

    bullet(int, int, int, int, int); 
    move(); 
};

bullet::bullet(int R_new, int G_new, int B_new, 
               int x_init, int y_init, 
               int x_vel, int y_vel) {
  R = R_new; 
  G = G_new; 
  B = B_new; 
  size = 1; 
  x = x_init; 
  y = y_init; 
  x_vel = x_vel; 
  y_vel = y_vel; 
}

void bullet::move() {
  x = x+x_vel; 
  y = y+y_vel; 
};
