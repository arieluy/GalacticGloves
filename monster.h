class Monster
{
public:

  int size;
  int *xpos;
  int *ypos;
  int red;
  int green;
  int blue;
  int speed;
  bool alive;

  Monster(int, int*, int*, int, int, int);
  ~Monster();
  void move();
  void find();
  void die();
};

