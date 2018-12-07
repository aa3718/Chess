#include "Queen.h"
#include <iostream>

using namespace std;

Queen::Queen(Color col) {

  color = col;

};

Color Queen::see_col() {
  return color;
};

int Queen::type() {
  return QUEEN;
};

bool Queen::validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter) {

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

  
  if ((source[0] == destination[0]) || (source[1] == destination[1])) {

 if (source[0] == destination[0] && source[1] == destination[1]) {
      return false;
    };
    
    if (source[0] == destination[0]) {

      
      if (source[1] < destination[1]) {
	for (int i = (source[1] + 1) ; i < destination[1] ; i++) {
	  
	  if (Board[i][source[0]] != nullptr) {

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
