#include "Building.h"



Building::Building()
{
	cost = 500;
}

Building::~Building()
{
}

int Building::get_cost()
{
	return cost;
}

char Building::type_of_building()
{
	return 'b';
}

void Building::print_info()
{
}
