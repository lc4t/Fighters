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
	Bullet(sf::Vector2f heroPosition,int type);
	sf::Texture heroBullet;
	sf::Sprite hero_bullet;
	int type;
	bool isKilled;

	sf::Sprite drawBullet();
	void bulletAutoMove();
	bool isShouldDelete(int type);
	int getType();
	void beKilled();
	bool getIsKilled();
	sf::Vector2f getPosition();
	virtual ~Bullet();
};

#endif /* INCLUDE_BULLET_H_ */
