#include <iostream>
#include "abstractgenome.h"
#include <vector>

int main() {
    AbstractGenome<int> genome(20);
    genome.fill(4);
    for (auto i : genome.get()) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    AbstractGenome<char> genomechar(20);
    genomechar.fill('A');
    for (auto i : genomechar.get()) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    AbstractGenome<int> genomeset(10);
    std::vector<int> vec = {2, 3, 4, 5, 0, 2, 35, 3, 4, 2};
    genomeset.set(vec);
}