/*
 * Hero.cpp
 *
 *  Created on: 2015年5月21日
 *      Author: lc4t
 */

#include <Hero.h>
#include <iostream>
#include "Bullet.h"
Hero::Hero()
{
	loadMyhero();
	this->hero.setPosition(sf::Vector2f(150, 480));
	this->hero.setTexture(this->myHero);
}


void Hero::loadMyhero()
{
	if (!this->myHero.loadFromFile(heroPath))
	{
		std::cout<<"Error to load heroImage"<<std::endl;
	}
}

sf::Sprite Hero::getHero()
{
	return this->hero;
}



int Hero::isOverBound(int offsetX)
{
	sf::Vector2f heroPosition = this->hero.getPosition();
	float heroPositionX = heroPosition.x;
	if ( heroPositionX + offsetX >= -41 && heroPositionX + offsetX <= 341)
	{
		return 1;	//yes can move
	}
	else
	{
		return 0;		// no no no you cannot move
	}

}

void Hero::moveLeft()
{
	if (isOverBound(-3))
	{
		this->hero.move(-3,0);
	}

}

void Hero::moveRight()
{
	if (isOverBound(3))
	{
		this->hero.move(3,0);
	}

}



std::vector<Bullet*> Hero::fire()

{
	return this->heroBullet;
}

void Hero::isFire()
{
	this->heroBullet.push_back(new Bullet(this->hero.getPosition()));
}




Hero::~Hero() {
	// TODO Auto-generated destructor stub
}

