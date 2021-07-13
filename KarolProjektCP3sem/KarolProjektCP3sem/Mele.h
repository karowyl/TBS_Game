#pragma once
#include "Unit.h"
/** Class that derives from Unit.*/
class Mele :
	public Unit
{
protected:
	int bonus_vs_cav;

public:
	/*Constructor for Mele*/
	Mele();
	/*Destructor for Mele*/
	~Mele();
	/*The metods calculates and returns the power of unit*/
	int battle_value();
};

