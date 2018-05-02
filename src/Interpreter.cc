#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <utility>
#include <stdexcept>
#include <vector>
#include <memory>
#include "Interpreter.h"
using namespace std;

Interpreter::Interpreter(Grid &grid, int level, int seed, string file, bool textOnly) :
                        g{grid}, level{level}, fileName{file}, textOnly{textOnly}, seed{seed} {
    if (level == 0) {
      random = false;
    }  else {
      random = true;
    }
    bg = make_shared<BlockGenerator>(level, seed, fileName, random);
    bg->update(level, fileName, random);
    blk = bg->getNext();
    if (bg->next().getPiece() == 'E') {
      noMore = true;
    }
    g.updateBlock(*blk);
    renderTop();
    g.render();
    renderBot();
    g.clear();
}

bool Interpreter::isIntersect(AbstractBlock *b) {
  bool intersect = false;
  for (auto &block : blockList) {
    for (auto &coordSet : block.getCoords()) {
      for (auto &coordCurrent : b->getCoords()) {
        if (coordSet.y == coordCurrent.y && coordSet.x == coordCurrent.x) {
          intersect = true;
        }
      }
    }
  }
  return intersect;
}

bool Interpreter::isOut(AbstractBlock *b) {
  bool out = false;
  for (auto &coord : b->getCoords()) {
    if (coord.x < 0 || coord.x > g.getWidth() - 1 || coord.y > g.getHeight() - 1) {
      out = true;
    }
  }
  return out;
}

void Interpreter::update(string in) {
    input = in;
    //g.updateBlock(*blk);
    execute(match());
    
    if (gameEnd && !noMore) {
        cout << "Game is over. Type 'restart' to play again!" << endl;
        return;
    } else {
        g.updateBlock(*blk);
        for(auto &block : blockList) {
            g.updateBlock(block);
        }
    }
    renderTop();
    g.render();
    renderBot();
    g.clear();
    multiplier = 1;
    isOver();
    if (gameEnd && noMore) {
      noMore = false;
      cout << "Game is over. Type 'restart' to play again!" << endl;
      return;
    }
}

string Interpreter::match() {
    int digitIndex = 0;
    int len = input.length();
    for (int i = 0; i < len; ++i) {
        if (isdigit(input[i])) {
            ++digitIndex;
        }
    }
    try {
        if (digitIndex != 0) {
            string digitHolder = input.substr(0, digitIndex);
            multiplier = stoi(digitHolder);
            input = input.substr(digitIndex);
        }
    } catch (...) {
        return "";
    }
    vector<string> temp;
    for (auto &command : commands) {
        if (command.find(input) == 0) {
            temp.push_back(command);
        }
    }

    if (temp.size() == 1) {
        return temp[0];
    }
    return "";
}

