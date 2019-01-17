class Gunner {
  public: 
    int size; 
    int x0;  
    int y0;
    int x1; 
    int y1;
    int R; 
    int G; 
    int B; 
    int angle; 
  
    Gunner(); 
    ~Gunner(); 
    void set_color(int, int, int); 
    void set_x(int); 
    void set_angle(int); 
};

