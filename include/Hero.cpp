/*
 * Hero.cpp
 *
 *  Created on: 2015年5月21日
 *      Author: lc4t
 */

#include <Hero.h>
#include <iostream>
#include "Bullet.h"
Hero::Hero() {
	// TODO Auto-generated constructor stub
	loadMyhero();
	this->hero.setPosition(sf::Vector2f(150, 480));
	this->hero.setTexture(this->myHero);
//	heroBulletCount = 1;
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
//void Hero::fire(sf::RenderWindow* windows)
//{
//	this->heroBullet.push_back(new Bullet(this->hero.getPosition()));
//	for (std::vector<Bullet*>::iterator i = heroBullet.begin();i != heroBullet.end(); i++)
//	{
//		//window->draw(i.draw());
//		std::cout<<"print bullet"<<std::endl;
//		windows->draw((*i)->drawBullet());
//	}
//
//}

std::queue<Bullet*> Hero::fire()
{
//	this->heroBullet.push_back(new Bullet(this->hero.getPosition()));
	return this->heroBullet;
}

void Hero::isFire()
{
//	if (heroBulletCount > 0)
//	{
		this->heroBullet.push(new Bullet(this->hero.getPosition()));
//		heroBulletCount--;
//	}

}

//void Hero::addHeroBullet()
//{
//	heroBulletCount++;
//}


Hero::~Hero() {
	// TODO Auto-generated destructor stub
}

