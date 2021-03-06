//============================================================================
// Name         	: Praktikum3.cpp
// Group members	:
// Description 		: Third practical of GdI3. Solve the travelling salesman problem using genetic algorithm.
//============================================================================

#include "TSPOrganism.h"
#include "TSPGenome.h"

#include "Cities.h"
#include "TSPUtil.h"
#include "GA/Util.h"
#include "GA/Genome.h"
#include "GA/GASolution.h"
#include "GA/Logger.h"

#include <cstdlib>


/*
* Call like: ./praktikum3 myfile.txt 2000
*/
int main(int argc, char** argv) {
    practical::ga::util::initRand();
    tsp::TSPUtil util;
    int ga_iterations = 5000;
    if(argc < 2) {
    	LOG_MSG("Need input file for cities.");
    	return -1;
    } else if(argc == 3) {
    	ga_iterations = atoi(argv[2]);
    }
    // file path as argument from command line
    util.load(argv[1]);
    const tsp::Cities& cities = tsp::Cities::instance();

    TSPOrganism organism;
    organism.init(1000);
    for(int generations = 0; generations <= ga_iterations; generations++) {
        organism.generate();
        if(generations % 10 == 0) {
            std::cout << "generation " << generations << ": ";
            std::cout << *(organism.fittest()) << std::endl;
        }
    }

    std::cout << *(organism.fittest()) << std::endl;

	return 0;
}



