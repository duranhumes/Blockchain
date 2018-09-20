#include <cstdlib>
#include <iostream>
#include <string>

#include "Blockchain.h"

Blockchain::Blockchain()
{
    vChain.emplace_back(Block(0, "Genesis Block"));
    nDifficulty = 6;
}

void Blockchain::AddBlock(Block bNew)
{
    bNew.sPrevHash = GetLastBlock().sHash;
    bNew.MineBlock(nDifficulty);
    vChain.push_back(bNew);
}

Block Blockchain::GetLastBlock() const
{
    return vChain.back();
}
