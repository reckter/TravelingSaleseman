/*
 * Util.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <cstdlib>
#include <ctime>

namespace practical {
namespace ga {
namespace util {

/**
 * Call once before using randInt
 */
inline void initRand(unsigned int seed = std::time(0)) {
	std::srand(seed);
}

inline int randInt(int max, int min = 0) {
	// No care has been taken for uniformity...
	int rand_value = (rand() % (max - min)) + min;
	return rand_value;
}

}
}
}

#endif /* UTIL_H_ */
