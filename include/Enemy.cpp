/*
 * Enemy.cpp
 *
 *  Created on: 2015年5月26日
 *      Author: lc4t
 */

#include <Enemy.h>

Enemy::Enemy(double x,int type)
{
	this->type = type;
	switch (type)
	{
		case 1:
			this->enemy_plane.loadFromFile(enemyPlanePath1);
			this->explodeTimes = 10;
		break;
	}
	sf::Sprite enemyPlane(this->enemy_plane);
	this->enemyPlane = enemyPlane;
	this->enemyPlanePosition = sf::Vector2f(x,0);
	planeSetPosition(this->enemyPlane, this->enemyPlanePosition);
	this->isKilled = false;

}



bool Enemy::isShouldDelete()
{
	if (this->enemyPlane.getPosition().y >= GAME_HEIGHT || this->isKilled)
	{
		return true;
	}
	else
	{
		return false;
	}
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

bool Enemy::getIsKilled()
{
	return this->isKilled;
}

int Enemy::getExplodeTimes()
{
	return this->explodeTimes;
}

void Enemy::decreaseExplodeTimes()
{
	this->explodeTimes--;
}

void Enemy::enemyFire(std::vector<Bullet*> &enemiesBullets)
{
	enemiesBullets.push_back(new Bullet(this->enemyPlane.getPosition(),2));
}

int Enemy::getType()
{
	return this->type;
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

