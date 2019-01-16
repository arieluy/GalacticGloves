class Monster
{
public:

  int size;
  int *xpos;
  int *ypos;
  int red;
  int green;
  int blue;

  Monster(int, int*, int*, int, int, int);
  ~Monster();
  void move();
  void find();
};

