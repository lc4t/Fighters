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
	sf::Texture enemy_plane;
	sf::Sprite enemyPlane;
	int type;
	bool isShouldDelete();
	sf::Sprite drawEnemy();
	sf::Vector2f getPosition();
	int getType();
	Enemy(double x,int type = 1);

	virtual ~Enemy();
};

#endif /* INCLUDE_ENEMY_H_ */