void Interpreter::execute(string command) {
    if (command == "left" && !gameEnd) {
        for (int i = 0; i < multiplier; ++i) {
          AbstractBlock temp = *blk;
          temp.left();
          if (!(isIntersect(&temp) || isOut(&temp))) {
            blk->setCoords(temp.getCoords());
          }
        }
        heavyDrop();
    } else if (command == "right" && !gameEnd) {
        for (int i = 0; i < multiplier; ++i) {
          AbstractBlock temp = *blk;
          temp.right();
          if (!(isIntersect(&temp) || isOut(&temp))) {
            blk->setCoords(temp.getCoords());
          }
        }
        heavyDrop();
    } else if (command == "down" && !gameEnd) {
        for (int i = 0; i < multiplier; ++i) {
          AbstractBlock temp = *blk;
          temp.down();
          if (!(isIntersect(&temp) || isOut(&temp))) {
            blk->setCoords(temp.getCoords());
          }
        }
        heavyDrop();
    } else if (command == "clockwise" && !gameEnd) {
        for (int i = 0; i < multiplier; ++i) {
          AbstractBlock temp = *blk;
          temp.rotateCW();
          if (!(isIntersect(&temp) || isOut(&temp))) {
            blk->setCoords(temp.getCoords());
          }
        }
        heavyDrop();
    } else if (command == "counterclockwise" && !gameEnd) {
        for (int i = 0; i < multiplier; ++i) {
          AbstractBlock temp = *blk;
          temp.rotateCCW();
          if (!(isIntersect(&temp) || isOut(&temp))) {
            blk->setCoords(temp.getCoords());
          }
        }
        heavyDrop();
    } else if (command == "drop" && !gameEnd) {
        for (int i = 0; i < multiplier; ++i) {
              while (true) {
                AbstractBlock temp = *blk;
                temp.down();
                if (!(isIntersect(&temp) || isOut(&temp))) {
                  blk->setCoords(temp.getCoords());
                } else {
                  break;
                }
              }
              blockList.push_back(*blk);
              for(auto &block : blockList) {
                  g.updateBlock(block);
              }
              
              if ((noClears + 1) % 5 == 0 && noClears >= 4 && g.delRows().size() == 0 && level == 4) {
                blk = bg->getBlock("K");
                while (true) {
                  AbstractBlock temp = *blk;
                  temp.down();
                  if (!(isIntersect(&temp) || isOut(&temp))) {
                    blk->setCoords(temp.getCoords());
                  } else {
                    break;
                  }
                }
                blockList.push_back(*blk);
                for(auto &block : blockList) {
                  g.updateBlock(block);
                }
              }
              blk = bg->getNext();
              delCells(g.delRows());
              g.clear();
              if (noMore) {
                gameEnd = true;
              } else if (bg->next().getPiece() == 'E') {
                noMore = true;
              }
        }   
    } else if (command == "levelup" && !gameEnd) {
        level += multiplier;
        if (level > 4) {
            level = 4;
        }
        if (level >= 1) {
          random = true;
        } else {
          random = false;
        }
        bg->update(level, fileName, random);
    } else if (command == "leveldown" && !gameEnd) {
        level -= multiplier;
        if (level < 0) {
            level = 0;
        }
        if (level >= 1) {
          random = true;
        } else {
          random = false;
        }
        bg->update(level, fileName, random);
    } else if (command == "norandom" && !gameEnd) {
        cin >> fileName;
        if (level == 3 || level == 4) {
          random = false;
        }
        bg->update(level, fileName, random);

    } else if (command == "random" && !gameEnd) {
        if (level == 3 || level == 4) {
          random = true;
        }
        bg->update(level, fileName, random);

    } else if (command == "sequence" && !gameEnd) {

    } else if (command == "restart") {
      gameEnd = false;
      int size =  blockList.size();
      for (int i = 0; i < size; ++i) {
        blockList.pop_back();
      }
      level = 0;
      score = 0;
      random = false;
      noClears = 0;
      multiplier = 1;
      noMore = false;
      bg->update(seed, fileName, random);
      blk = bg->reopen();
    } else if (command == "hint" && !gameEnd) {

    } else if (command == "I" && !gameEnd) {
        blk = bg->getBlock("I");
    } else if (command == "J" && !gameEnd) {
        blk = bg->getBlock("J");
    } else if (command == "L" && !gameEnd) {
        blk = bg->getBlock("L");
    } else if (command == "O" && !gameEnd) {
        blk = bg->getBlock("O");
    } else if (command == "S" && !gameEnd) { 
        blk = bg->getBlock("S");
    } else if (command == "Z" && !gameEnd) {
        blk = bg->getBlock("Z");
    } else if (command == "T" && !gameEnd) {
        blk = bg->getBlock("T");
    } else if (command == "done") {
        gameEnd = true;
    } else {
        
    }
}

void Interpreter::endTurn() {
  
}

bool Interpreter::isEnd() {
    return gameEnd;
}

void Interpreter::delCells(vector<int> rows) {
  int size = rows.size();
  if (size != 0 && level == 4) {
    noClears = 0;
  } else {
    noClears++;
  }
  
  for (int i = 0; i < size; ++i) {
    for (auto &block : blockList) {
      vector<Coordinate> newCoords;
        for (auto &coord : block.getCoords()) {
          if (coord.y != rows.at(i)) {
            newCoords.push_back(coord);
          }
        }
        block.setCoords(newCoords);
      }
  }
  
  for (int i = 0; i < size; ++i) {
    shiftDown(rows[i]);
  }
  
  if (size > 0) {
    score += (size + level) * (size + level);
  }
  
  vector<AbstractBlock> temp;
  for(auto &block : blockList) {
    if (block.getCoords().empty()) {
      score += (block.getLevel() + 1) * (block.getLevel() + 1);
    } else {
       temp.push_back(block);
    }
  }
  blockList.clear();
  blockList = temp;

  if (score > highScore) {
    highScore = score;
  }
  
}

void Interpreter::shiftDown(int row) {
  for(auto &block : blockList) {
    vector<Coordinate> newCoords;
    for (auto &coord : block.getCoords()) {
      if (coord.y < row) {
        newCoords.push_back(Coordinate{coord.x, coord.y + 1});
      } else {
        newCoords.push_back(Coordinate{coord.x, coord.y});
      }
    }
    block.setCoords(newCoords);
  }
}

void Interpreter::renderTop() {
  cout << "Level:      " << level << endl;
  cout << "Score:      " << score << endl;
  cout << "Hi Score:   " << highScore << endl;
  if(!(textOnly)){
      g.graphicstop(level,score,highScore);
  }
}

void Interpreter::renderBot() {
  cout << "Next: " << endl;
  if (bg->next().getPiece() != 'E') {
    bg->next().renderBlock();
    if(!(textOnly)){
      g.graphicsbot(bg->next());
    }
  }
  cout << endl;
}
  
void Interpreter::heavyDrop() {
  if (blk->getLevel() >= 3) {
    AbstractBlock temp = *blk;
    temp.down();
    if (!(isIntersect(&temp) || isOut(&temp))) {
      blk->setCoords(temp.getCoords());
    }
  }
}

void Interpreter::isOver() {
  AbstractBlock temp = bg->next();
  if (isIntersect(&temp)) {
    gameEnd = true;
    cout << "Game is over. Type 'restart' to play again!" << endl;
  } 
}

Interpreter::~Interpreter() {

}
