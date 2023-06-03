#ifndef BITSPOP_H_
#define BITSPOP_H_

#include "BitsOrganism.h"

class BitsPop {

    std::vector<BitsOrganism *> pop;
    int popsize;

public:

    BitsPop(int n, int genomesize) {
        popsize = n;
        for (int i = 0; i < n; i++) {
            BitsOrganism* org = new BitsOrganism(genomesize);
            pop.push_back(org);
        }
    }

    void update(const std::vector<BitsOrganism*> & newpop) {
        pop = newpop;
    }

    std::vector<BitsOrganism*> getPop() {
        return pop;
    }

    double getMax() {
    double max = 0.0; 
    for (int i = 0; i < popsize; i++) {
        if (max < pop[i]->getScore()) {
            max = pop[i]->getScore();
        }
    }
    return max;
}

double getMean() {
    double sum = 0.0;
    for (int i = 0; i < popsize; i++) {
        sum += pop[i]->getScore();
    }
    double mean = sum / static_cast<double>(popsize);
    return mean;
}

    std::vector<BitsOrganism*> tournament_select(int tournsize) {
        std::vector<BitsOrganism*> new_popfinal;  
        for (int i=0; i<popsize; i++) {
        std::vector<BitsOrganism*> new_pop;
            for (int i=0; i<tournsize; i++) {
                int orgIndex = rand() % popsize; 
                new_pop.push_back(pop[orgIndex]);
                std::sort(new_pop.begin(), new_pop.end());
            }
          
        new_popfinal.push_back(new_pop.back());

    } 
    return new_popfinal;
    }

    std::vector<BitsOrganism*> roulette_select() {
        // your implementation
    }

};

#endif /*BITSPOP_H_*/