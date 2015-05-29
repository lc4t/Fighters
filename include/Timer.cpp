/*
 * Timer.cpp
 *
 *  Created on: 2015年5月27日
 *      Author: lc4t
 */

#include <Timer.h>

Timer::Timer() {
	// TODO Auto-generated constructor stub

//	this->thisEnemyTime = this->enemyControlTimer.getElapsedTime();
	this->startTime = time(NULL);
}

int Timer::getRunningTime()
{
//	return this->thisEnemyTime.asSeconds();
//	this->enemyControlTimer.restart();
	time_t nowTime;
	nowTime = time(NULL);
	return difftime(nowTime, this->startTime);
}

Timer::~Timer() {
	// TODO Auto-generated destructor stub
}

