#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <utility>
#include <stdexcept>
#include <vector>
#include <memory>
#include "ABlock.h"
using namespace std;

vector<Coordinate> AbstractBlock::getCoords() {
  return coords;
}

void AbstractBlock::setCoords(vector<Coordinate> c) {
  coords = c;
  coords.resize(c.size());
}

void AbstractBlock::renderBlock() {
  int space1 = coords.at(0).x;
  int space2 = 0;
  bool isTwo = false;
  for (int i = 0; i < 4; ++i) {
    if (coords.at(i).y == 4) {
      space2 = coords.at(i).x;
      isTwo = true;
      break;
    }
  }
  for (int i = 0; i < space1; ++i) {
    cout << " ";
  }
  for (int i = 0; i < 4; ++i) {
    if (coords.at(i).y == 3) {
      cout << piece;
    }
  }
  if (isTwo) {
    cout << endl;
  }
  for (int i = 0; i < space2; ++i) {
    cout << " ";
  }
  for (int i = 0; i < 4; ++i) {
    if (coords.at(i).y == 4) {
      cout << piece;
    }
  }
  cout << endl;
}

int AbstractBlock::getLevel() {
  return level;
}
  
Coordinate AbstractBlock::getBotLeft(const vector<Coordinate> coor) {
  int x = 14;
  int y = 0;
  for (auto &coord : coords) {
    if (coord.x < x) {
      x = coord.x;
    }
    if (coord.y > y) {
      y = coord.y;
    }
  }
  return Coordinate{x, y};
}

char AbstractBlock::getPiece() {
  return piece;
}

void AbstractBlock::left() {
  for (auto &coord : coords) {
    coord.x -= 1;
  }
}

void AbstractBlock::right() {
  for (auto &coord : coords) {
    coord.x += 1;
  }
}

void AbstractBlock::down() {
  for (auto &coord : coords) {
    coord.y += 1;
  }
}

void AbstractBlock::rotateCW() {
  Coordinate botLeft = getBotLeft(coords);
  vector<Coordinate> relatives;
  for (auto &coord : coords) {
    relatives.push_back(Coordinate{coord.x-botLeft.x, coord.y-botLeft.y});
  }
  for (auto &relative : relatives) {
    relative = Coordinate{relative.x * 0 + relative.y * - 1, relative.x * 1 + relative.y * 0};
  }
  for (int i = 0; i < 4; ++i) {
    coords[i].x = botLeft.x + relatives[i].x;
    coords[i].y = botLeft.y + relatives[i].y;
  }
  Coordinate newBotLeft = getBotLeft(coords);
  botLeft.x -= newBotLeft.x;
  botLeft.y -= newBotLeft.y;
  for (auto &coor : coords) {
    coor = Coordinate{coor.x + botLeft.x, coor.y + botLeft.y};
  }
}

void AbstractBlock::rotateCCW() {
  Coordinate botLeft = getBotLeft(coords);
  vector<Coordinate> relatives;
  for (auto &coord : coords) {
    relatives.push_back(Coordinate{coord.x-botLeft.x, coord.y-botLeft.y});
  }
  for (auto &relative : relatives) {
    relative = Coordinate{relative.x * 0 + relative.y * 1, relative.x * - 1 + relative.y * 0};
  }
  for (int i = 0; i < 4; ++i) {
    coords[i].x = botLeft.x + relatives[i].x;
    coords[i].y = botLeft.y + relatives[i].y;
  }
  Coordinate newBotLeft = getBotLeft(coords);
  botLeft.x -= newBotLeft.x;
  botLeft.y -= newBotLeft.y;
  for (auto &coor : coords) {
    coor = Coordinate{coor.x + botLeft.x, coor.y + botLeft.y};
  }
}  
  

AbstractBlock & AbstractBlock::operator=(const AbstractBlock &other) {
  piece = piece;
  level = level;
  coords = coords;
  return *this;
}

AbstractBlock::~AbstractBlock() {}
