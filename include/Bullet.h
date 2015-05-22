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
	sf::Texture heroBullet;
	sf::Sprite hero_bullet;
	Bullet();
	Bullet(sf::Vector2f heroPosition);
	sf::Sprite drawBullet();
	void bulletAutoMove();
	virtual ~Bullet();
};

#endif /* INCLUDE_BULLET_H_ */
