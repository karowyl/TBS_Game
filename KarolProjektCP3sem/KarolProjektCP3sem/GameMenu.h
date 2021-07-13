#pragma once
#include <string>
#include "Game.h"
/**This class creates the game*/
class GameMenu 
{
	Game* game;
public:
	/*Constructor for GameMenu*/
	GameMenu(std::string &map_file, std::string &save_file);
	/*Destructor for GameMenu*/
	~GameMenu();

};

