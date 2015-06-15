/*
 * Died.cpp
 *
 *  Created on: 2015年5月29日
 *      Author: lc4t
 */

#include <Died.h>


Died::Died()
{

}

Died::Died(std::vector<Enemy*> &enemies,std::vector<Bullet*> &bullets)
{
	for (std::vector<Enemy*>::iterator i = enemies.begin();i != enemies.end() && enemies.size() != 0;i++)
	{
		for (std::vector<Bullet*>::iterator j = bullets.begin();j != bullets.end() && bullets.size() != 0;j++)
		{
			if (isCrash((*i)->getPosition(), (*i)->getType(), (*j)->getPosition(), (*j)->getType()))
			{
				(*i)->beKilled();
				(*j)->beKilled();
				continue;
			}
		}
	}
}

Died::Died(Hero &hero, std::vector<Bullet*> &enemyBullets,Musics& music)
{

	for (std::vector<Bullet*>::iterator j = enemyBullets.begin();j != enemyBullets.end() && enemyBullets.size() != 0;j++)
	{
		if (isCrash(hero.getPosition(), hero.getType(), (*j)->getPosition(), (*j)->getType()))
		{
			music.heroBeKilledMusicPlay();
			hero.beKilled();
			(*j)->beKilled();
			continue;
		}
	}
}


Died::Died(Hero & hero,std::vector<Enemy*> &enemies,Musics& music)
{// 10 1

	for (std::vector<Enemy*>::iterator i = enemies.begin();i != enemies.end() && enemies.size() != 0;i++)
	{
		if (isCrashDown(hero.getPosition(), hero.getType(), (*i)->getPosition(), (*i)->getType()) == 1)
		{
			if ((*i)->isKilled == true)
			{
				continue;
			}
			music.heroBeKilledMusicPlay();
			(*i)->beKilled();
			hero.beKilled();

			continue;
		}
	}

}

bool Died::isCrash(sf::Vector2f object1, int object1Type, sf::Vector2f object2, int object2Type)
{						//Enemy && Bullet
		//判断在哪一支下面
	switch(object1Type)
	{
		case 1:	// enemy is 1
		{
			switch (object2Type)
			{
				case 1: 	//  1 is bullets
				{
					if (isCrashDown(object1, object1Type, object2, object2Type) == 1)
					{
						return true;
					}
				}
			}
			break;
		}
		case 10: // hero is 10
		{
			switch(object2Type)
			{
				case 2:	// enemy 's bullet
				{
					if (isCrashDown(object1, object1Type, object2, object2Type) == 1)
					{
						return 1;
					}
				}
			}
		}
	}
	return false;
}

int Died::isUpLine(sf::Vector2f linePoint1, sf::Vector2f linePoint2, sf::Vector2f testPoint)
{

	if (linePoint1.x > linePoint2.x)
	{
		swap(linePoint1,linePoint2);
	}
	// (y -y2)   (x -x2)
	// ------  - ------- = 0     ->>>>>line  在下方此式为正
	// (x1-x2)   (y1-y2)
	//warning 线段!
	if (testPoint.x < linePoint1.x || testPoint.x > linePoint2.x)
	{

		return NOT_IN_THIS_DOWN;
	}
	else if ((testPoint.y - linePoint2.y) / (linePoint1.x - linePoint2.x) - (testPoint.x - linePoint2.x) / (linePoint1.y - linePoint2.y) < 0
			&& (testPoint.y - linePoint2.y) / (linePoint1.x - linePoint2.x) - (testPoint.x - linePoint2.x) / (linePoint1.y - linePoint2.y) >= -0.1)
	{
		std::cout<<(testPoint.y - linePoint2.y) / (linePoint1.x - linePoint2.x) - (testPoint.x - linePoint2.x) / (linePoint1.y - linePoint2.y)<<std::endl;//someting wrong, should near
		return YES;
	}
	else
	{
		return NOT;
	}

}

void Died::swap(sf::Vector2f &v1, sf::Vector2f &v2)
{
	sf::Vector2f temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}

int Died::isCrashDown(sf::Vector2f object1, int object1Type, sf::Vector2f object2, int object2Type)
{
	switch(object1Type)
		{
			case 1:	// enemy is 1
			{
				switch (object2Type)
				{
					case 1: 	//  1 is bullets
					{
						if (object2.x >= object1.x- 0.001 &&
								object2.x <= object1.x + enemyPlane1Size.x - 0.001 &&
								object2.y <= object1.y + enemyPlane1Size.y - 0.01)
						{
							return 1;
						}
					}
				}
				break;
			}
			case 10: // hero is 10
			{
				switch(object2Type)
				{
					case 1://enemy
					{ // 右下角 	// object1 hero object 2 enemy
						if (object2.x + enemyPlane1Size.x >= object1.x- 0.001 &&
								object2.x + enemyPlane1Size.x <= object1.x + heroPlane1Size.x - 0.01 &&
								object2.y + enemyPlane1Size.y >= object1.y  - 0.01
														)
						{
							return 1;
						}// 左上角
						else if (object2.x >= object1.x- 0.001 &&
								object2.x  <= object1.x + heroPlane1Size.x - 0.01 &&
								object2.y  >= object1.y + heroPlane1Size.y - 0.01)
						{
							return 1;
						}
						break;
					}
					case 2:	// enemy 's bullet
					{
						if (object2.x >= object1.x- 0.001 &&
								object2.x <= object1.x + heroPlane1Size.x - 0.01 &&
								object2.y >= object1.y + enemyPlane1Size.y - 0.01
								)
						{
							return 1;
						}
					}
				}
			}
		}
	return -1;
}

Died::~Died() {
	// TODO Auto-generated destructor stub
}

