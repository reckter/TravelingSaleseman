
#include "GA/Organism.h"
#include "TSPGenome.h"
#include "Cities.h"

#include <algorithm>
#include <random>
#include "GA/Util.h"



class TSPOrganism : public practical::ga::Organism {

public:
    void init(unsigned int initial_size) {


        int genesSize = tsp::Cities::instance().getCities().size();
        std::cout << genesSize << std::endl;
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
                shuffleGene.push_back(genes[rand]);
                genes.erase(genes.begin() + rand);
            }

            genome->getGenes() = shuffleGene;
            this->genomes.push_back(genome);
            genes = shuffleGene;
            shuffleGene.clear();
        }

        std::string delim("");
        for(std::deque<practical::ga::Genome*>::iterator i = this->genomes.begin(); i < this->genomes.end(); i++) {
            std::cout << "[";
            delim = "";
            for(std::vector<practical::ga::IntGene>::const_iterator j = (*i)->getGenes().begin(); j < (*i)->getGenes().end(); j++) {
                std::cout << delim << j->getValue();
                delim = ", ";
            }
            std::cout << "]" << std::endl;
        }
    }
};