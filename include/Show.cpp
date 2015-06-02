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
	this->scoreText.setFont(font);
	this->scoreText.setColor(sf::Color::Black);
	this->scoreText.setCharacterSize(24);
	this->scoreText.setStyle(sf::Text::Bold);
}

sf::Text& Show::getScoreText()
{
	this->scoreText.setString("Score:");
	return this->scoreText;
}

Show::~Show() {
	// TODO Auto-generated destructor stub
}

