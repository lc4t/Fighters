/*
 * Bullet.h
 *
 *  Created on: 2015年5月21日
 *      Author: lc4t
 */

#ifndef INCLUDE_BULLET_H_
#define INCLUDE_BULLET_H_
#include "Object.h"
#include "config.h"
class Bullet:public Object{
public:
	sf::Texture heroBullet;
	sf::Sprite hero_bullet;
	bool isKilled;
	Bullet(sf::Vector2f heroPosition);
	sf::Sprite drawBullet();
	void bulletAutoMove();
	bool isShouldDelete();
	void beKilled();
	virtual ~Bullet();
};

#endif /* INCLUDE_BULLET_H_ */
