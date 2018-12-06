#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <vector>
#include "King.h"
#include "Queen.h"
#include "Castle.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Piece.h"
#include "Color.h"

class ChessBoard {
 public:
  ChessBoard();
  int row;
  int file;
  int file_length = 8;
  int row_length = 8;
  int counter = 0;
  Piece* Board[8][8];
  int source[3];
  int destination[3];
  int king_pos_w[3];
  int king_pos_b[3];
  Queen queen_black = Queen(Black);
  Queen queen_white = Queen(White);
  King king_black = King(Black);
  King king_white = King(White);
  std::vector<Pawn> pawn_black;
  std::vector<Pawn> pawn_white;
  std::vector<Castle> castle_white;
  std::vector<Castle> castle_black;
  std::vector<Bishop> bishop_white;
  std::vector<Bishop> bishop_black;
  std::vector<Knight> knight_white;
  std::vector<Knight> knight_black;
  void resetBoard();
  void submitMove(const char source_s[], const char destination_s[]);
  int findPiece();
  bool inCheck(int king_pos[], Color color);
  bool checkMate(int king_pos[], Color color);
  bool stalemate();
  bool white_in_check = false;
  bool black_in_check = false;
};

#endif
