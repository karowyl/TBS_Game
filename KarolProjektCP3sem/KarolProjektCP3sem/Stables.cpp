#include "Stables.h"
#include "Building.h"
#include <iostream>

Stables::Stables() : Farm::Farm()
{
}

Stables::~Stables()
{
}

int Stables::get_income()
{
	return income;
}

void Stables::print_info()
{
	std::cout << "Income: " << income << std::endl;
}

char Stables::type_of_building()
{
	return 's';
}
