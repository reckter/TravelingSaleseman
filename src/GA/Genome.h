/*
 * Genome.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 *
 *  Abstract base class Genome. Represents an individual (one possible solution of our problem) of our Organism.
 *  Offers fitness (eg. inverse of travel distance), mutation, corssover etc.
 *  Holds a vector of IntGene.h, which represent the city index.
 */

#ifndef GENOME_H_
#define GENOME_H_

#include "IntGene.h"

#include <vector>
#include <iostream>

namespace practical {
namespace ga {

class Genome {
protected:
	std::vector<IntGene> genes;

public:
	Genome();

	Genome(const std::vector<IntGene>& genes);

	/*
	* Copy constructor
	*/
	Genome(const Genome& other);

	/*
	* Copy assignment operator
	*/
	const Genome& operator=(const Genome& rhs);

	/*
	* Used for sorting a vector of Genomes (uses fitness value)
	*/
	bool operator<(const Genome& rhs) const;

	/*
	* Create children using crossover. To implement in sub class
	*/
	virtual std::pair<Genome*, Genome*> crossover(const Genome& other) const = 0;

	/*
	* Mutate this Genome. To implement in sub class
	*/
	virtual void mutate() = 0;

	/*
	* Calculate fitness based on some metric. To implement in sub class
	*/
	virtual double fitness() const = 0;

	/*
	* Make a shallow copy (everything but std::vector<IntGene> genes;). To implement in sub class
	*/
	virtual Genome* shallowCopy() const = 0;

	/*
	* Make a deep copy. Makes use of virtual Genome* shallowCopy()
	*/
	virtual Genome* deepCopy() const;

	/*
	* Duel other Genome based on fitness value.
	* return 1 if this fitness value > opponent
	* return 0 if this fitness value == opponent
	* return -1 if this fitness value < opponent
	*/
	virtual int duel(const Genome& opponent) const;

	virtual const std::vector<IntGene>& getGenes() const;

	virtual std::vector<IntGene>& getGenes();

	virtual ~Genome();
};

/*
* Print Genome to console
*/
std::ostream& operator<<(std::ostream& os, const Genome& genome);

} /* namespace ga */
} /* namespace practical */

#endif /* GENOME_H_ */
