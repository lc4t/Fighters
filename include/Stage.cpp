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


//void Stage::isTimeOut(float testTime)
//{
//	this->enemyControlTimer.restart();
//	std::cout <<this->thisEnemyTime.asSeconds()<< std::endl;
//}

void Stage::heroControl()
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
				hero.isFire();
				++this->heroBulletAdder %= heroFireSpeed;
			}
			else
			{
				++this->heroBulletAdder %= heroFireSpeed;
			}

	}
}

void Stage::musicControl()
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

void Stage::drawAddBullet()
{
	std::vector<Bullet*> heroBullet = hero.fire();	//draw 子弹
	for (std::vector<Bullet*>::iterator i = heroBullet.begin() ;i != heroBullet.end() && heroBullet.size() != 0;)
	{
		if ((*i)->isShouldDelete())
		{
			i = heroBullet.erase(i);
		}
		else
		{
			this->getWindow()->draw((*i)->drawBullet());
			i++;
		}
	}
	std::vector<Bullet*>(heroBullet).swap(heroBullet);
}

void Stage::drawEnemies()
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
				(*i)->enemyFire();
			}
			i++;
		}
	}
	std::vector<Enemy*>(enemies).swap(enemies);	//更新内存

}

void Stage::addEnemy()
{
	if (random() % EnemyAddSpeed ==0)
	{
		std::cout<<"Add an Enemy"<<std::endl;
		enemyAdder();
	}
}

void Stage::drawShow()
{

	this->getWindow()->draw(this->show.getScoreText());
}

void Stage::drawEnemysBullets()
{
	for (std::vector<Enemy*>::iterator i = enemies.begin() ;i != enemies.end() && enemies.size() != 0;)
	{
		std::vector<Bullet*> bullets = (*i)->getEnemyBullets();
		for (std::vector<Bullet*>::iterator j = bullets.begin() ;j != bullets.end() && bullets.size() != 0;)
		{
			this->getWindow()->draw((*j)->drawBullet());
			j++;
		}
		i++;
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
		musicControl();
		{
			this->getWindow()->clear();
			this->getWindow()->draw(this->BGI.getBG());	//加载背景图片
			this->getWindow()->draw(this->hero.getHero());	//飞机
		}
		std::vector<Bullet*> heroBullet = hero.fire();
		Died dieTest(enemies,heroBullet);

		drawAddBullet();
		addEnemy();
		drawShow();
		drawEnemies();
		drawEnemysBullets();
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
