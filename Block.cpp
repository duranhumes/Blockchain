#include <cstdlib>
#include <iostream>
#include <string>

#include "Block.h"
#include "SHA256.h"

Block::Block(uint32_t nIndexIn, const std::string &sDataIn) : nIndex(nIndexIn), sData(sDataIn)
{
    nNonce = 0;
    tTime = time(nullptr);

    sHash = CalculateHash();
}

void Block::MineBlock(uint32_t nDifficulty)
{
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    std::string str(cstr);

    while (sHash.substr(0, nDifficulty) != str)
    {
        nNonce++;
        sHash = CalculateHash();
    }

    std::cout << "Block mined: " << sHash << "\n";
}

inline std::string Block::CalculateHash() const
{
    std::stringstream ss;
    ss << nIndex << sPrevHash << tTime << sData << nNonce;

    return sha256(ss.str());
}
