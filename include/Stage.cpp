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
	this->musics.backgroundMusicPlay();
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

void Stage::heroControl()   // hero的控制
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->hero.moveLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->hero.moveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
			if (this->heroBulletAdder == 0)
			{
				musics.playBulletShootSound();
				hero.isFire(this->heroBullet);
				++this->heroBulletAdder %= heroFireSpeed;
			}
			else
			{
				++this->heroBulletAdder %= heroFireSpeed;
			}

	}
}

void Stage::musicControl()   // music
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
	{
		this->musics.backgroundMusicIncrease();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
	{
		this->musics.backgroundMusicDecrease();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
	{
		this->musics.backgroundMusicPause();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
	{
		this->musics.backgroundMusicStop();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10))
	{
		this->musics.stopSoundEffect();
	}

}

void Stage::drawAddBullet()	//hero 是否 打到 敌机 draw 子弹
{
//	std::vector<Bullet*> heroBullet = hero.fire();	//draw 子弹
	for (std::vector<Bullet*>::iterator i = this->heroBullet.begin() ;i != this->heroBullet.end() && this->heroBullet.size() != 0;)
	{
		if ((*i)->isShouldDelete(1))
		{
			i = heroBullet.erase(i);
		}
		else
		{
			this->getWindow()->draw((*i)->drawBullet());
			i++;
		}
	}
	std::vector<Bullet*>(this->heroBullet).swap(this->heroBullet);
}

void Stage::drawEnemies()   // draw 敌机 敌机被击毁检测 敌机fire
{
	for (std::vector<Enemy*>::iterator i = enemies.begin() ;i != enemies.end() && enemies.size() != 0;)
	{
		if ((*i)->getIsKilled() && (*i)->getExplodeTimes() > 0)
		{
			this->show.socerAdder(1);
			Explode explodeTemp;
			explodeTemp.letExplode(i,1);
			this->getWindow()->draw((*i)->drawEnemy());
			if ((*i)->getExplodeTimes() == 9)
			{
				musics.playEnemyBeKilledSound();
			}
			i++;
		}
		else if ((*i)->isShouldDelete())
		{
			i = enemies.erase(i);
		}
		else
		{
			this->getWindow()->draw((*i)->drawEnemy());
			if (random() % enemyFireSpeed == 0)
			{
				(*i)->enemyFire(this->enemiesBullets);
			}
			i++;
		}
	}
	std::vector<Enemy*>(enemies).swap(enemies);	//更新内存

}

void Stage::addEnemy()   // 自动增加敌机
{
	if (random() % EnemyAddSpeed ==0)
	{
		enemyAdder();
	}
}

void Stage::drawShow()   //分数
{

	this->getWindow()->draw(this->show.getScoreText());
	this->getWindow()->draw(this->show.getBloodText(this->hero.getBlood()));
}

void Stage::drawEnemysBullets()   // 敌机的子弹
{

	for (std::vector<Bullet*>::iterator i = this->enemiesBullets.begin() ;i != this->enemiesBullets.end() && this->enemiesBullets.size() != 0;)
	{
		if ((*i)->isShouldDelete(2))
		{
			i = this->enemiesBullets.erase(i);
		}
		else
		{
			this->getWindow()->draw((*i)->drawBullet());
			i++;
		}
	}
	std::vector<Bullet*>(this->enemiesBullets).swap(this->enemiesBullets);
}

std::vector<Bullet*>& Stage::getEnemiesBullets()
{
	return this->enemiesBullets;
}

void Stage::draw()
{

	sf::Event event;
	++this->heroBulletAdder %= heroFireSpeed;
	while (this->getWindow()->isOpen())
	{
		this->getWindow()->clear();
		if (this->hero.getBlood() > 0)
		{
//			this->getWindow()->clear();
			if (this->getWindow()->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					this->getWindow()->close();
					std::exit(0);
				}
			}
			heroControl();
			musicControl();
			{
//				this->getWindow()->clear();
				this->getWindow()->draw(this->BGI.getBG());	//加载背景图片
				this->getWindow()->draw(this->hero.getHero());	//飞机
			}
	//		std::vector<Bullet*> heroBullet = hero.fire();
			Died enemyDieTest(enemies,this->heroBullet);
			Died heroDieTest(this->hero, this->enemiesBullets);
			std::cout<<hero.getBlood()<<std::endl;
			drawAddBullet();
			addEnemy();
			drawShow();
			drawEnemies();
			drawEnemysBullets();


		}
		else
		{
			if (this->getWindow()->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					this->getWindow()->close();
					std::exit(0);
				}
			}
			this->getWindow()->draw(this->BGI.getGameOver());	//加载背景图片
		}
		this->getWindow()->display();
	}


}

void Stage::enemyAdder()
{

	this->enemies.push_back(new Enemy(random() % 330, 1));
}

sf::RenderWindow* Stage::getWindow()
{
	return window;
}
