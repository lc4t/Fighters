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
#include "Timer.h"
#include "Died.h"
#include "Explode.h"
#include "Show.h"
class Stage{
public:
	Stage();
	sf::RenderWindow* window;
	sf::RenderWindow* getWindow();
	//timer
	Timer timer;
	BackgroundImage BGI;
	Musics musics;
	Hero hero;
	std::vector<Bullet*> heroBullet;
	Show show;
	int heroBulletAdder;
	int needScore;
////////////////////////////////////////////////
	std::vector<Enemy*> enemies;	// 敌机
	std::vector<Bullet*> enemiesBullets;
	std::vector<Bullet*>& getEnemiesBullets();
	void enemyAdder();
	void drawEnemies();
///////////////////////////////////////////////

	void setBGI(BackgroundImage &BGI);
	void setHero(Hero &hero);
	void drawAddBullet();
	void addEnemy();
	void heroControl();
	void musicControl();
	void drawShow();			// score
	void drawEnemysBullets();	// enemy's bullets
	void draw();

	virtual ~Stage();

};

#endif /* INCLUDE_STAGE_H_ */
