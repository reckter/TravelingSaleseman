

#include "Genome.h"

namespace practical {
    namespace ga {
        class PermutationGenome : public Genome {

            public:
                std::pair<Genome*, Genome*> crossover(const Genome& other) const {
                    int crossoverPoint = util::randInt(other.genes.size(), 0);

                    Genome* child1 = new Genome();
                    Genome* child2 = new Genome();

                    for(int i = 0; i < crossoverPoint; i++) {
                        child1->genes.push_back(this->genes[i]);
                        child2->genes.push_back(other.genes[i]);
                    }

                    for(int i = 0; i < other.genes.size(); i++) {
                        bool contains = false;
                        for(int j = 0; j < child1->genes.size(); j++) {
                            if(child1->genes[j].getValue() == other.genes[i].getValue()) {
                                contains = true;
                                break;
                            }
                        }
                        if(!contains) {
                            child1->genes.push_back(other.genes[i]);
                        }
                    }

                    for(int i = 0; i < this->genes.size(); i++) {
                        bool contains = false;
                        for(int j = 0; j < child2->genes.size(); j++) {
                            if(child2->genes[j].getValue() == this->genes[i].getValue()) {
                                contains = true;
                                break;
                            }
                        }
                        if(!contains) {
                            child2->genes.push_back(this->genes[i]);
                        }
                    }

                    std::pair<Genome*, Genome*> ret;
                    ret.first = child1;
                    ret.second = child2;

                    return ret;
                }

        };
    }
}
