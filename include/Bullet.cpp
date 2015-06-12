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
		{
			this->heroBullet.loadFromFile(bulletPath1);
			heroPosition.x += 45;
			heroPosition.y -= 13;
			break;
		}
		case 2:
		{
			this->heroBullet.loadFromFile(bulletPath2);
			heroPosition.x += 21;
			heroPosition.y += 26;
			break;
		}
	}
	sf::Sprite hero_bullet(this->heroBullet);
	hero_bullet.setPosition(heroPosition);
	this->hero_bullet = hero_bullet;
	this->isKilled = false;

}

void Bullet::bulletAutoMove()
{
	switch(this->type)
	{
		case 1:
		{
			hero_bullet.move(0,heroBulletSpeed);
			break;
		}
		case 2:// enemy1's bullets
		{
			hero_bullet.move(0,enemyBulletSpeed);
		}
	}

}

sf::Sprite Bullet::drawBullet()
{
	bulletAutoMove();
	return this->hero_bullet;
}

bool Bullet::isShouldDelete(int type)
{
	switch(type)
	{
		case 1:	//飞机的子弹
		{
			if (this->hero_bullet.getPosition().y <= 0 || this->isKilled)
			{
				return true;
			}
			break;
		}
		case 2:
		{
			if (this->hero_bullet.getPosition().y >= 600 || this->isKilled)
			{
				return true;
			}
			break;
		}
	}
	return false;
}

void Bullet::beKilled()
{
	this->isKilled = true;
}

int Bullet::getType()
{
	return this->type;
}

bool Bullet::getIsKilled()
{
	return this->isKilled;
}

sf::Vector2f Bullet::getPosition()
{
	return this->hero_bullet.getPosition();
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

