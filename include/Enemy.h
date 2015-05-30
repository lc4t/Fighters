/*
 * Enemy.h
 *
 *  Created on: 2015年5月26日
 *      Author: lc4t
 */

#ifndef INCLUDE_ENEMY_H_
#define INCLUDE_ENEMY_H_
#include "Object.h"
#include "config.h"
class Enemy:public Object {
public:
	Enemy(double x,int type);
	sf::Texture enemy_plane;
	sf::Sprite enemyPlane;
	int type;
	bool isKilled;
	bool isShouldDelete();
	sf::Sprite drawEnemy();
	sf::Vector2f getPosition();
	void beKilled();
	int getType();


	virtual ~Enemy();
};

#endif /* INCLUDE_ENEMY_H_ */
