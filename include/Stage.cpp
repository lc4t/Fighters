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
	this->heroBulletAdder = 0;
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
			if (this->heroBulletAdder == 0)
			{
				std::cout<<"Fire!!"<<std::endl;
				hero.isFire();
				++this->heroBulletAdder %= heroFireSpeed;
			}
			else
			{
				++this->heroBulletAdder %= heroFireSpeed;
			}

	}
}

void Stage::draw()
{
	sf::Event event;
	++this->heroBulletAdder %= heroFireSpeed;
	while (this->getWindow()->isOpen())
	{

		if (this->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->getWindow()->close();
				std::exit(0);
			}

		}
		heroControl();
		{
			this->getWindow()->clear();
			this->getWindow()->draw(this->BGI.getBG());	//加载背景图片
			this->getWindow()->draw(this->hero.getHero());	//飞机
			std::vector<Bullet*> heroBullet = hero.fire();	//draw 子弹

			if (!heroBullet.empty())
			{
				std::vector<Bullet*>::iterator test = heroBullet.begin();
				if ((*test)->isShouldDelete())
				{
					heroBullet.erase(test);
//					continue;
				}
				for (std::vector<Bullet*>::iterator i = heroBullet.begin();i != heroBullet.end(); i++)
				{
					std::cout<<"print bullet"<<std::endl;
					this->getWindow()->draw((*i)->drawBullet());
				}

			}


//			for (std::vector<Bullet*>::iterator i = heroBullet.begin();i != heroBullet.end(); i++)
//				{
//					std::vector<Bullet*>::iterator test = heroBullet.begin();
//					if (heroBullet.empty())
//					{
//						break;
//					}
////					else  if ((*i)->isShouldDelete())
////					{
////						i = heroBullet.erase(i);
////					}
//					else
//					{
//						std::cout<<"print bullet"<<std::endl;
//						this->getWindow()->draw((*i)->drawBullet());
// 					}
//
//				}
		}

		this->getWindow()->display();
	}

}

sf::RenderWindow* Stage::getWindow()
{
	return window;
}
