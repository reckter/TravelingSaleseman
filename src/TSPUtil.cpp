/*
 * TSPUtil.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: ahueck
 */

#include "TSPUtil.h"
#include "Cities.h"

#include "GA/Logger.h"

#include <iostream>
#include <fstream>

namespace tsp {

TSPUtil::TSPUtil() {

}

bool TSPUtil::load(const std::string& file) {
  std::ifstream  tsp_file;
  tsp_file.open (file.c_str());
  if(!tsp_file.good()) {
	  LOG_ERROR("Reading file '" << file << "' failed.");
	  return false;
  }
  double x = 0, y = 0;
  tsp::Cities& instance = tsp::Cities::instance();
  while(tsp_file >> x >> y) {
	  instance.addCity(x, y);
  }
  tsp_file.close();
  return true;
}

TSPUtil::~TSPUtil() {
}

} /* namespace tsp */
