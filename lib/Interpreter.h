#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include <vector>
#include <string>
#include <memory>
#include "ABlock.h"
#include "Grid.h"
#include "BG.h"

class Interpreter {
    const std::vector<std::string> commands {"left", "right", "down", "clockwise", "counterclockwise", 
                                  "drop", "levelup", "leveldown", "norandom", "random", 
                                  "sequence", "restart", "hint", "I", "J", "L", "O", "S", "Z", "T", "done"};
    std::string input;
    int multiplier = 1;
    Grid &g;
    std::shared_ptr<AbstractBlock> blk;
    std::vector<AbstractBlock> blockList;
    int level;
    int highScore = 0;
    int score = 0;
    int noClears = 0;
    std::shared_ptr<BlockGenerator> bg;
    bool gameEnd = false;
    std::string fileName;
    bool textOnly;
    bool random;
    bool noMore = false;
    int seed;
public:
    Interpreter(Grid &grid, int level, int seed, std::string file, bool textOnly);
    bool isIntersect(AbstractBlock *b);
    bool isOut(AbstractBlock *b);
    void update(std::string input);
    void heavyDrop();
    std::string match();
    void execute(std::string command);
    void endTurn();
    bool isEnd(); 
    void delCells(std::vector<int> rows);
    void shiftDown(int row);
    void renderTop();
    void renderBot();
    void isOver();
    ~Interpreter();
};
#endif
