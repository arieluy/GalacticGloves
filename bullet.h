class Bullet {
  public: 
    int size; 
    int x; 
    int  y; 
    int R; 
    int G; 
    int B;
    int color;
    int x_vel; 
    int y_vel; 

    Bullet(int, int, int, int, int, int, int, int); 
    int get_x(); 
    int get_y(); 
    void move();
};

