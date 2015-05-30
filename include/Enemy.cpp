/*
 * Enemy.cpp
 *
 *  Created on: 2015年5月26日
 *      Author: lc4t
 */

#include <Enemy.h>

Enemy::Enemy(double x,int type) {
	this->type = type;
	switch (type)
	{
		case 1:this->enemy_plane.loadFromFile(enemyPlanePath1);
		break;
	}
	sf::Sprite enemyPlane(this->enemy_plane);
	this->enemyPlane = enemyPlane;
	sf::Vector2f enemyPlanePosition = sf::Vector2f(x,0);
	planeSetPosition(this->enemyPlane, enemyPlanePosition);
	this->isKilled = false;
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

sf::Vector2f Enemy::getPosition()
{
	return this->enemyPlane.getPosition();
}

void Enemy::beKilled()
{
	this->isKilled = true;
}

int Enemy::getType()
{
	return this->type;
}
Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

