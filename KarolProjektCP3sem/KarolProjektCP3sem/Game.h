#pragma once
#include "Map.h"
#include "City.h"
#include "Army.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
/**Class Game starts the game, loads the map, created maps, enemy etc.*/
class Game
{
private:
	Map *map;
	Player *player;
	Enemy* enemy;

	int turn_counter;
	int max_number_of_turns;

public:
	/*Constructor for new game
	@param map_file path to file with map*/
	Game(std::string &map_file);
	/*Destructor for game*/
	~Game();
private:
	/*This method starts new game*/
	void new_game();
	/*This method exits from game*/
	void exit();
	/*This method checks who win the battle*/
	void battle();

	void end_turn();


};

