/*
 * Hero.h
 *
 *  Created on: 2015年5月21日
 *      Author: lc4t
 */

#ifndef INCLUDE_HERO_H_
#define INCLUDE_HERO_H_
#include "Object.h"
#include "config.h"
#include "Bullet.h"
class Hero:public Object {
public:
	Hero();
	sf::Texture myHero;
	sf::Sprite hero;
	std::vector<Bullet*> heroBullet;
	int isOverBound(int offsetX);
	void loadMyhero();
	sf::Sprite getHero();		//返回 飞机
	void moveLeft();
	void moveRight();			//移动
	void isFire(std::vector<Bullet*> &heroBullet);
//	std::vector<Bullet*>& fire();
	void addHeroBullet();
	virtual ~Hero();
};

#endif /* INCLUDE_HERO_H_ */
