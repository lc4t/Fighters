
#include <Musics.h>
#include <iostream>
#include "Stage.h"
#include "BackgroundImage.h"
#include "Hero.h"

#include "config.h"



using namespace std;
using namespace sf;


int main()
{
	/***********    window     **********/

	Stage stage;

	/***********      END      **********/
	/***********    BGI load   **********/

//	BackgroundImage BGI;

	/***********      END      **********/
	/***********    BGM load   **********/

	Musics backgroundMusic;
	backgroundMusic.backgroundMusicPlay();

	/***********      END      **********/
	/***********   font load   **********/

//    sf::Font font;
//    if (!font.loadFromFile(fontPath))
//		{
//			cout<<"Error load font"<<endl;
//		}
//    sf::Text text;
//    text.setFont(font);
//    text.setString("Hello world");
//    text.setCharacterSize(24);
//    text.setColor(sf::Color::Red);
//    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    /***********      END      **********/


	/***********    HERO load  **********/

//	Hero hero;

	/***********      END      **********/



    /***********   main run    **********/

//	while (stage.getWindow()->isOpen())
//	{
//		sf::Event event;
//		while (stage.getWindow()->pollEvent(event))
//		{
			stage.draw();
//			if (event.type == sf::Event::Closed)
//			{
//				stage.getWindow()->close();
//			}
//			if (event.key.code == sf::Keyboard::Left)
//			{
//				hero.moveLeft();
//			}
//			if (event.key.code == sf::Keyboard::Right)
//			{
//			    hero.moveRight();
//			}
//			if (event.key.code == sf::Keyboard::Right)
//			{
//				hero.fire();
//			}

//			stage.getWindow()->clear();
//			stage.getWindow()->draw(BGI.getBG());	//加载背景图片
//			stage.getWindow()->draw(hero.getHero());
//
//
//
//			stage.getWindow()->display();

//		}
	 //run
    return 0;
}//main
