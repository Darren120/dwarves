
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bot.h"

using namespace std;
const int MAX_ROWS = 40;
const int MAX_COLS = 40;
const int MAX_NUM = 10;

int ROWS;  // global variables
int COLS;
int NUM;
bool isNextToATree(Dwarf & dwarf, int r, int c){
  if (dwarf.look(r, c-1) == PINE_TREE || dwarf.look(r, c-1) == APPLE_TREE)
  {
    // dwarf.start_chop(WEST);

    return true;
  }
  if (dwarf.look(r, c+1) == PINE_TREE || dwarf.look(r, c+1) == APPLE_TREE)
  {
    // dwarf.start_chop(EAST);

    return true;
  }
  if (dwarf.look(r+1, c) == PINE_TREE || dwarf.look(r+1, c) == APPLE_TREE)
  {
    // dwarf.start_chop(SOUTH);

    return true;
  }
  if (dwarf.look(r-1, c) == PINE_TREE || dwarf.look(r-1, c) == APPLE_TREE)
  {
    // dwarf.start_chop(NORTH);

    return true;
  }
  return false;

}
/* onStart: 
An Initialization procedure called at the start of the game.
You can use it to initialize certain global variables, or do 
something else before the actual simulation starts.
Parameters:
    rows: number of rows
    cols: number of columns
    num:  number of dwarfs
    log:  a cout-like log */

void onStart(int rows, int cols, int num, std::ostream &log) {
  log << "Start!" << endl; // Print a greeting message

  ROWS = rows; // Save values in global variables
  COLS = cols;
  NUM = num;
}

/* onAction: 
A procedure called each time an idle dwarf is choosing 
their next action.
Parameters:
    dwarf:   dwarf choosing an action
    day:     day (1+)
    hours:   number of hours in 24-hour format (0-23)
    minutes: number of minutes (0-59)
    log:     a cout-like log  */
int lol = 0;
int lul = 0;
void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) {
  // Get current position of the dwarf
  int r = dwarf.row();
  int c = dwarf.col();
  // bool a = isNextToATree(dwarf,r,c);

  // Look if there is a tree on the right from the dwarf

    // If there is a pine tree, chop it
  if (dwarf.look(r, c-1) == PINE_TREE || dwarf.look(r, c-1) == APPLE_TREE)
  {
    dwarf.start_chop(WEST);
    log << "Found a tree -- chop" << endl;
    return;
  }else if(dwarf.look(r, c+1) == PINE_TREE || dwarf.look(r, c+1) == APPLE_TREE)
  {
    dwarf.start_chop(EAST);
    log << "Found a tree -- chop" << endl;
    return;
  }else if (dwarf.look(r+1, c) == PINE_TREE || dwarf.look(r+1, c) == APPLE_TREE)
  {
    dwarf.start_chop(SOUTH);
    log << "Found a tree -- chop" << endl;
    return;
  }else if (dwarf.look(r-1, c) == PINE_TREE || dwarf.look(r-1, c) == APPLE_TREE)
  {
    dwarf.start_chop(NORTH);
    log << "Found a tree -- chop" << endl;
    return;
  } else {
    // Otherwise, move to a random location
    for (int i = lol; i < MAX_ROWS; ++i)
    {
      for (int j = lul; j < MAX_COLS; ++j)
      {
        if (isNextToATree(dwarf,i,j))
        {
          lol = i;
          lul = 0;
          log << "Found a spot" << endl;
          dwarf.start_walk(i, j);
          return;
        }
      }
    }
  }
}

