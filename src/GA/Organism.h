/*
 * Organism.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 *
 *  Organism is a pool of solutions for a problem. It has a vector of Genomes, which represent a single solution.
 *  Organism is responsible for the creation of a new generation (void generate();) of solutions by selecting parents (selectParents()) and creating children based on these selections.
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

#include <utility>
#include <deque>
#include <iostream>

namespace practical {
namespace ga {

class Genome;

class Organism {
protected:
	std::deque<Genome*> genomes;
	bool mutateAfterCrossover;
	bool sorted;
	bool duelChildren;
    struct GenomeCmp {
      bool operator()(const Genome* lhs, const Genome* rhs);
    };
public:

	Organism();

	Organism(unsigned int initial_size);

	/*
	* Copy constructor
	*/
	Organism(const Organism& other);

	/*
	* Copy assignment operator
	*/
	const Organism& operator=(const Organism& rhs);

	/*
	* Create a new generation by repreatedly selecting parents and applying a crossover on the selected Genomes until the generation size is reached.
	*/
	virtual void generate();

	/*
	* Fitness of the best Genome (solution) currently
	*/
	virtual double fitness() const;

	/*
	* Pointer to the best Genome (solution) currently
	*/
	virtual const Genome* fittest() const;

	/*
	* Pointer to the worst Genome (solution) currently
	*/
	virtual const Genome* worst() const;

	/*
	* Sort std::vector<Genome*> genomes. Fittest solution is in the beginning of the vector.
	*/
	virtual void sort();

	virtual const std::deque<Genome*>& getGenomes() const;

	virtual ~Organism();
protected:
	/*
	* Select a pair of parents for crossover
    * TODO: implemented by the students
	*/
	virtual std::pair<Genome*, Genome*> selectParents();

private:
	void copyGenomes(const Organism& rhs);

	void clearGenomes();

	/*
	 * gives back a random genome
	 */
	Genome* getRandomGenome();

};

/*
* Print Organism to console
*/
std::ostream& operator<<(std::ostream& os, const Organism& genome);

} /* namespace ga */
} /* namespace practical */

#endif /* ORGANISM_H_ */
