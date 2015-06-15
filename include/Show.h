/*
 * Show.h
 *
 *  Created on: 2015年6月2日
 *      Author: lc4t
 */

#ifndef INCLUDE_SHOW_H_
#define INCLUDE_SHOW_H_
#include "config.h"
class Show {
public:
	sf::Font font;
	sf::Text scoreText;
	sf::Text bloodText;
	sf::Text levelText;
	int score;
	int lastScore;
	int needScore;
	int level;
	int currentLevel;
	Show();
	sf::Text& getScoreText();
	sf::Text& getBloodText(int blood);
	sf::Text& getLevelText();
	void levelUp();

	std::string int2string(int num);
	void socerAdder(int type);
	virtual ~Show();
};

#endif /* INCLUDE_SHOW_H_ */
