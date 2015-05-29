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

	bool isShouldDelete();
	sf::Sprite drawEnemy();
	Enemy(double x);

	virtual ~Enemy();
};

#endif /* INCLUDE_ENEMY_H_ */
