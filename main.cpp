#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Includes/Config.hpp"


using namespace std;
using namespace sf;


int main()
{
	//window load
	sf::RenderWindow window(sf::VideoMode(400, 600), "Fighters");

	// BGI load init
	sf::Texture background;
	if (!background.loadFromFile(bgiPath))
		{
			cout<<"Error to load background"<<endl;
		}
	sf::Sprite bg(background);
	// BGI load init end

	//BGM load
	sf::Music music;
	if (!music.openFromFile(bgmPath))
	    return EXIT_FAILURE;
	music.play();
	//BGM load end



    //font load
    sf::Font font;
    if (!font.loadFromFile("Resources/font/STHeiti Light.ttc"))
		{
			cout<<"Error load font"<<endl;
		}
    sf::Text text;
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);




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
        window.draw(text);		//font
        window.display();
    }

    return 0;
}
