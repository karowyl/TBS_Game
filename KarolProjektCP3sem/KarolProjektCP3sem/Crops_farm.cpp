#include "Crops_farm.h"
#include <iostream>
Crops_farm::Crops_farm()
{
	income = 600;
}

Crops_farm::~Crops_farm()
{
}

void Crops_farm::print_info()
{
	std::cout << "Income: " << income << std::endl;
}

char Crops_farm::type_of_building()
{
	return 'c';
}
