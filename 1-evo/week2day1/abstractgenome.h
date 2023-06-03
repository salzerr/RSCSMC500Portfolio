#include <vector>

template<class T>
class AbstractGenome {
    protected:
        std::vector<T> genome;
    
    public:
        AbstractGenome(int n) {
            genome.resize(n);
        }
        ~AbstractGenome(){};
        void fill(T x) {
            std::fill(genome.begin(), genome.end(), x);
        }
        std::vector<T> get() {
            return genome;
        }

        void set(std::vector<T> v) {
            genome = v;
        }
};
