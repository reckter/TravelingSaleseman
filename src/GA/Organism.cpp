/*
 * Organism.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 */

#include "Organism.h"
#include "Genome.h"
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iostream>
#include "Util.h"

class iterator;
namespace practical {
namespace ga {

bool Organism::GenomeCmp::operator()(const Genome* lhs, const Genome* rhs){
	return lhs->fitness() < rhs->fitness();
}

Organism::Organism() :
		genomes(), mutateAfterCrossover(true), sorted(false), duelChildren(true) {
}

Organism::Organism(unsigned int initial_size) :
		genomes(), mutateAfterCrossover(true), sorted(false), duelChildren(true) {
}

Organism::Organism(const Organism& other) :
		genomes(), mutateAfterCrossover(other.mutateAfterCrossover), sorted(other.sorted), duelChildren(other.duelChildren) {
	copyGenomes(other);
}

const Organism& Organism::operator=(const Organism& rhs) {
	if (this != &rhs) {
		this->genomes = rhs.genomes;
		this->mutateAfterCrossover = rhs.mutateAfterCrossover;
		copyGenomes(rhs);
	}
	return *this;
}

void Organism::generate() {
	const unsigned int genome_count = this->genomes.size();
	std::deque<Genome*> new_genomes;

	while(genome_count > new_genomes.size()){
		std::pair<Genome*, Genome*> parents = this->selectParents();
		std::pair<Genome*, Genome*> children = parents.first->crossover(*parents.second);

		if (mutateAfterCrossover && util::randInt(1000) < 100) {
			children.first->mutate();
			children.second->mutate();
		}
		if(new_genomes.size() + 2 > genome_count) {
			if(children.second->duel(*children.first) == 1) {
				new_genomes.push_back(children.second);
				delete children.first;
			} else {
				new_genomes.push_back(children.first);
				delete children.second;			
			}
		} else {
			new_genomes.push_back(children.first);
			new_genomes.push_back(children.second);
		}
	}

	std::sort(new_genomes.begin(), new_genomes.end(), GenomeCmp());

	// best of last generation is kept.
	const Genome& new_generation_worst = *new_genomes.front();
	if(fittest()->duel(new_generation_worst) == 1) {
		delete new_genomes.front();
		new_genomes.pop_front();
		new_genomes.insert( 
            std::upper_bound(new_genomes.begin(), new_genomes.end(), fittest(), GenomeCmp())
			, fittest()->deepCopy()
		);
	}

	clearGenomes();
	genomes.swap(new_genomes);
	sorted = true;
}

double Organism::fitness() const {
	return fittest()->fitness();
}

const Genome* Organism::fittest() const {
	return genomes.back();
}

const Genome* Organism::worst() const {
	return genomes.front();
}

std::pair<Genome*, Genome*> Organism::selectParents() {
	std::deque<Genome*> tempGenome;
	for(int i = 0; i < 6 && i < genomes.size(); i++) {
		tempGenome.push_front(getRandomGenome());
	}
	std::sort(tempGenome.begin(), tempGenome.end(), GenomeCmp());
	std::pair<Genome* , Genome*> ret;
	ret.first = *(tempGenome.begin());
	ret.second = *(tempGenome.begin()++);

	return ret;
}

Genome* Organism::getRandomGenome() {
	int rand = util::randInt((int) genomes.size());
	return *(genomes.begin() + rand);
}

void Organism::sort() {
	std::sort(genomes.begin(), genomes.end(), GenomeCmp());
	sorted = true;
}

void Organism::copyGenomes(const Organism& rhs) {
	std::deque<Genome*>::const_iterator iter = rhs.genomes.begin();
	for (; iter != rhs.genomes.end(); ++iter) {
		const Genome* original = *iter;
		this->genomes.push_back(original->deepCopy());
	}
}

const std::deque<Genome*>& Organism::getGenomes() const {
	return genomes;
}

void Organism::clearGenomes() {
	std::deque<Genome*>::iterator iter = genomes.begin();
	for (; iter != genomes.end(); ++iter) {
		delete *iter;
	}
	genomes.clear();
}

Organism::~Organism() {
	clearGenomes();
}

std::ostream& operator<<(std::ostream& os, const Organism& organism) {
    os << "<[";
    std::deque<practical::ga::Genome*>::const_iterator iter = organism.getGenomes().begin();
	for (; iter < organism.getGenomes().end() - 1; ++iter) {
		os << *(*iter) << " | ";
	}
	return os << *(*iter) << "]>";
}

} /* namespace ga */
} /* namespace practical */
