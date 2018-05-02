#include <iostream>
#include "Cell.h"
using namespace std;

Cell::Cell() : coord(Coordinate{0, 0}), piece(' '), b(nullptr) {
}

Coordinate Cell::getCoord() {
  return coord;
}

void Cell::setCoord(Coordinate c) {
  coord.x = c.x;
  coord.y = c.y;
}

void Cell::textRender() {
  cout << piece;
}

void Cell::setPiece(char c) {
  piece = c;
}

char Cell::getPiece() {
  return piece;
}

Cell::~Cell() {
  //delete b;
}
