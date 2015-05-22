/*
 * Bullet.cpp
 *
 *  Created on: 2015年5月21日
 *      Author: lc4t
 */

#include <Bullet.h>

Bullet::Bullet(sf::Vector2f heroPosition)
{

	this->heroBullet.loadFromFile(bulletPath);
	heroPosition.x += 45;
	heroPosition.y -= 13;
	sf::Sprite hero_bullet(this->heroBullet);
	hero_bullet.setPosition(heroPosition);
	this->hero_bullet = hero_bullet;

}


void Bullet::bulletAutoMove()
{
//	while (this->hero_bullet.getPosition().y > 0)
//	{
		hero_bullet.move(0,-2);
//	}
}


sf::Sprite Bullet::drawBullet()
{
	bulletAutoMove();
	return this->hero_bullet;
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

