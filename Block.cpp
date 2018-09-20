#include <cstdlib>
#include <iostream>
#include <string>

#include "Block.h"
#include "SHA256.h"

/**
	Init Block with new index and data
	since we use constant parameters and pass in the reference
	we need to init those parameters before the constructor runs
*/
Block::Block(uint32_t nIndexIn, const std::string &sDataIn) : nIndex(nIndexIn), sData(sDataIn)
{
    nNonce = 0;
    tTime = time(nullptr);

    sHash = CalculateHash();
}

/**
	Init MineBlock with nDifficulty (6) to result in a hash
	similar to '00000020b7c23836d17210d7461b738f0d1cf6ab58f12fba00c66d299062518a'
	PoW loops through potential hash matches at substring till bases case of hash substring that
	matches the difficulty
*/
void Block::MineBlock(uint32_t nDifficulty)
{
    char cString[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cString[i] = '0';
    }
    cString[nDifficulty] = '\0';

    std::string str(cString);

    while (sHash.substr(0, nDifficulty) != str) {
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
