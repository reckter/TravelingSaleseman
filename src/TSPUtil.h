/*
 * TSPUtil.h
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 *
 *  Read a file of x,y values per line. Interpredted as locations for a city.
 *  Makes use of Cities.h instance and fills it with the content of the file.
 */

#ifndef TSPUTIL_H_
#define TSPUTIL_H_

#include <string>

namespace tsp {

class TSPOrganism;

class TSPUtil {
public:
	TSPUtil();

    /*
    * Read from std::string& file
    */
	bool load(const std::string& file);

	virtual ~TSPUtil();
};

} /* namespace tsp */

#endif /* TSPUTIL_H_ */
