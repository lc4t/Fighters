/*
 * Died.h
 *
 *  Created on: 2015年5月29日
 *      Author: lc4t
 */

#ifndef INCLUDE_DIED_H_
#define INCLUDE_DIED_H_
#include "config.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>
#define NOT_IN_THIS_DOWN 0x001
#define NOT 0x010
#define YES 0x100
class Died {
public:
	Died(std::vector<Enemy*> &enemies,std::vector<Bullet*> &bullets);
	bool isCrash(sf::Vector2f object1, int object1Type, sf::Vector2f object2, int object2Type);
	int isUpLine(sf::Vector2f linePoint1, sf::Vector2f linePoint2, sf::Vector2f testPoint);
	void swap(sf::Vector2f &v1, sf::Vector2f &v2);
	virtual ~Died();
};

#endif /* INCLUDE_DIED_H_ */
