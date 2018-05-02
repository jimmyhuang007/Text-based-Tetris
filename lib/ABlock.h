#ifndef ABLOCK_H
#define ABLOCK_H

#include <vector>
#include "Coordinate.h"

class AbstractBlock {
protected:
  char piece;
  int level;
  std::vector<Coordinate> coords;
  //Grid *g;
public:
  char getPiece();
  std::vector<Coordinate> getCoords();
  void setCoords(std::vector<Coordinate> c);
  Coordinate getBotLeft(const std::vector<Coordinate> coor);
  Coordinate getTopLeft(const std::vector<Coordinate> coor);
  void left();
  void right();
  void down();
  void rotateCW();
  void rotateCCW();
  void renderBlock();
  int getLevel();
  AbstractBlock &operator=(const AbstractBlock &other);
  virtual ~AbstractBlock();
};

#endif

