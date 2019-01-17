#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  initscr();
  int chr = getch();
  endwin();
  cout << chr; 
  return 0;
}
