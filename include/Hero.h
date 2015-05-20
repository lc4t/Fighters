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
class Hero:public Object {
public:
	Hero();
	sf::Texture myHero;
	sf::Sprite hero;
	void loadMyhero();
	sf::Sprite getHero();		//返回 飞机

	virtual ~Hero();
};

#endif /* INCLUDE_HERO_H_ */
