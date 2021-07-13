#pragma once
#include "Mele.h"
/** Class that derives from Mele. It has special abilites for sword.*/
class Sword :
	public Mele
{
public:
	/*Constructor for Sword*/
	Sword();
	/*Destructor for Sword*/
	~Sword();
	/*The method returns the unit type as the first character of the unit name*/
	char type_of_unit();
};

