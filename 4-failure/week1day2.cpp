class organism {
    int age = (rand() % 100);
    // https://www.simplilearn.com/tutorials/cpp-tutorial/random-number-generator-in-cpp
    string name = NULL;
    bool isAlive = true; 

    bool operator< (organism& temporganism){
    if (age < temporganism.age)
        return true;
    else 
        return false;
};

};

class population {
    vector<organism> popvec(20);
    for ( int i = 0; i < 20; i++ ) {
        popvec.push_back(organism);
    };
    sort(popvec.begin(), popvec.end());
};


// the code above is what our group got to in class, code below is the solution


#include <string> // want to use strings
#include <vector> // want to use vectors
#include <iostream> // want to be able to print text
#include <algorithm> // want to use math symbols like <

class Organism { // initializing public organism class
    public:
        int _age; // stores age as int 
        std::string _name; // stores name of organism as string 
        bool _isAlive; // and bool for whether organism is alive or not

        Organism() { // default constructor for organism class
            _age = 0; // set age to 0 and is alive to true
            _isAlive = true;
        }
        
        ~Organism(){}; // deconstructor for class

        void setAge(int age) { // create function to set the age of an organism to given age
            _age = age;
        }

        bool operator < (Organism const & org) { // this method overloads the < to compare age of two organism
            return _age < org._age; // returns true if age is <
        }

};

class Population { //initalize public population class
    public: 
        std::vector<Organism> pop; //this member variable is a vector of organisms
        int maxSize; // also include int for max population size

        Population() { // default constructor for population class
            maxSize = 10000; // set max size of population to 10,000
        }

        Population(int n) { // function to set max size of population to given size
            maxSize = n;
        }

        ~Population(){}; // deconstructor for population class
};

int main() { // main function
    Population population(20); // initalize population vector size to 20
    for (int i = 0; i < 20; i++) { // loop to put 20 organisms in vector
        Organism org; // create organism object
        org.setAge(std::rand() % 100); // set a random age for organism
        population.pop.push_back(org); // add organism to population
    }
    for (auto it : population.pop) { // print out ages in population vector
        std::cout << it._age << std::endl;
    }

    std::sort(population.pop.begin(), population.pop.end()); // sort vector by age in ascending order
    std::cout << "After sort " << std::endl; // print out ages after sort to show that it worked
    for (auto it : population.pop) {
        std::cout << it._age << std::endl;
    }
}
