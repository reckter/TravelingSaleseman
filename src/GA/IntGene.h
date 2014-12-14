/*
 * IntGene.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 *
 *  Specialization of the Gene.h template class.
 *  We simply need it to represent a city index, therefore unsigned int is the value
 *  IntGeneMutator is empty, since we only mutate on the Genome level. It can be ignored.
 */

#ifndef INTGENE_H_
#define INTGENE_H_

#include "Gene.h"
#include "Util.h"
#include <limits>

namespace practical {
namespace ga {

struct IntGeneMutator {
	static inline void mutate(unsigned int& value) {
		// never called, so leave empty
	}
};

typedef Gene<unsigned int, IntGeneMutator> IntGene;

} /* namespace ga */
} /* namespace practical */

#endif /* INTGENE_H_ */
