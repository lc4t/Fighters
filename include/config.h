#ifndef CONFIG_H
#define CONFIG_H
#include <string>

/***********global    ***********/

const int GAME_HEIGHT = 600;
const int GAME_WIDTH =	400;
const std::string GAME_NAME = "Fighters";

/***********resources ***********/

const std::string imageBasePath = "resources/image/";
const std::string soundBasePath = "resources/sound/";
const std::string fontBasePath = "resources/font/";

/***********image path***********/

const std::string bgiPath = imageBasePath + "background.png";
const std::string gameOverImagePath = imageBasePath + "gameover.png";
const std::string heroPath = imageBasePath + "hero.png";

/***********music path***********/

const std::string bgmPath = soundBasePath + "game_music.ogg";
const std::string gameOverMusicPath = soundBasePath + "game_over.ogg";

/***********font path ***********/

const std::string fontPath = fontBasePath + "STHeiti Light.ttc";



#endif//config file
