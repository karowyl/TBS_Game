#pragma once
#include "Building.h"
/**Class that derives from Building. Parent class for crops_farms and stables.*/
class Farm :
	public Building
{
protected:
	int income;

public:
	/*The method returns a income from the farm*/
	int get_income();
	/*Constructor for Farm*/
	Farm();
	/*Destructor for Farm*/
	~Farm();

};

