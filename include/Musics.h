/*
 * Musics.h
 *
 *  Created on: 2015年5月20日
 *      Author: lc4t
 */

#ifndef INCLUDE_MUSICS_H_
#define INCLUDE_MUSICS_H_
#include "config.h"
class Musics {
public:
	sf::Music backgroundMusic;
	Musics();
	void loadBGM();
	void backgroundMusicPlay();
	virtual ~Musics();
};

#endif /* INCLUDE_MUSICS_H_ */
