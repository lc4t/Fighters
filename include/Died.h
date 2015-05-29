/*
 * Died.h
 *
 *  Created on: 2015年5月29日
 *      Author: lc4t
 */

#ifndef INCLUDE_DIED_H_
#define INCLUDE_DIED_H_
#include "config.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>
class Died {
public:
	Died(std::vector<Enemy*> &enemies,std::vector<Bullet*> &bullets);
	virtual ~Died();
};

#endif /* INCLUDE_DIED_H_ */
