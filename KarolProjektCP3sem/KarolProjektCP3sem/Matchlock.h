#pragma once
#include "Ranged.h"
/** Class that derives from Ranged. It has a special abilites for Matchlock.*/
class Matchlock :
	public Ranged
{
public:
	/*Constructor for Matchlock*/
	Matchlock();
	/*Destructor for Matchlock*/
	~Matchlock();
	/*The method returns the unit type as the first character of the unit name*/
	char type_of_unit();
};

