/*
 * BackgroundImage.cpp
 *
 *  Created on: 2015年5月20日
 *      Author: lc4t
 */

#include <BackgroundImage.h>
#include <iostream>
BackgroundImage::BackgroundImage()
{
}

sf::Sprite BackgroundImage::getBG()
{

	if (!this->background.loadFromFile(bgiPath))
	{
		std::cout<<"Error to load backgroundImage"<<std::endl;
	}
	sf::Sprite bg1(this->background);
	this->bg = bg1;
	return this->bg;
}


sf::Sprite BackgroundImage::getGameOver()
{
	if (!this->background.loadFromFile(gameOverImagePath))
	{
		std::cout<<"Error to load gameOverImage"<<std::endl;
	}
	sf::Sprite bg1(this->background);
	this->bg = bg1;
	return this->bg;
}

BackgroundImage::~BackgroundImage() {
	// TODO Auto-generated destructor stub
}

