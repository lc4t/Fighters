/*
 * Enemy.cpp
 *
 *  Created on: 2015年5月26日
 *      Author: lc4t
 */

#include <Enemy.h>

Enemy::Enemy(double x) {
	this->enemy_plane.loadFromFile(enemyPlanePath1);
	sf::Sprite enemyPlane(this->enemy_plane);
	this->enemyPlane = enemyPlane;
	sf::Vector2f enemyPlanePosition = sf::Vector2f(x,0);
	planeSetPosition(this->enemyPlane, enemyPlanePosition);
}



bool Enemy::isShouldDelete()
{

	if (this->enemyPlane.getPosition().y >= GAME_HEIGHT)
	{
		std::cout<<"Y:"<<enemyPlane.getPosition().y<<std::endl;
		return true;
	}
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

