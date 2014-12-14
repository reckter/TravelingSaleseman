/*
 * Cities.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 *
 *  Cities is a helper class for the TSP. It keeps track of all cities ((x,y)-coordinates) and calculates the distance between them.
 */

#ifndef CITIES_H_
#define CITIES_H_

#include <vector>

namespace tsp {

class Cities {
public:
	struct City {
		double x, y;
	};

	static Cities& instance() {
		static Cities INSTANCE_CITIES;
		return INSTANCE_CITIES;
	}

	void addCity(const City& c);

	void addCity(double x, double y);

	double distance(int city_start, int city_end) const;

	const std::vector<City>& getCities() const;

	virtual ~Cities();

private:
	Cities();
	std::vector<City> city_vec;
};

} /* namespace tsp */

#endif /* CITIES_H_ */

