/*
 * GASolution.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 * 
 *  Builds new generations (iterations is the total amount) and prints intermediate results to the console.
 *  Needs an instance of Organism in the constructor (and the amount of iterations)
 */

#ifndef GASOLUTION_H_
#define GASOLUTION_H_

namespace practical {
namespace ga {

class Organism;
class Genome;

class GASolution {
private:
	Organism& organism;
	unsigned int iterations;

public:
	GASolution(Organism& organism);

	GASolution(Organism& organism, unsigned int iterations);

	/*
	* Calculate best solution by building new generations using the organism variable
	*/
	virtual void findBestSolution();

	/*
	* Return best solution Genome calculated using the organism variable
	*/
	virtual const Genome* getBest() const;

	virtual ~GASolution();
};

} /* namespace ga */
} /* namespace practical */

#endif /* GASOLUTION_H_ */
