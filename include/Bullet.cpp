/*
 * Bullet.cpp
 *
 *  Created on: 2015年5月21日
 *      Author: lc4t
 */

#include <Bullet.h>

Bullet::Bullet(float x, float y)
{
	this->bullet.setPosition(sf::Vector2f(x,y));
}


void bulletAutoMove()
{

}
Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

