#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <utility>
#include <vector>
#include <memory>
#include <cstdlib>
#include "BG.h"
#include "ABlock.h"
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "TBlock.h"
#include "KBlock.h"
#include "EBlock.h"
using namespace std;


//blockgenerator.cc

BlockGenerator::BlockGenerator(int level, int s, string fileName, bool random) : level{level}, file{fileName}, random{random}, myFile{fileName} {
    srand (s);
    nextBlock = makeBlock();
};

bool BlockGenerator::isRandom() {
    return random;
}

void BlockGenerator::setRandom(bool state) {
    random = state;
}

AbstractBlock BlockGenerator::next() {
    return *nextBlock;
}

shared_ptr<AbstractBlock> BlockGenerator::getNext() {
    shared_ptr<AbstractBlock> temp = nextBlock;
    nextBlock = makeBlock();
    return temp;
}

shared_ptr<AbstractBlock> BlockGenerator::makeBlock() {
    if (!random) {
      string input;
      
      if (!(myFile.eof())) {
        myFile >> input;
      } else {
        return make_shared<EmptyBlock>(level);
      }
        
      if (input == "S") {
        return make_shared<SBlock>(level);
      } else if (input == "Z") {
        return make_shared<ZBlock>(level);
      }  else if (input == "I") {
        return make_shared<IBlock>(level);
      } else if (input == "J") {
        return make_shared<JBlock>(level);
      } else if (input == "L") {
        return make_shared<LBlock>(level);
      } else if (input == "O") {
        return make_shared<OBlock>(level);
      } else if (input == "T") {
        return make_shared<TBlock>(level);
      } else {
        return make_shared<EmptyBlock>(level);
      }
        
    } else if (level == 1){
        int r = rand()%12; 
        if(r == 0){
            return make_shared<SBlock>(level);
        } else if (r == 1){
            return make_shared<ZBlock>(level);
        } else if ((r == 2) || (r == 3)) {
            return make_shared<IBlock>(level);
        } else if ((r == 4) || (r == 5)) {
            return make_shared<JBlock>(level);
        } else if ((r == 6) || (r == 7)) {
            return make_shared<LBlock>(level);
        } else if ((r == 8) || (r == 9)) {
            return make_shared<OBlock>(level);
        } else if ((r == 10) || (r == 11)) {
            return make_shared<TBlock>(level);
        }
    } else if (level == 2) {
        int r = rand()%6;
        if(r == 0){
            return make_shared<SBlock>(level);
        } else if (r == 1) {
            return make_shared<ZBlock>(level);
        } else if (r == 2) {
            return make_shared<IBlock>(level);
        } else if (r == 3) {
            return make_shared<JBlock>(level);
        } else if (r == 4) {
            return make_shared<LBlock>(level);
        } else if (r == 5) {
            return make_shared<OBlock>(level);
        } else if (r == 6) {
            return make_shared<TBlock>(level);
        }
    } else if (level >= 3) {
        int r = rand()%8;
        if((r == 0) || (r == 1)) {
            return make_shared<SBlock>(level);
        } else if ((r == 2) || (r == 3)) {
            return make_shared<ZBlock>(level);
        } else if (r == 4) {
            return make_shared<IBlock>(level);
        } else if (r == 5) {
            return make_shared<JBlock>(level);
        } else if (r == 6) {
            return make_shared<LBlock>(level);
        } else if (r == 7) {
            return make_shared<OBlock>(level);
        } else if (r == 8) {
            return make_shared<TBlock>(level);
        }
    } else {
    }
    return make_shared<EmptyBlock>(level);
}

shared_ptr<AbstractBlock> BlockGenerator::getBlock(string blk) {
  if (blk == "I") {
    return make_shared<IBlock>(level);
  } else if (blk == "J") {
    return make_shared<JBlock>(level);
  } else if (blk == "L") {
    return make_shared<LBlock>(level);
  } else if (blk == "O") {
    return make_shared<OBlock>(level);
  } else if (blk == "S") {
    return make_shared<SBlock>(level);
  } else if (blk == "Z") {
    return make_shared<ZBlock>(level);
  } else if (blk == "T") {
    return make_shared<TBlock>(level);
  } else {
    return make_shared<KBlock>(level);
  }
}
void BlockGenerator::update(int lv, string fl, bool isRand) {
    level = lv;
    if (isRand && file != fl) {
      myFile.open(fl);
    }
    file = fl;
    random = isRand;
}

shared_ptr<AbstractBlock> BlockGenerator::reopen() {
  myFile.clear();
  myFile.seekg(0, ios::beg);
  shared_ptr<AbstractBlock>temp = makeBlock();
  nextBlock = makeBlock();
  return temp;
}
