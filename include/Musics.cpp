/*
 * Musics.cpp
 *
 *  Created on: 2015年5月20日
 *      Author: lc4t
 */

#include <Musics.h>
#include <iostream>
Musics::Musics()
{

}

void Musics::backgroundMusicPlay()
{
	if (!backgroundMusic.openFromFile(bgmPath))
	 {
		std::cout<<"Error to load backgroundMusic"<<std::endl;
	 }
	backgroundMusic.setLoop(true);	// 循环播放
	backgroundMusic.play();
}

void Musics::playBulletShootSound()
{
	if (!bulletShootSound.openFromFile(bulletShootSoundPath))
	 {
		std::cout<<"Can't load bulletShootSound"<<std::endl;
	 }
	bulletShootSound.play();

}

Musics::~Musics()
{

}

