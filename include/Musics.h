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
	sf::Music bulletShootSound;
	sf::Music enemy1BeKilledSound;
	sf::Music heroBeKilledSound;
	int backgroundMusicVolume;
	Musics();
	void backgroundMusicPlay();
	void backgroundMusicPause();
	void backgroundMusicStop();
	void backgroundMusicIncrease();
	void backgroundMusicDecrease();

	void playBulletShootSound();
	void playEnemyBeKilledSound();

	void stopSoundEffect();

	void heroBeKilledMusicPlay();
	virtual ~Musics();
};

#endif /* INCLUDE_MUSICS_H_ */
