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
#include "Enemy.h"
class Stage{
public:
	Stage();
	sf::RenderWindow* window;
	sf::RenderWindow* getWindow();
	//timer

	bool isTimeOut(float testTime);
	BackgroundImage BGI;
	Musics musics;
	Hero hero;
	int heroBulletAdder;
////////////////////////////////////////////////
	std::vector<Enemy*> enemies;	// 敌机
	void enemyAdder();
	void drawEnemies();
///////////////////////////////////////////////

	void setBGI(BackgroundImage &BGI);
	void setHero(Hero &hero);
	void drawAddBullet();
	void heroControl();
	void draw();

	virtual ~Stage();

};

#endif /* INCLUDE_STAGE_H_ */
