#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "Block.h"

class Blockchain {
public:
    Blockchain();
    void AddBlock(Block bNew);

private:
    uint32_t nDifficulty;
    std::vector<Block> vChain;
    Block GetLastBlock() const;
};

#endif //BLOCKCHAIN_H
