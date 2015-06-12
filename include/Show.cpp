/*
 * Show.cpp
 *
 *  Created on: 2015年6月2日
 *      Author: lc4t
 */

#include <Show.h>

Show::Show()
{
	if (!this->font.loadFromFile(fontPath))
	{
	    std::cout<<"Can't load font"<<std::endl;
	}
	this->score = 0;
	this->lastScore = this->score;
	this->scoreText.setFont(font);
	this->scoreText.setColor(sf::Color::Black);
	this->scoreText.setCharacterSize(24);
	this->scoreText.setStyle(sf::Text::Bold);

	this->bloodText.setFont(font);
	this->bloodText.setColor(sf::Color::Red);
	this->bloodText.setCharacterSize(24);
	this->bloodText.setStyle(sf::Text::Bold);
	this->bloodText.setPosition(300,0);
}

sf::Text& Show::getScoreText()
{
	if (this->lastScore == this->score)
	{
		return this->scoreText;
	}
	this->scoreText.setString("Score:" + int2string(this->score));
	this->lastScore = this->score;
	return this->scoreText;
}

sf::Text& Show::getBloodText(int blood)
{
	switch(blood)
	{
		case 3:
		{
			this->bloodText.setString("000");
			break;
		}
		case 2:
		{
			this->bloodText.setString("00");
			break;
		}
		case 1:
		{
			this->bloodText.setString("0");
			break;
		}
		default:
		{
			this->bloodText.setString("0");
		}
	}
	return this->bloodText;
}

void Show::socerAdder(int type)
{

	this->score += type;

}

std::string Show::int2string(int num)
{
	std::string s = "";
	std::string temp = "";
	int number = 0;
	if (num == 0)
	{
		s += "0";
	}
	else if(num > 0)
	{
		while(num > 0)
		{
			number = num % 10;
			num -= number;
			num /= 10;
			temp += ('0' + number);
		}
		for (int i = temp.length() - 1; i >= 0; i--)
		{
			s += temp[i];
		}
	}
	return s;

}

Show::~Show() {
	// TODO Auto-generated destructor stub
}

