#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <list>
#include <unistd.h>

#include "rpi-rgb-led-matrix-master/include/led-matrix.h"
#include "bullet.h"
#include "gunner.h"
#include "monster.h"
#include "draw.h"

using namespace std;
using std::list;
using rgb_matrix::Canvas;

int main(int argc, char *argv[]) {
  bool gameOver = false;
  int gameCounter = 0;

  //Monster Colors: R,G,B,Amber
  int monsterR [4] = {255, 0,   0,   255};
  int monsterG [4] = {0,   255, 0,   200};
  int monsterB [4] = {0,   0,   255, 0};

  //Bullet Colors: magenta, light green, cyan, yellow
  int bulletR [4] = {255,   50,     0,   255};
  int bulletG [4] = {0,    255,   255,   255};
  int bulletB [4] = {255,   50,   255,   0};

  std::list<Monster> monsters;
  std::list<Bullet> bullets;

  int x = 3;
  int y = 2;
  Gunner gunner;

  Canvas *canvas = setupLED(argc, argv);

  while(!gameOver && gameCounter < 20) {

    gameCounter++;

    //Read from Controller
    if(true) { //(rand()%10+1) == 7) {
      int rand_col = rand()%4;
      int s = 4;
      int *x = new int[s];
      int *y = new int[s];
      x[0] = rand()%31;
      y[0] = rand()%15;
      x[1] = x[0];
      y[1] = y[0] + 1;
      x[2] = x[0] + 1;
      y[2] = y[0];
      x[3] = x[0] + 1;
      y[3] = y[0] + 1;
      
      Monster newMonster = Monster(4, x, y, monsterR[rand_col],
                                   monsterG[rand_col], monsterB[rand_col]);
      //Append monster to monster list
      monsters.push_front(newMonster);
    }

    cout << "MOVING ALL MONSTERS\n"; 
    //Move all monsters
    for(std::list<Monster>::iterator it = monsters.begin(); it != monsters.end(); it++) {
      it->move();
      it->find();
    }

    cout << "MOVING ALL BULLETS\n"; 
    //Move all Bullets & remove all bullets that are out of range
    for(std::list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++) {
      it->move();  //Move bullet
      //Remove if out of range
      if(it->get_x() < 0 || it->get_x() >= 35 || it->get_y() < 0 || it->get_y() >=16) {
        bullets.erase(it);
      }
    }

    //if(bullet hits monster, kill monster)

    //Move gunner
    //Create new bullets
   
    cout << "DRAW\n"; 

    DrawOnCanvas(canvas, monsters, gunner, bullets); // draws monster, bullets, gunner
    usleep(500000);
  }

  usleep(3000000);
  clearLED(canvas);
  return 0;
}

