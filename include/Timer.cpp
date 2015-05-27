/*
 * Timer.cpp
 *
 *  Created on: 2015年5月27日
 *      Author: lc4t
 */

#include <Timer.h>

Timer::Timer() {
	// TODO Auto-generated constructor stub

	this->thisEnemyTime = this->enemyControlTimer.getElapsedTime();
}

Timer::~Timer() {
	// TODO Auto-generated destructor stub
}

