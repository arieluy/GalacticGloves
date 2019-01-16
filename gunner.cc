#include <iostream>

using namespace std; 

class gunner {
  public: 
    int size; 
    int* x; 
    int* y; 
    int R; 
    int G; 
    int B; 
    int angle; 
  
    gunner(); 
    ~gunner(); 
    void set_color(int, int, int); 
    void set_x(int); 
    void set_angle(int); 
};

gunner::gunner() {
  R = 200; 
  G = 200; 
  B = 200; 
  angle = 0; 
  size = 2; 
  x = new int[size]; 
  y = new int[size];
  x[0] = 15; //gunner body 
  y[0] = 15;
  x[1] = 15; //gunner turret
  y[1] = 14; 
}

gunner::~gunner() {
  delete[] x; 
  delete[] y; 
}

void gunner::set_color(int R_new, int G_new, int B_new) {
  R = R_new; 
  G = G_new; 
  B = B_new;
}

//Update the position of the body of the gunner
// move left if -1, move right if 1
void gunner::set_x(int dir) {
  int new_x; 
  new_x = x[0] + dir; 
  if(new_x >= 0 && new_x <= 31) {
    x[0] = new_x; 
    if(new_x == 0 && angle == -1) {
      angle = 0;
    }
    else if(new_x == 31 && angle == 1) {
      angle = 0; 
    }
    x[1] = new_x + angle;
  }
}

//Update the angle to be to the left if -1, straight up if 0, 
//and to the right if 1
void gunner::set_angle(int new_angle) {
  if(x[0] == 0 && angle == -1) {
    angle = 0; 
  }
  else if(x[0] == 31 && angle == 1) {
    angle = 0; 
  }
  else {
    angle = new_angle; 
  }
}


int main() {
    gunner g; 
    g.set_color(12,3,12); 
    return 0; 
}
