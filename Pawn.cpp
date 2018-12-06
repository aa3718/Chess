#include "Pawn.h"
#include <iostream>
#include <cmath>

using namespace std;

Pawn::Pawn(Color col) {

  color = col;
  
}

Color Pawn::see_col() {

  return color;
  
};

int Pawn::type() {
  
  return PAWN;
  
};

bool Pawn::validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter) {


  // If white playing
  if (color == White) {
    if (source[0] == destination[0] &&
	destination[1] == source[1] + 1 &&
	Board[destination[1]][destination[0]] == nullptr) {

      return true;
    };

    if (source[0] == destination[0] &&
	destination[1] == source[1] + 2 &&
	Board[destination[1]][destination[0]] == nullptr &&
	Board[source[1] + 1][destination[0]] == nullptr &&
	source[1] == 1) {

      return true;

    };

    if (destination[1] == source[1] + 1 &&
	destination[0] == source[0] + 1 &&
	Board[destination[1]][destination[0]]) {

      return true;
    };

    if (destination[1] == source[1] + 1 &&
	destination[0] == source[0] - 1 &&
	Board[destination[1]][destination[0]]) {

      return true;
    };    
    
  };


  // If black playing
  if (color == Black) {
  
  if (source[0] == destination[0] &&
	destination[1] == source[1] - 1 &&
	Board[destination[1]][destination[0]] == nullptr) {

      return true;
    };

    if (source[0] == destination[0] &&
	destination[1] == source[1] - 2 &&
	Board[destination[1]][destination[0]] == nullptr &&
	Board[source[1] - 1][destination[0]] == nullptr &&
	source[1] == 6) {

      return true;

    };

    if (destination[1] == source[1] - 1 &&
	destination[0] == source[0] + 1 &&
	Board[destination[1]][destination[0]]) {

      return true;
    };

    if (destination[1] == source[1] - 1 &&
	destination[0] == source[0] - 1 &&
	Board[destination[1]][destination[0]]) {

      return true;
    };    

  };

  return false;
};



