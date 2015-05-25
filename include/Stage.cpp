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
	this->backgroundMusic.backgroundMusicPlay();
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

void Stage::heroControl()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		std::cout<<"Left"<<std::endl;
		this->hero.moveLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		std::cout<<"Right"<<std::endl;
		this->hero.moveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
			std::cout<<"Fire!!"<<std::endl;
//			sf::sleep(sf::milliseconds(100));
			hero.isFire();
	}
}

void Stage::draw()
{
	sf::Event event;
	while (this->getWindow()->isOpen())
	{
		if (this->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->getWindow()->close();
				std::exit(0);
			}
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//			{
//				std::cout<<"Left"<<std::endl;
//				this->hero.moveLeft();
//			}
//			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
//			{
//				std::cout<<"Right"<<std::endl;
//				this->hero.moveRight();
//			}
//			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
//			{
//					std::cout<<"Fire!!"<<std::endl;
//					hero.isFire();
//			}

//			event.type = sf::Event::KeyReleased;
		}
		heroControl();
		{
			this->getWindow()->clear();
			this->getWindow()->draw(this->BGI.getBG());	//加载背景图片
			this->getWindow()->draw(this->hero.getHero());	//飞机
			std::queue<Bullet*> heroBullet = hero.fire();	//draw 子弹
//			int count = 0;
//			for (std::vector<Bullet*>::iterator i = heroBullet.begin();i != heroBullet.end(); i++)
//				{
//					if ((*i)->isShouldDelete())
//					{
//						heroBullet.erase(heroBullet.begin() + count);
//						continue;
//					}
//					std::cout<<"print bullet"<<std::endl;
//					this->getWindow()->draw((*i)->drawBullet());
//					count++;
//				}
//			if(!heroBullet.empty())
//			{
//				for (Bullet* i = heroBullet.front(); i != heroBullet.back() +1;i++)
//				{
//
//					std::cout<<"print bullet"<<std::endl;
//					this->getWindow()->draw((i)->drawBullet());
//
//				}
//			}
//
//		}
		this->getWindow()->display();
	}

}

sf::RenderWindow* Stage::getWindow()
{
	return window;
}
