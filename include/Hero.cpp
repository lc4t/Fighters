/*
 * Hero.cpp
 *
 *  Created on: 2015年5月21日
 *      Author: lc4t
 */

#include <Hero.h>
#include <iostream>
Hero::Hero() {
	// TODO Auto-generated constructor stub
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
	std::cout<<"I am at X: "<<heroPositionX<<std::endl;
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
	if (isOverBound(-10))
	{
		this->hero.move(-10,0);
	}

}

void Hero::moveRight()
{
	if (isOverBound(10))
	{
		this->hero.move(10,0);
	}

}
void Hero::fire()
{

}

Hero::~Hero() {
	// TODO Auto-generated destructor stub
}

