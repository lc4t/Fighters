/*
 * Stage.h
 *
 *  Created on: 2015年5月20日
 *      Author: lc4t
 */

#ifndef INCLUDE_STAGE_H_
#define INCLUDE_STAGE_H_

#include "config.h"
#include "Musics.h"
#include "BackgroundImage.h"
#include "Hero.h"
#include "Bullet.h"
#include <vector>
class Stage{
public:
	Stage();
	int heroBulletAdder;
	std::vector<Bullet*> bullets;
	BackgroundImage BGI;
	Musics backgroundMusic;
	Hero hero;

	void setBGI(BackgroundImage &BGI);
	void setHero(Hero &hero);

	sf::RenderWindow* window;
	sf::RenderWindow* getWindow();
	void heroControl();
	void draw();
	std::vector<Bullet*> bullet;
	virtual ~Stage();

};

#endif /* INCLUDE_STAGE_H_ */
