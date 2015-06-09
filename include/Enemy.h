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
#include "Bullet.h"
class Enemy:public Object {
public:
	Enemy(double x,int type);
	sf::Texture enemy_plane;
	sf::Vector2f enemyPlanePosition;
//	sf::Texture enemy_attack;
	sf::Sprite enemyPlane;
	int type;
	bool isKilled;
	int explodeTimes;
	bool isShouldDelete();
	sf::Sprite drawEnemy();
	sf::Vector2f getPosition();
	void beKilled();
	bool getIsKilled();
	int getExplodeTimes();
	void decreaseExplodeTimes();
	int getType();

	std::vector<Bullet*> enemyBullet;
	std::vector<Bullet*>& getEnemyBullets();
	void enemyFire();




	virtual ~Enemy();
};

#endif /* INCLUDE_ENEMY_H_ */
