/*
 * Bullet.cpp
 *
 *  Created on: 2015年5月21日
 *      Author: lc4t
 */

#include <Bullet.h>

Bullet::Bullet(sf::Vector2f heroPosition, int type)
{
	this->type = type;
	switch (type)
	{
		case 1:
			this->heroBullet.loadFromFile(bulletPath);
		break;
	}
	heroPosition.x += 45;
	heroPosition.y -= 13;
	sf::Sprite hero_bullet(this->heroBullet);
	hero_bullet.setPosition(heroPosition);
	this->hero_bullet = hero_bullet;
	this->isKilled = false;

}


void Bullet::bulletAutoMove()
{
		hero_bullet.move(0,-5);
}


sf::Sprite Bullet::drawBullet()
{
	bulletAutoMove();
	return this->hero_bullet;
}

bool Bullet::isShouldDelete()
{
	if (this->hero_bullet.getPosition().y <= 0 || this->isKilled)
	{
		return true;
	}
	else
	{
		return false ;
	}
}

void Bullet::beKilled()
{
	this->isKilled = true;
}

int Bullet::getType()
{
	return this->type;
}

sf::Vector2f Bullet::getPosition()
{
	return this->hero_bullet.getPosition();
}


Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

