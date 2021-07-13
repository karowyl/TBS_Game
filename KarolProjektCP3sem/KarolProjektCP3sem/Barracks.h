#pragma once
#include "Military.h"
/**Class that derives from Military. Without barracks the player can not rectuits an army */
class Barracks :
	public Military
{

public:
	/*Constructor for Barracks*/
	Barracks();
	/*Destructor for Barracks*/
	~Barracks();
	/*The method returns the building type as the first character of the bilding name*/
	char type_of_building();
};

