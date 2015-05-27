/*
 * Enemy.cpp
 *
 *  Created on: 2015年5月26日
 *      Author: lc4t
 */

#include <Enemy.h>

Enemy::Enemy() {
	this->enemy_plane.loadFromFile(enemyPlanePath1);
	sf::Sprite enemyPlane(this->enemy_plane);
//	enemyPlane.setPosition(heroPosition);
	this->enemyPlane = enemyPlane;

}

void Enemy::setEnemyPlanePosition()
{
	sf::Vector2f enemyPlanePosition = sf::Vector2f(0,0);
	planeSetPosition(this->enemyPlane, enemyPlanePosition);

}

bool Enemy::isShouldDelete()
{
	//TEST
	return false;
}

sf::Sprite Enemy::drawEnemy()
{
	planeAutoMoveDown(this->enemyPlane);
	return this->enemyPlane;
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

