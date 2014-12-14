/*
 * GASolution.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 */

#include "GASolution.h"
#include "Organism.h"
#include "Genome.h"
#include "Logger.h"
#include "Util.h"
#include <cmath>

namespace practical {
namespace ga {

GASolution::GASolution(Organism& organism) : organism(organism), iterations(100) {

}

GASolution::GASolution(Organism& organism, unsigned int iterations) : organism(organism), iterations(iterations) {

}

void GASolution::findBestSolution() {
	for (unsigned int generation_count = 1; generation_count <= iterations; ++generation_count) {
		LOG_MSG("At generation: " << generation_count << "/" << iterations);
		LOG_MSG("  Best Element: " << *organism.fittest() << " - " << organism.fitness());
		LOG_MSG("  Worst Element: " << *organism.worst() << " - " << organism.worst()->fitness());
		organism.generate();
	}
}

const Genome* GASolution::getBest() const {
	return organism.fittest();
}

GASolution::~GASolution() {
}

} /* namespace ga */
} /* namespace practical */
