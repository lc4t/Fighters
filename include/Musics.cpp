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
	this->backgroundMusicVolume = 100;
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

void Musics::backgroundMusicPause()
{
	backgroundMusic.pause();
}

void Musics::backgroundMusicStop()
{
	backgroundMusic.stop();
}

void Musics::backgroundMusicIncrease()
{
	if (this->backgroundMusicVolume + 1 >= 100)
	{
		this->backgroundMusicVolume = 100;
	}
	else
	{
		this->backgroundMusicVolume++;
	}
	backgroundMusic.setVolume((float)(this->backgroundMusicVolume));
}

void Musics::backgroundMusicDecrease()
{
	if (this->backgroundMusicVolume - 1 <= 0)
	{
		this->backgroundMusicVolume = 0;
	}
	else
	{
		this->backgroundMusicVolume--;
	}
	backgroundMusic.setVolume((float)(this->backgroundMusicVolume));
}








void Musics::playBulletShootSound()
{
	if (!bulletShootSound.openFromFile(bulletShootSoundPath))
	 {
		std::cout<<"Can't load bulletShootSound"<<std::endl;
	 }
	bulletShootSound.play();

}

void Musics::playEnemyBeKilledSound()
{
	if (!enemy1BeKilledSound.openFromFile(enemy1BeKilledSoundPath))
		 {
			std::cout<<"Can't load bulletShootSound"<<std::endl;
		 }
	enemy1BeKilledSound.play();
}

void Musics::stopSoundEffect()
{
	bulletShootSound.setVolume(0);
	enemy1BeKilledSound.setVolume(0);
}

Musics::~Musics()
{

}

