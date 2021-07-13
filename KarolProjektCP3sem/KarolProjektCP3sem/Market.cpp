#include "Market.h"
#include <iostream>

Market::Market()
{
	income_multiplier = 0.25;
	cost = 2800;
}

Market::~Market()
{
}
float Market::get_income_multiplier()
{
	return income_multiplier;
}
char Market::type_of_building()
{
	return 'm';
}

void Market::print_info()
{
	std::cout << "Income multiplier: " << income_multiplier << std::endl;
}
