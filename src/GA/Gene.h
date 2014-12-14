/*
 * Gene.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 *
 * Gene template class. Holds a single value. In this practical it is an unsigned int.
 * @ see IntGene.h
 */

#ifndef GENE_H_
#define GENE_H_

#include <iostream>

namespace practical {
namespace ga {

template <typename T, typename GenePolicy>
class Gene {
private:
	T value;

public:
	Gene();

	Gene(const T& value);

	/*
	* Mutate the value. Not used in the practical.
	*/
	void mutate();

	/*
	* Comparison operators used for sorting etc.
	*/
	bool operator <(const Gene& other) const;

	bool operator ==(const Gene& other) const;

	const T& getValue() const;

	T& getValue();

	virtual ~Gene();
};


template <typename T, typename GenePolicy>
Gene<T, GenePolicy>::Gene() :
		value(T()) {
}

template <typename T, typename GenePolicy>
Gene<T, GenePolicy>::Gene(const T& value) :
		value(value) {
}

template <typename T, typename GenePolicy>
void Gene<T, GenePolicy>::mutate() {
	GenePolicy::mutate(value);
}

template <typename T, typename GenePolicy>
bool Gene<T, GenePolicy>::operator <(const Gene& other) const {
	return value < other.value;
}

template <typename T, typename GenePolicy>
bool Gene<T, GenePolicy>::operator ==(const Gene& other) const {
	return value == other.value;
}

template <typename T, typename GenePolicy>
const T& Gene<T, GenePolicy>::getValue() const {
	return value;
}

template <typename T, typename GenePolicy>
T& Gene<T, GenePolicy>::getValue() {
	return value;
}

template <typename T, typename GenePolicy>
Gene<T, GenePolicy>::~Gene() {
}

template <typename T, typename GenePolicy>
std::ostream& operator<<(std::ostream& os, const Gene<T, GenePolicy>& gene) {
	return os << gene.getValue();
}


} /* namespace ga */
} /* namespace practical */

#endif /* GENE_H_ */
