#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include <cmath>
#include "Piece.h"
#include "Color.h"

class Bishop : public Piece {
 public:
  Color color;
  Bishop(Color col);
  bool validatePiece(const int source[], const int destination[], Piece* Board[8][8], const int counter) override;
  Color see_col() override;
  int type() override;

};

#endif
