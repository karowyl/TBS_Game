#include "Pike.h"

Pike::Pike() : Mele::Mele()
{
	bonus_vs_cav = 100;
	recruitment_cost = 500;
	upkeep_cost = 300;
}

Pike::~Pike()
{
}

char Pike::type_of_unit()
{
	return 'p';
}