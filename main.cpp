#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "config.h"



using namespace std;
using namespace sf;


int main()
{
	/***********    window     **********/

	sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), GAME_NAME);

	/***********      END      **********/

	/***********    BGI load   **********/
	sf::Texture background;
	if (!background.loadFromFile(bgiPath))
		{
			cout<<"Error to load backgroundImage"<<endl;
		}
	sf::Sprite bg(background);
	/***********      END      **********/

	/***********    BGM load   **********/

	sf::Music music;
	if (!music.openFromFile(bgmPath))
	    {
			cout<<"Error to load backgroundMusic"<<endl;
	    }
	music.play();

	/***********      END      **********/

	/***********   font load   **********/
    sf::Font font;
    if (!font.loadFromFile(fontPath))
		{
			cout<<"Error load font"<<endl;
		}
    sf::Text text;
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    /***********      END      **********/


	/***********    HERO load  **********/
    sf::Texture herok;
    	if (!herok.loadFromFile(heroPath))
    		{
    			cout<<"Error to load heroImage"<<endl;
    		}
//    sf::Sprite Hero(herok);
    sf::Sprite hero;
    hero.setPosition(sf::Vector2f(150, 470));
    hero.setTexture(herok);


	/***********      END      **********/



    /***********   main run    **********/

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(bg);		//BGI
        window.draw(hero);		//hero
//        window.draw(text);		//font
        window.display();
    }

    return 0;
}
