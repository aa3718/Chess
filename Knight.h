#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include <cmath>
#include "Piece.h"
#include "Color.h"

class Knight : public Piece {
 public:
  Color color;
  Knight(Color col);
  bool validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter) override;
  Color see_col() override;
  int type() override;


};


#endif
