/*
 * backgroundImage.h
 *
 *  Created on: 2015年5月20日
 *      Author: lc4t
 */

#ifndef INCLUDE_BACKGROUNDIMAGE_H_
#define INCLUDE_BACKGROUNDIMAGE_H_
#include "config.h"
class BackgroundImage{
public:
	sf::Texture background;
	sf::Sprite bg;
	BackgroundImage();
	sf::Sprite getBG();
	virtual ~BackgroundImage();
};

#endif /* INCLUDE_BACKGROUNDIMAGE_H_ */
