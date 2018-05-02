#include <vector>
#include <iostream>
#include "Grid.h"
using namespace std;

Grid::Grid(bool textOnly) {
  grid.clear();
  grid.resize(height);

  for (int i = 0; i < height; ++i) {

    for (int j = 0; j < width; ++j) {
      
      grid.at(i).emplace_back(Cell());
      grid.at(i).at(j).setCoord(Coordinate{i, j});
    }
  }
  if(!(textOnly)){
      graph = make_shared<Graphics>();
  }
}

void Grid::render() {
  cout << "-----------" << endl;
  
  for (int h = 0; h < height; ++h) {
    for (int c = 0; c < width; ++c) {
      grid[h][c].textRender();
      if(graph){graph->notify(grid[h][c]);}
    }

    cout << endl;
  }

  cout << "-----------" << endl;
}

void Grid::clear() {
    for (int h = 0; h < height; ++h) {
        for (int c = 0; c < width; ++c) {
          grid[h][c].setPiece(' ');
        }
    }
}

void Grid::updateBlock(AbstractBlock &b) {
  for (auto &coord : b.getCoords()) {
    grid[coord.y][coord.x].setPiece(b.getPiece());
  }
}

int Grid::getWidth() {
  return width;
}

int Grid::getHeight() {
  return height;
}

vector<int> Grid::delRows() {
  vector<int> v;
  for (int i = 3; i < height; ++i) {
    bool toClear = true;

    for (int j = 0; j < width; ++j) {
      if (grid.at(i).at(j).getPiece() == ' ') {
        toClear = false;
        break;
      }
    }
    if (toClear) {
      v.push_back(i);
    }
  }
  return v;
}

void Grid::graphicstop(int level, int score, int highscore){
    graph->notifytop(level,score,highscore);
}

void Grid::graphicsbot(AbstractBlock b){
    graph->notifybot(b.getPiece());
}


Grid::~Grid() {
  /*for (int i = 0; i < height; ++i) {
    delete[] grid[i];
  }

  delete[] grid;*/
}
