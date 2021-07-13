#pragma once
#include "Unit.h"
/**Class that derives from Unit. It has special abilites for cavalry. */
class Cavalry :
	public Unit
{
public:
	/*Constructor for Cavalry*/
	Cavalry();
	/*Destructor for Cavalry*/
	~Cavalry();
	/*The method returns the unit type as the first character of the unit name*/
	char type_of_unit();
	/*The metods calculates and returns the power of unit*/
	int battle_value();
};

