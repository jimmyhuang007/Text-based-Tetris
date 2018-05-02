#ifndef CELL_H
#define CELL_H
#include "ABlock.h"

class Cell {
  Coordinate coord;  //may not need
  char piece;
  AbstractBlock *b;
public:
  Cell();
  Coordinate getCoord();
  void setCoord(Coordinate c);
  void setPiece(char c);
  char getPiece();
  bool isOccupied();
  //Block * getBlock();
  //Cell * update(char pce, bool occ, Block *blk);
  void textRender();
  //Cell &operator=(const Cell &o);
  ~Cell();
};

#endif
