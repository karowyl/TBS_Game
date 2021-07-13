#pragma once
#include "Ranged.h"
/** Class that derives from Ranged. It has a special abilites for archer.*/
class Archer :
	public Ranged
{
public:
	/*Constructor for Archer*/
	Archer();
	/*Destructor for Archer*/
	~Archer();
	/*The method returns the unit type as the first character of the unit name*/ 
	char type_of_unit();
};

