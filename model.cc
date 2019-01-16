#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#include "bullet.h"
#include "gunner.h"
#include "spacemonster.h"


int main() {
  bool gameOver = false; 

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

  while(!gameOver) {
    //Read from Controller
    if((rand()%10+1) == 7) {
      int rand_col = rand()%4; 
      Monster newMonster = Monster(rand()%2+1, rand()%32, rand()%14+2,
                                   monsterR[rand_col], monsterG[rand_col], monsterB[rand_col]); 
      //Append monster to monster list                          
      monsters.pushfront(newMonster); 
    }
    //Move all monsters
    for(std::list<Monster>::iterator it = monsters.begin(); it != monsters.end(); it++) {
      *it.move();  
    }
    //Move all Bullets & remove all bullets that are out of range
    for(std::list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); it++) {
      *it.move();  //Move bullet
      //Remove if out of range
      if(*it.get_x() < 0 || *it.get_x() >= 35 || *it.get_y() < 0 || *it.get_y() >=16) {
        bullets.erase(it);  
      }
    }

    //if(bullet hits monster, kill monster)
    
    //Move gunner
    //Create new bullets
    //redraw all
    usleep(1000);  
  }
  return 0; 
}

