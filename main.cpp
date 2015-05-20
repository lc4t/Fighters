
#include <Musics.h>
#include <iostream>
#include "Stage.h"
#include "BackgroundImage.h"
#include "config.h"



using namespace std;
using namespace sf;


int main()
{
	/***********    window     **********/

	Stage stage;

	/***********      END      **********/
	/***********    BGI load   **********/

	BackgroundImage BGI;

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

//    sf::Texture herok;
//    	if (!herok.loadFromFile(heroPath))
//    		{
//    			cout<<"Error to load heroImage"<<endl;
//    		}
////    sf::Sprite Hero(herok);
//    sf::Sprite hero;
//    hero.setPosition(sf::Vector2f(150, 470));
//    hero.setTexture(herok);


	/***********      END      **********/



    /***********   main run    **********/

//    while (stage.getWindow->isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(bg);		//BGI
//        window.draw(hero);		//hero
////        window.draw(text);		//font
//        window.display();
//    }

	while (stage.getWindow()->isOpen())
	{
		sf::Event event;
		while (stage.getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				stage.getWindow()->close();
			}

		stage.getWindow()->clear();
		stage.getWindow()->draw(BGI.getBG());	//加载背景图片

		stage.getWindow()->display();

		}
	}
    return 0;
}
