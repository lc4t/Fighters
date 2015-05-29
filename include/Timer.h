/*
 * Timer.h
 *
 *  Created on: 2015年5月27日
 *      Author: lc4t
 */

#ifndef INCLUDE_TIMER_H_
#define INCLUDE_TIMER_H_
#include "config.h"
#include <ctime>
class Timer
{
public:
	Timer();
	time_t startTime;
	int getRunningTime();
	virtual ~Timer();
};




#endif /* INCLUDE_TIMER_H_ */
