#include "King.h"
#include <iostream>
#include <cmath>

using namespace std;

King::King(Color col) {

  color = col;
  
};

Color King::see_col() {
  return color;
};

int King::type() {
  
  return KING;
  
};

bool King::validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter) { 
 
  if ((destination[1] == source[1] && destination[0] == source[0] + 1) ||
      (destination[1] == source[1] + 1 && destination[0] == source[0]) ||
      (destination[1] == source[1] - 1 && destination[0] == source[0]) ||
      (destination[1] == source[1] && destination[0] == source[0] - 1) ||
      (destination[1] == source[1] - 1 && destination[0] == source[0] - 1) ||
      (destination[1] == source[1] + 1 && destination[0] == source[0] + 1) ||
      (destination[1] == source[1] + 1 && destination[0] == source[0] - 1) ||
      (destination[1] == source[1] - 1 && destination[0] == source[0] + 1)) {
      
    return true;
    } else {
    
      return false;
      
    };

};
