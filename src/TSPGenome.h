
#ifndef TSP_GENOME_H
#define TSP_GENOME_H

#include "Cities.h"
#include "GA/PermutationGenome.h"

class TSPGenome : public practical::ga::PermutationGenome {
    public:
        double fitness() const{
            tsp::Cities cities = tsp::Cities::instance();
            int distance = 0;
            for(std::vector<practical::ga::IntGene>::const_iterator pointer = genes.begin(); pointer + 1 != genes.end(); pointer++) {
                distance += cities.distance(pointer->getValue(), (pointer + 1)->getValue());
            }
            distance += cities.distance((genes.end() - 1)->getValue(), genes.begin()->getValue());
            return 1 / (double) distance;
        }

        practical::ga::Genome* shallowCopy() const {
            return new TSPGenome();
        }
};

#endif