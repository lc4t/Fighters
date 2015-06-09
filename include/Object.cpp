/*
 * Object.cpp
 *
 *  Created on: 2015年5月21日
 *      Author: lc4t
 */

#include <Object.h>
#include "config.h"
Object::Object() {
	// TODO Auto-generated constructor stub

}

void Object::planeAutoMoveDown(sf::Sprite &plane)
{
	plane.move(0, enemyMoveSpeed1);	// round 1

}

void Object::planeSetPosition(sf::Sprite &plane, sf::Vector2f position)
{
	plane.setPosition(position);
}



Object::~Object() {
	// TODO Auto-generated destructor stub
}





