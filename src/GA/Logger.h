/*
 * Logger.h
 *
 *  Created on: May 9, 2014
 *      Author: ahueck
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>

// FIXME set at compile time...
#define LOG_LEVEL 1

#define LOG_LEVEL_MSG(LEVEL, MSG) if(LEVEL <= LOG_LEVEL) std::cout << "In '" << __func__  << "' (" << __LINE__ <<"): " << MSG << "\n"

#define LOG_DEBUG(MSG) LOG_LEVEL_MSG(3, MSG)
#define LOG_INFO(MSG) LOG_LEVEL_MSG(2, MSG)
#define LOG_ERROR(MSG) LOG_LEVEL_MSG(1, MSG)
#define LOG_FATAL(MSG) LOG_LEVEL_MSG(0, MSG)
#define LOG_MSG(MSG) std::cout << MSG << "\n"

#endif /* LOGGER_H_ */
