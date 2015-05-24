
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
	Stage stage;
	Musics backgroundMusic;
	backgroundMusic.backgroundMusicPlay();
	stage.draw();
    return 0;
}
