
#include <Musics.h>
#include <iostream>
#include "Stage.h"
#include "BackgroundImage.h"
#include "Hero.h"

#include "config.h"



using namespace std;
using namespace sf;

//void timer(Stage *stage)
//{
//	//isplay
//	while(1)
//	{
//		stage->hero.addHeroBullet();
//		sf::sleep(sf::milliseconds(500));
//	}
//
//}

int main()
{

	Stage stage;
//    sf::Thread thredTimer(&timer, &stage);
//    thredTimer.launch();

//	Musics backgroundMusic;
//	backgroundMusic.backgroundMusicPlay();
	stage.draw();
    return 0;
}

