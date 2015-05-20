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
	loadMyhero();
	this->hero.setPosition(sf::Vector2f(150, 470));
	this->hero.setTexture(this->myHero);
	return this->hero;
}

Hero::~Hero() {
	// TODO Auto-generated destructor stub
}

