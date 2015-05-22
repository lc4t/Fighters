/*
 * Bullet.h
 *
 *  Created on: 2015年5月21日
 *      Author: lc4t
 */

#ifndef INCLUDE_BULLET_H_
#define INCLUDE_BULLET_H_
#include "Object.h"
class Bullet:public Object{
public:
	sf::Sprite bullet;
	Bullet();
	Bullet(float x, float y);
	void bulletAutoMove();
	virtual ~Bullet();
};

#endif /* INCLUDE_BULLET_H_ */
