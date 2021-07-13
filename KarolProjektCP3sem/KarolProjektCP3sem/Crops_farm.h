#pragma once
#include "Farm.h"
/** Class that derives from Farm. Crops_farm gives money*/
class Crops_farm :
	public Farm
{
private:
	int income;

public:
	/*Constructor for Crops_farm*/
	Crops_farm();
	/*Destructor for Crops_farm*/
	~Crops_farm();
	/*The method returns the building type as the first character of the building name*/
	char type_of_building();
	/*The method informs about income from crops_farm*/
	void print_info();
};

