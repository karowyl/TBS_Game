#pragma once
#include "Mele.h"
/** Class that derives from Mele. It has special abilites for pike.*/
class Pike :
	public Mele
{
public:
	/*Constructor for Pike*/
	Pike();
	/*Destructor for Pike*/
	~Pike();
	/*The method returns the unit type as the first character of the unit name*/
	char type_of_unit();
};

