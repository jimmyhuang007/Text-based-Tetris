#ifndef BG_H
#define BG_H
#include <vector>
#include <fstream>
#include <memory>
#include <string>
#include "ABlock.h"

//blockgenerator.h
class BlockGenerator {
    int level;
    std::string file;
    bool random;
    std::shared_ptr<AbstractBlock> nextBlock;
    std::ifstream myFile;
public:
    BlockGenerator(int level, int s, std::string fileName, bool random);
    bool isRandom();
    void setRandom(bool state);
    AbstractBlock next();
    std::shared_ptr<AbstractBlock> getNext();
    std::shared_ptr<AbstractBlock> makeBlock();
    std::shared_ptr<AbstractBlock> getBlock(std::string blk);
    void update(int lv, std::string fl, bool isRand);
    std::shared_ptr<AbstractBlock> reopen();
};

#endif
