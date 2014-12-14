

#include "Genome.h"

namespace practical {
    namespace ga {
        class PermutationGenome : public Genome {

            public:
                std::pair<Genome*, Genome*> crossover(const Genome& other) const {
                    int crossoverPoint = util::randInt(other.getGenes().size(), 0);

                    Genome* child1 = other.shallowCopy();
                    Genome* child2 = this->shallowCopy();

                    for(int i = 0; i < crossoverPoint; i++) {
                        child1->getGenes().push_back(this->getGenes()[i]);
                        child2->getGenes().push_back(other.getGenes()[i]);
                    }

                    for(int i = 0; i < other.getGenes().size(); i++) {
                        bool contains = false;
                        for(int j = 0; j < child1->getGenes().size(); j++) {
                            if(child1->getGenes()[j].getValue() == other.getGenes()[i].getValue()) {
                                contains = true;
                                break;
                            }
                        }
                        if(!contains) {
                            child1->getGenes().push_back(other.getGenes()[i]);
                        }
                    }

                    for(int i = 0; i < this->getGenes().size(); i++) {
                        bool contains = false;
                        for(int j = 0; j < child2->getGenes().size(); j++) {
                            if(child2->getGenes()[j].getValue() == this->getGenes()[i].getValue()) {
                                contains = true;
                                break;
                            }
                        }
                        if(!contains) {
                            child2->getGenes().push_back(this->getGenes()[i]);
                        }
                    }

                    std::pair<Genome*, Genome*> ret;
                    ret.first = child1;
                    ret.second = child2;

                    return ret;
                }

                void mutate() {
                    int a = util::randInt(this->genes.size(), 0);
                    int b = util::randInt(this->genes.size(), 0);

                    IntGene ig = this->genes[a];
                    this->genes[a] = this->genes[b];
                    this->genes[b] = ig;
                }

        };
    }
}
