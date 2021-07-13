#pragma once
#include "Unit.h"
/*Class that derives from Unit.*/
class Ranged :
	public Unit
{
protected:
	int range; 
	int ammunition;
	int missile_damage;

public:
	/*Constructor for Ranged*/
	Ranged();
	/*Destructor for Ranged*/
	~Ranged();
	/*The metods calculates and returns the power of unit*/
	int battle_value();
};

