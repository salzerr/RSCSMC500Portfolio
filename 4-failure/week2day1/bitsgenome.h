#include "abstractgenome.h"
#include <algorithm>

class BitsGenome : public AbstractGenome<bool> {
    public:
    int ones() {
       return std::count(genome.begin(), genome.end(), 1);
    }
};