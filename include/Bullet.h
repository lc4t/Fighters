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
	int type;
	bool isKilled;
	Bullet(sf::Vector2f heroPosition,int type = 1);
	sf::Sprite drawBullet();
	void bulletAutoMove();
	bool isShouldDelete();
	int getType();
	void beKilled();
	sf::Vector2f getPosition();
	virtual ~Bullet();
};

#endif /* INCLUDE_BULLET_H_ */
