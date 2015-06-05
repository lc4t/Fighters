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
	int score;
	int lastScore;
	Show();
	sf::Text& getScoreText();
	std::string int2string(int num);
	void socerAdder(int type);
	virtual ~Show();
};

#endif /* INCLUDE_SHOW_H_ */
