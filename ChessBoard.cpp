#include "ChessBoard.h"
#include "Color.h"
#include "King.h"
#include "Queen.h"
#include "Castle.h"
#include "Bishop.h"
#include "Knight.h"     
#include "Pawn.h"
#include "Piece.h"
#include <iostream>
#include <vector>

using namespace std;

ChessBoard::ChessBoard():pawn_black(8, Pawn(Black)),
			 pawn_white(8, Pawn(White)),
			 castle_white(2, Castle(White)),
			 castle_black(2, Castle(Black)),
			 bishop_white(2, Bishop(White)),
			 bishop_black(2, Bishop(Black)),
			 knight_white(2, Knight(White)),
			 knight_black(2, Knight(Black))
{

  resetBoard();

};

void ChessBoard::resetBoard() {

  for (int rank_i = 0; rank_i < row_length; rank_i++) {
    for (int file_j = 0; file_j < file_length; file_j++) {
      Board[rank_i][file_j] = nullptr;
    };
  };
  
  row = 0;
  file = 0;

  Board[row][file] = &castle_white[0];
  file++;
  Board[row][file] = &knight_white[0];
  file++;
  Board[row][file] = &bishop_white[0];
  file++;
  Board[row][file] = &queen_white;
  file++;
  Board[row][file] = &king_white;
  file++;
  Board[row][file] = &bishop_white[1];
  file++;
  Board[row][file] = &knight_white[1];
  file++;
  Board[row][file] = &castle_white[1];
  
  row = 1;
  file = 0;
  
  for (; file < file_length; file++) {
    Board[row][file] = &pawn_white[file];  
  };
  
  row = 6;
  file = 0;
  
  for (; file < file_length; file++) {
    Board[row][file] = &pawn_black[file];
  };

  row = 7;
  file = 0;
  
  Board[row][file] = &castle_black[0];
  file++;
  Board[row][file] = &knight_black[0];
  file++;
  Board[row][file] = &bishop_black[0];
  file++;
  Board[row][file] = &queen_black;
  file++;
  Board[row][file] = &king_black;
  file++;
  Board[row][file] = &bishop_black[1];
  file++;
  Board[row][file] = &knight_black[1];
  file++;
  Board[row][file] = &castle_black[1];
 
};

void ChessBoard::submitMove(const char source_s[], const char destination_s[]) {

  cout << source_s[0] << source_s[1] << " to " << destination_s[0] << destination_s[1] << " is the move given.\n";
  
  source[0] = source_s[0] - 'A';
  source[1] = source_s[1] - '1';  

  destination[0] = destination_s[0] - 'A';
  destination[1] = destination_s[1] - '1';
  
  for (int i = 0 ; i < 2 ; i++) {
    if (source[i] < 0 || source[i] > 7) {
      cout << "Sorry wrong source input value." << endl;
      return;
    };
  };

  for (int i = 0 ; i < 2 ; i++) {
    if (destination[i] < 0 || destination[i] > 7) {
      cout << "Sorry wrong destination input value." << endl;
      return;
    };
  };
  
  findPiece();
};


int ChessBoard::findPiece() {
  
  // Checking if it the right colors turn
  if ((Board[source[1]][source[0]]) &&
      (counter % 2 == 0) &&
      (Board[source[1]][source[0]]->see_col() == Black)) {

    cout << "Wrong color: Not blacks turn.\n";

    return 0;

  };
  
  if ((Board[source[1]][source[0]]) &&
      (counter % 2 == 1) &&
      (Board[source[1]][source[0]]->see_col() == White)) {

    cout << "Wrong color: Not whites turn.\n";

    return 0;

  };

  // Checking if it is a valid move and that the source move is not empty
  if (Board[source[1]][source[0]]) {
    
    if (Board[source[1]][source[0]]->validatePiece(source, destination, Board, counter) == true) {

      if (Board[destination[1]][destination[0]] &&
	  Board[destination[1]][destination[0]]->see_col() == Board[source[1]][source[0]]->see_col()) {

	cout << "Sorry can't put a piece where your own color piece already is.\n";

	return 0;
	
      };

      if (Board[destination[1]][destination[0]]) {
	
	cout << "Eaten piece at destination :";
	printOutType(destination[1], destination[0]);
	cout << "\n";
	
      };

      // Make move on the board
      auto hold = Board[destination[1]][destination[0]];
      Board[destination[1]][destination[0]] = Board[source[1]][source[0]];
      Board[source[1]][source[0]] = nullptr;

      if (inCheck(king_pos_w, Black) == true) {

	cout << "White in check.\n";

	// Checking it did not put own piece in check resulting in an illegal move
	if (counter % 2 == 0) {
	  
	  // Reversing move on board if results in illegal move
	  Board[source[1]][source[0]] = Board[destination[1]][destination[0]];
	  Board[destination[1]][destination[0]] = hold;

	  cout << "This move leads to your own pawn in check, not allowed, please play again.\n";

	  return 0;

	};

	if (checkMate(king_pos_w, Black) == true) {
	  cout << "Nice move.\n";
	  cout << "Checkmate.\n";

	  return 0;
	  
	};
	
      };

      // Check if in stalemate if not in Check for Black
      if ((checkMate(king_pos_w, Black) == true)) {

	cout << "Stalemate.\n";

	return 0;

      };
      
      
      if (inCheck(king_pos_b, White) == true) {

	cout << "Black in check.\n";

	// Checking it did not put own piece in check resulting in an illegal move
	if (counter % 2 == 1) {
	  
	  // Reversing the move on the board if results in illegal move
	  Board[source[1]][source[0]] = Board[destination[1]][destination[0]];
	  Board[destination[1]][destination[0]] = hold;
	  
	  cout << "This move leads to your own pawn in check, not allowed, please play again.\n";
	  return 0;
	  
	};

	if (checkMate(king_pos_b, White) == true) {
	  cout << "Nice move.\n";
	  cout << "Checkmate.\n";

	  return 0;
	};
	
      };

      // Check if in stalemate if not in Check for White 
      if (checkMate(king_pos_b, White) == true) {

	cout << "Stalemate.\n";

	return 0;

      };

      // If valid move print out color and type moved
      
      cout << "Nice move: ";

      if (counter % 2 == 0) {
	cout << "White";
      };

      if (counter % 2 == 1) {
	cout << "Black";
      };
      
      printOutType(destination[1], destination[0]);
      cout << "moved.\n";
  
      counter++;

      
    } else {
      
      cout << "Sorry it is not a valid move.\n";
      
      return 0;
    };

  } else {
    
    cout << "The space is empty, there is no piece at source given.\n";

    return 0;
  };
  
  return 0;
};

