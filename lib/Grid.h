#ifndef GRID_H
#define GRID_H
#include <vector>
#include <memory>
#include "Cell.h"
#include "graphics.h"

class Grid {
  std::vector<std::vector<Cell>> grid;
  const int width = 11;
  const int height = 18;
  std::shared_ptr<Graphics> graph = nullptr;
public:
  Grid(bool textOnly);
  void render();
  void clear();
  void updateBlock(AbstractBlock &b);
  int getWidth();
  int getHeight();
  std::vector<int> delRows();
  void graphicstop(int level, int score, int highscore);
  void graphicsbot(AbstractBlock b);
  ~Grid();
};

#endif
