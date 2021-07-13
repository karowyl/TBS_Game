#include "Farm.h"

int Farm::get_income()
{
	return income;
}

Farm::Farm()
{
	cost = 900;
	income = 400;

}

Farm::~Farm()
{
}
