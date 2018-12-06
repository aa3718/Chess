#include "Castle.h"
#include <iostream>

using namespace std;

Castle::Castle(Color col) {

  color = col;
  
};

Color Castle::see_col() {
  
  return color;
  
};

int Castle::type() {

  return CASTLE;

};

bool Castle::validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter) {


  if ((source[0] == destination[0]) || (source[1] == destination[1])) {


    if (source[0] == destination[0] && source[1] == destination[1]) {
      return false;
    };
 
    if (source[0] == destination[0]) {
      if (source[1] < destination[1]) {
	for (int i = (source[1] + 1) ; i < destination[1] ; i++) {
	  if (Board[i][source[0]]) {

	    return false;
	  };
	};
      };

      if (source[1] > destination[1]) {
	for (int i = (source[1] - 1) ; i > destination[1] ; i--) {
	  if (Board[i][source[0]]) {
	    
	    return false;
	  }
	};
      };
    };

    
    if (source[1] == destination[1]) {
    
      
      if (source[0] < destination[0]) {
	for (int i = (source[0] + 1) ; i < destination[0] ; i++) {
	  if (Board[source[1]][i]) {
	   
	    return false;
	  }
	};
      };

      if (source[0] > destination[0]) {
	for (int i = (source[0] - 1); i > destination[0] ; i--) {
	  if (Board[source[1]][i]) {
	    
	    return false;
	  }
	};
      };
    };
    return true;
  } else {
    return false;
  };
  
  return false;

};
