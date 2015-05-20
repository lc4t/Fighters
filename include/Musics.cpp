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

void Musics::loadBGM()
{
	if (!backgroundMusic.openFromFile(bgmPath))
		 {
			std::cout<<"Error to load backgroundMusic"<<std::endl;
		 }
}

void Musics::backgroundMusicPlay()
{
	loadBGM();
	backgroundMusic.setLoop(true);	// 循环播放
	backgroundMusic.play();
}
Musics::~Musics() {
	// TODO Auto-generated destructor stub
}

