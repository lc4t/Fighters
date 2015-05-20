/*
 * Stage.cpp
 *
 *  Created on: 2015年5月20日
 *      Author: lc4t
 */

#include <Stage.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
Stage::Stage()
{
	this->window = new sf::RenderWindow(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), GAME_NAME);
}

Stage::~Stage()
{
	delete this->window;
}



sf::RenderWindow* Stage::getWindow()
{
	return window;
}
