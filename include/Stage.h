/*
 * Stage.h
 *
 *  Created on: 2015年5月20日
 *      Author: lc4t
 */

#ifndef INCLUDE_STAGE_H_
#define INCLUDE_STAGE_H_

#include "config.h"

class Stage {
public:
	Stage();
	sf::RenderWindow* window;
	sf::RenderWindow* getWindow();
	virtual ~Stage();

};

#endif /* INCLUDE_STAGE_H_ */
