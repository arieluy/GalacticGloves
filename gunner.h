class Gunner {
  public: 
    int size; 
    int* x; 
    int* y; 
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

