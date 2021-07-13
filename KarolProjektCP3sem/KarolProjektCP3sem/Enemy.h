#pragma once
#include "Player.h"

/**Class that derives from Player. It creates the enemy, his city and army.*/
class Enemy : public Player
{

public:
	/*Constructor for new enemy*/
	Enemy(const Map &_map);
	/*Constructor for Enemy*/
	Enemy();
	/*Destructor for Enemy*/
	~Enemy();

	
};

