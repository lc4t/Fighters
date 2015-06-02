/*
 * Explode.cpp
 *
 *  Created on: 2015年6月2日
 *      Author: lc4t
 */

#include <Explode.h>

Explode::Explode()
{

}

void Explode::letExplode(std::vector<Enemy*>::iterator &i, int type)
{
	(*i)->decreaseExplodeTimes();
	(*i)->enemyPlanePosition = (*i)->enemyPlane.getPosition();


	if (!(*i)->enemy_plane.loadFromFile(enemyPlanePath1Attack2))
	{
		std::cout<<"not load enemyPlanePath1Attack2"<<std::endl;
	}
//	(*i)->enemyPlane((*i)->enemy_plane);
	(*i)->planeSetPosition((*i)->enemyPlane, (*i)->enemyPlanePosition);
//	std::cout<<"Boom!!!"<<std::endl;
}



Explode::~Explode() {
	// TODO Auto-generated destructor stub
}

