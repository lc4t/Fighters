/*
 * Died.cpp
 *
 *  Created on: 2015年5月29日
 *      Author: lc4t
 */

#include <Died.h>

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
								object2.y < object1.y + enemyPlane1Size.y - 0.01)
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

