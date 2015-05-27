/*
 * Timer.h
 *
 *  Created on: 2015年5月27日
 *      Author: lc4t
 */

#ifndef INCLUDE_TIMER_H_
#define INCLUDE_TIMER_H_

class Timer
{
public:
	Timer();
	sf::Clock enemyControlTimer;
	sf::Time thisEnemyTime = enemyControlTimer.getElapsedTime();
	virtual ~Timer();
};




#endif /* INCLUDE_TIMER_H_ */
