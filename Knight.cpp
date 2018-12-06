#include "Knight.h"
#include <iostream>
#include <cmath>

using namespace std;

Knight::Knight(Color col) {

  color = col;

};

Color Knight::see_col() {

  return color;

};

int Knight::type() {
  
  return KNIGHT;

};

bool Knight::validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter) {

  if ((abs(source[0] - destination[0]) == 2 && abs(source[1] - destination[1]) == 1) ||
      (abs(source[0] - destination[0]) == 1 &&abs(source[1] - destination[1]) == 2)) {
 
    return true;
	
  } else {
    
    return false;

  };
};
