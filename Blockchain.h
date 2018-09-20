#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdint>
#include <iostream>
#include <vector>

#include "Block.h"

class Blockchain {
public:
    Blockchain();
    void AddBlock(Block bNew);

    // Return latest block data
	std::string display() {
		return GetLastBlock().GetData();
	}

private:
    uint32_t nDifficulty;
    std::vector<Block> vChain;
    Block GetLastBlock() const;
};

#endif //BLOCKCHAIN_H
