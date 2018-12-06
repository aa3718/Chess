#ifndef KING_H
#define KING_H

#include <iostream>
#include <cmath>
#include "Piece.h"
#include "Color.h"

class King : public Piece {
 public:
  Color color;
  King(Color col);
  bool validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter) override;
  Color see_col() override;
  int type() override;
};

#endif
