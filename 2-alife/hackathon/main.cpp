
#include <iostream>
#include "BitsPop.h"
#include "BitsOrganism.h"

int main() {

    int popsize = 100;
    int genomesize = 1000;
    int n_generations = 100;

    BitsPop population(popsize, genomesize);

    for (int i = 0; i < n_generations; i++) {
       std::cout << "Generation " << i+1 << std::endl;

        // Selection
        std::vector<BitsOrganism*> newpop;
        int k = 10; // tournament size
        newpop = population.tournament_select(k);
        //newpop = population.roulette_select() 
        //newpop = population.getPop();

        // variation
        std::vector<BitsOrganism*> newpop2 = population.getPop();
        for (int i = 0; i < newpop2.size(); i++) {
            //org->point_mutate();
            BitsOrganism* org = newpop2[i];
            org->block_mutate(k); // if doing tourament selection
        }

        // heritability
        population.update(newpop);

        //int meanFitness = population.getMean(); // get & print out mean 
        // int maxFitness = population.getMax(); // get & print out max
        // std::cout << "Mean fitness: " << meanFitness << std::endl; 
        std::cout << "Max fitness: " << population.getMax() << std::endl;
        std::cout << "Mean fitness: " << population.getMean() << std::endl;


    }

}