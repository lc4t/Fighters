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
	this->needScore = 10;
	this->lastScore = -1;
	this->scoreText.setFont(font);
	this->scoreText.setColor(sf::Color::Black);
	this->scoreText.setCharacterSize(24);
	this->scoreText.setStyle(sf::Text::Bold);

	this->bloodText.setFont(font);
	this->bloodText.setColor(sf::Color::Red);
	this->bloodText.setCharacterSize(24);
	this->bloodText.setStyle(sf::Text::Bold);
	this->bloodText.setPosition(360,0);

	this->level = 1;
	this->currentLevel = -1;
	this->levelText.setFont(font);
	this->levelText.setColor(sf::Color::Blue);
	this->levelText.setCharacterSize(24);
	this->levelText.setStyle(sf::Text::Bold);
	this->levelText.setPosition(180,0);
}

sf::Text& Show::getScoreText()
{
	if (this->lastScore != this->score)
	{
		this->scoreText.setString("Score:" + int2string(this->score));
		this->lastScore = this->score;
	}

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

sf::Text& Show::getLevelText()
{
	if (this->level != this->currentLevel)
	{
		this->currentLevel = this->level;
		this->levelText.setString("Level  " + int2string(this->level));
	}
	return this->levelText;


}

void Show::levelUp()
{
	this->level ++;
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

