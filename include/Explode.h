/*
 * Explode.h
 *
 *  Created on: 2015年6月2日
 *      Author: lc4t
 */

#ifndef INCLUDE_EXPLODE_H_
#define INCLUDE_EXPLODE_H_

#include "Bullet.h"
#include "config.h"
#include "Enemy.h"
#include <vector>
class Explode {
public:
	Explode();
	void letExplode(std::vector<Enemy*>::iterator &i, int type);
	virtual ~Explode();
};

#endif /* INCLUDE_EXPLODE_H_ */
