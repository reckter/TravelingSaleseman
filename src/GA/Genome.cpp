/*
 * Genome.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 */

#include "Genome.h"
#include "Util.h"

namespace practical {
namespace ga {

Genome::Genome() :
		genes() {

}

Genome::Genome(const std::vector<IntGene>& genes) :
		genes(genes) {

}

Genome::Genome(const Genome& other) :
		genes(other.genes) {
}

const Genome& Genome::operator=(const Genome& rhs) {
	if (this != &rhs) {
		genes = rhs.genes;
	}
	return *this;
}

Genome* Genome::deepCopy() const {
	Genome* copy = shallowCopy();
	copy->genes = this->genes;
	return copy;
}

bool Genome::operator<(const Genome& rhs) const {
	return fitness() < rhs.fitness();
}

int Genome::duel(const Genome& opponent) const {
	const double fitness = this->fitness();
	const double opo_fitness = opponent.fitness();
	if (fitness > opo_fitness) {
		return 1;
	} else if (fitness < opo_fitness) {
		return -1;
	}
	return 0;
}

const std::vector<IntGene>& Genome::getGenes() const {
	return genes;
}

std::vector<IntGene>& Genome::getGenes() {
	return genes;
}

Genome::~Genome() {

}

std::ostream& operator<<(std::ostream& os, const Genome& genome) {
	os << "[";
	std::vector<practical::ga::IntGene>::const_iterator iter = genome.getGenes().begin();
	for (; iter < genome.getGenes().end() - 1; ++iter) {
		os << *iter << " ";
	}
	return os << *iter << "] " << 1.0 / genome.fitness();
}

}
}