bool ChessBoard::inCheck(int king_pos[], Color color) {

  // Finds the King
  for (int row = 0 ; row < 8 ; row++) {
    for (int file = 0 ; file < 8 ; file++) {

      if (Board[row][file] &&
	  Board[row][file]->type() == KING &&
	  Board[row][file]->see_col() != color) {
	
	king_pos[0] = file;
	king_pos[1] = row;
	
      };
    };
  };

  // Any valid move from piece of the opposite color that could take king
  for (int i = 0 ; i < 8 ; i++) { 
    for (int j = 0 ; j < 8 ; j++) {
      
      int positionTest[2];
      positionTest[0] = j;
      positionTest[1] = i;
      
      if (Board[i][j] &&
	  Board[i][j]->see_col() == color &&
	  Board[i][j]->validatePiece(positionTest, king_pos, Board, counter) == true) {
	
	return true;
	
      };
    };
  };

  return false;
  
};
  
  
bool ChessBoard::checkMate(int king_pos[], Color color) {

  // Piece pointer holding vaue for reverse
  Piece* holding;
  
  // Goes through entire board and looks for own color pieces
  for (int row = 0 ; row < 8 ; row++) {
    for (int file = 0 ; file < 8 ; file++) {

      if (Board[row][file] &&
	  Board[row][file]->see_col() != color) {

	// Creating array for possible piece move
	int possible_piece[2];
	possible_piece[0] = file;
	possible_piece[1] = row;
      
	for (int possible_row = 0 ; possible_row < 8 ; possible_row++) {
	  for (int  possible_file = 0 ; possible_file < 8 ; possible_file++) {

	    // Creating array for possible move
	    int possible_move[2];
	    possible_move[0] = possible_file;
	    possible_move[1] = possible_row;

	    // Checking whether fake move is valid with given piece
	    if (Board[row][file]->validatePiece(possible_piece, possible_move, Board, counter) == true) {
	      // Checking if destination is empty or can eat the pawn of other color
	      if ((Board[possible_row][possible_file] == nullptr) || 
		  (Board[possible_row][possible_file] &&
		   Board[possible_row][possible_file]->see_col() == color)) {

		// Make the move on physical board
		holding = Board[possible_row][possible_file];
		Board[possible_row][possible_file] = Board[row][file];
		Board[row][file] = nullptr;

		// Now that move made on board check if still InCheck
		if (inCheck(king_pos, color) == false) {

		  // If inCheck is false then CM is not happening so delete change keep going
		  Board[row][file] = Board[possible_row][possible_file];
                  Board[possible_row][possible_file]= holding;

		  return false;

		} else {
		  
		  // Reverse move but keep going to try and find another move
		  Board[row][file] = Board[possible_row][possible_file];
		  Board[possible_row][possible_file]= holding;
		  
		};
	      };
	    };
	  };
	};
      };
    };
  };

  // If goes through entire possible moves and nothing gets it out of inCheck then it is CheckMate
  return true;

  
};


int ChessBoard::printOutType(int row, int file) {

  
  if (Board[row][file]->type() == 1) {

    cout << " Queen ";

    return 0;
  }; 


  if (Board[row][file]->type() == 2) {

    cout << " King ";
    
    return 0;

  };

  if (Board[row][file]->type() == 3) {

    cout << " Bishop ";
    
    return 0;
    
  }; 

  if (Board[row][file]->type() == 4) {

    cout << " Castle ";
    
    return 0;

  }; 

  if (Board[row][file]->type() == 5) {

    cout << " Pawn ";
    
    return 0;
    
  }; 

  if (Board[row][file]->type() == 6) {

    cout << " Knight ";
    
    return 0;

  }; 

  return 0;
  
};



  
 






