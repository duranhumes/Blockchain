#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

class Block {
public:
    std::string sHash;
    std::string sPrevHash;

    Block(uint32_t nIndexIn, const std::string &sDataIn);

    std::string GetData() { return this->sData; };

    void MineBlock(uint32_t nDifficulty);

private:
    uint32_t nIndex;
    uint32_t nNonce;
    std::string sData;
    time_t tTime;

    std::string CalculateHash() const;
};

#endif //BLOCK_H
