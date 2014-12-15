
#include "GA/Organism.h"
#include "TSPGenome.h"
#include "Cities.h"

#include <algorithm>
#include <random>
#include "GA/Util.h"
#include "../../../../../Library/Developer/CommandLineTools/usr/include/c++/v1/vector"



class TSPOrganism : public practical::ga::Organism {

public:
    void init(unsigned int initial_size) {

        int genesSize = tsp::Cities::instance().getCities().size();
        std::vector<practical::ga::IntGene> genes;
        std::vector<practical::ga::IntGene> shuffleGene;

        for(int i = 0; i < genesSize; i++) {
            genes.push_back(practical::ga::IntGene(i));
        }

        for(int i = 0; i < initial_size; i++) {
            TSPGenome* genome = new TSPGenome();

            shuffleGene.clear();
            for(int j = 0; j < genesSize; j++) {
                int rand = practical::ga::util::randInt(genes.size());
                shuffleGene.push_back(genes[i]);
                genes.erase(genes.begin() + i);
            }

            genome->getGenes() = shuffleGene;
            this->genomes.push_back(genome);
            genes = shuffleGene;
            shuffleGene.clear();
        }
    }
};