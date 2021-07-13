#pragma once
#include "Economy.h"
/**Class that derives from Economy. Market  multiplies the income*/
class Market :
	public Economy
{
private:
	float income_multiplier;

public:
	/*Constructor for Market*/
	Market();
	/*Destructor for Market*/
	~Market();
	/*The method returns income multiplier*/
	float get_income_multiplier();
	/*The method informs about income multiplier*/
	void print_info();
	/*The method returns the building type as the first character of the bilding name*/
	char type_of_building();
};

