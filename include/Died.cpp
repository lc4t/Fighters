/*
 * Died.cpp
 *
 *  Created on: 2015年5月29日
 *      Author: lc4t
 */

#include <Died.h>

Died::Died(std::vector<Enemy*> &enemies,std::vector<Bullet*> &bullets)
{
	std::vector<Enemy*>::iterator i = enemies.begin();
	std::vector<Bullet*>::iterator j = bullets.begin();
	while(i != enemies.end() && enemies.size() != 0 && j != bullets.end() && bullets.size() != 0)
	{
		// test kill someone

		i++;
		j++;
	}




}

Died::~Died() {
	// TODO Auto-generated destructor stub
}

