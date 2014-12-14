#include "Cities.h"
#include "GA/PermutationGenome.h"

class TSPGenome : public practical::ga::PermutationGenome {
    public:
        double fitness() const{
            tsp::Cities cities = tsp::Cities::instance();
            int distance = 0;
            for(std::iterator<IntGene> pointer = genes.begin(); pointer + 1 != genes.end(); pointer++) {
                distance += cities.distance(pointer, pointer + 1);
            }
            distance += cities.distance(genes.end(), genes.begin());
            return 1 / (double) distance;
        }

        Genome* shallowCopy(){
            return new TSPGenome();
        }
};