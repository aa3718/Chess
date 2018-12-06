#include "Bishop.h"
#include <iostream>

using namespace std;

Bishop::Bishop(Color col) {

  color = col;
  
};

Color Bishop::see_col() {

  return color;

};

int Bishop::type() {

  return BISHOP;
};

bool Bishop::validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter) {

  int i, j;
  
  if ((abs(source[0] - destination[0])) == (abs(source[1] - destination[1]))) {


    if ((source[1] < destination[1]) &&
	(source[0] < destination[0])) {
      for ((i = (source[1] + 1)), (j = (source[0] + 1)) ; i < destination[1] && j < destination[0] ; i++, j++) {
	  if (Board[i][j]) {

	    return false;
	  };
	};
      };
    
    if ((source[1] < destination[1]) &&
	(source[0] > destination[0])) {

      for ((i = (source[1] + 1)), (j = (source[0] - 1)) ; i < destination[1] && j > destination[0] ; i++, j--) {
	  if (Board[i][j]) {

	    return false;
	  };
	};
      };

    if ((source[1] > destination[1]) &&
	(source[0] > destination[0])) {
      for ((i = (source[1] - 1)), (j = (source[0] - 1)) ; i > destination[1] && j > destination[0] ; i--, j--) {
	  if (Board[i][j]) {

	    return false;
	  };
	};
    };

    if ((source[1] > destination[1]) &&
	(source[0] < destination[0])) {
      for ((i = (source[1] - 1)), (j = (source[0] + 1)) ; i > destination[1] && j < destination[0] ; i--, j++) {
	  if (Board[i][j]) {

	    return false;
	  };
	};
      };

    return true;
    
  };
  
    return false;
  
  };
