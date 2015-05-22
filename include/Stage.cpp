/*
 * Stage.cpp
 *
 *  Created on: 2015年5月20日
 *      Author: lc4t
 */

#include <Stage.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
Stage::Stage()
{
	this->window = new sf::RenderWindow(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), GAME_NAME);
}

Stage::~Stage()
{
	delete this->window;
}


void Stage::setBGI(BackgroundImage &BGI)
{
	this->BGI = BGI;
}

void Stage::setHero(Hero &hero)
{
	this->hero = hero;
}


void Stage::draw()
{
	sf::Event event;
	while (this->getWindow()->isOpen())
		{
		while (this->getWindow()->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					this->getWindow()->close();
				}
				if (event.key.code == sf::Keyboard::Left)
				{
					std::cout<<"Left"<<std::endl;
					this->hero.moveLeft();
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					std::cout<<"Right"<<std::endl;
					this->hero.moveRight();
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					std::cout<<"Fire!!"<<std::endl;
					this->hero.fire();
				}
				this->getWindow()->clear();
				this->getWindow()->draw(this->BGI.getBG());	//加载背景图片
				this->getWindow()->draw(this->hero.getHero());

				this->getWindow()->display();
			}
		}
}

sf::RenderWindow* Stage::getWindow()
{
	return window;
}
