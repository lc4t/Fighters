#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
/***********global    ***********/

const int GAME_HEIGHT = 600;
const int GAME_WIDTH =	400;
const std::string GAME_NAME = "Fighters";
const int heroFireSpeed = 25;
const float enemyMoveSpeed1 = 0.5f;
const int EnemyAddSpeed = 700;
/***********resources ***********/

const std::string imageBasePath = "resources/image/";
const std::string soundBasePath = "resources/sound/";
const std::string fontBasePath = "resources/font/";

/***********image path***********/

const std::string bgiPath = imageBasePath + "background.png";
const std::string gameOverImagePath = imageBasePath + "gameover.png";
const std::string heroPath = imageBasePath + "hero.png";
const std::string bulletPath1 = imageBasePath + "heroBullet1.png";
const std::string enemyPlanePath1 = imageBasePath + "enemyPlane1.png";
const std::string enemyPlanePath1Attack2 = imageBasePath + "enemyPlane1Attack2.png";
const std::string enemyPlanePath2 = imageBasePath + "enemyPlane2.png";

/***********music path***********/

const std::string bgmPath = soundBasePath + "game_music.ogg";
const std::string gameOverMusicPath = soundBasePath + "game_over.ogg";
const std::string bulletShootSoundPath = soundBasePath + "bullet.ogg";
const std::string enemy1BeKilledSoundPath = soundBasePath + "enemy1_down.ogg";
const std::string enemy2BeKilledSoundPath = soundBasePath + "enemy2_down.ogg";
const std::string enemy3BeKilledSoundPath = soundBasePath + "enemy3_down.ogg";
/***********font path ***********/

const std::string fontPath = fontBasePath + "STHeiti Light.ttc";

/***********Crash config ********/

const sf::Vector2f heroBullet1Area = sf::Vector2f(8,20);			//子弹1区域
//////////////敌机1
const sf::Vector2f enemyPlane1CenterCrashPoint = sf::Vector2f(23,34);	//中心碰撞点
const sf::Vector2f enemyPlane1LeftCrashPoint = sf::Vector2f(0,13);	//左碰撞点
const sf::Vector2f enemyPlane1RightCrashPoint = sf::Vector2f(47,13);	//右碰撞点
/////////////


#endif//config file




/*
background -- gameover

heroReady -- hero -- heroAttack1 -- heroAttack2 -- heroAttack3
heroBullet1 -- heroBullet2 -- heroBullet3
enemyPlane1 -- enemyPlane1Attack1 -- enemyPlane1Attack2
enemyPlane2 --
enemyPlane3 --
enemyPlane4 -- enemyPlane4Attack1 -- enemyPlane4Attack2 -- enemyPlane4Attack3 -- enemyPlane4Attack4 --
boom1
boom2

explode

 */


