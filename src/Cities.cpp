/*
 * Cities.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 */

#include "Cities.h"

#include <cmath>

namespace tsp {

Cities::Cities() {

}

void Cities::addCity(const City& c) {
	city_vec.push_back(c);
}

void Cities::addCity(double x, double y) {
	City c = {x,y};
	city_vec.push_back(c);
}

double Cities::distance(int city_start, int city_end) const {
	const City& start = city_vec[city_start];
	const City& end = city_vec[city_end];
	const double dx = start.x - end.x;
	const double dy = start.y - end.y;
	const double dist = std::sqrt(dx*dx + dy*dy);
	return dist;
}

const std::vector<Cities::City>& Cities::getCities() const {
	return city_vec;
}

Cities::~Cities() {
}

} /* namespace tsp */
