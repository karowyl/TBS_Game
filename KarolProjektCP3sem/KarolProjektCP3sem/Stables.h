#pragma once
#include "Farm.h"
/** Class that derives from Farm. Without Stables the player can not recruit an cavalry*/
class Stables :
	public Farm
{
	//int income;
public:
	/*Constructor for Stables*/
	Stables();
	/*Destructor for Stables*/
	~Stables();
	/*The method returns income*/
	int get_income();
	/*The method informs about income*/
	void print_info();
	/*The method returns the building type as the first character of the building name*/
	char type_of_building();
};

