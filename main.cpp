#include <cstdlib>
#include <iostream>
#include <string>

#include "Blockchain.h"

int main()
{
    Blockchain bChain = Blockchain();

    std::cout << "Mining block 1... \n";
    bChain.AddBlock(Block(1, "Block 1 Data"));

    std::cout << "Mining block 2... \n";
    bChain.AddBlock(Block(2, "Block 2 Data"));

    std::cout << "Mining block 3... \n";
    bChain.AddBlock(Block(3, "Block 3 Data"));

    return 0;
}

// g++ -std=c++11 main.cpp Block.cpp Blockchain.cpp SHA256.cpp && ./a.out
