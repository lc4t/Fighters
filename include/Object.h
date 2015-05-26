/*
 * Object.h
 *
 *  Created on: 2015年5月21日
 *      Author: lc4t
 */

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_
#include "config.h"
//返回物体作为参数
class Object
{
public:
	Object();
	void planeAutoMoveDown(sf::Sprite &plane);
	void planeSetPosition(sf::Sprite &plane, sf::Vector2f position);
	virtual ~Object();
};

#endif /* INCLUDE_OBJECT_H_ */
