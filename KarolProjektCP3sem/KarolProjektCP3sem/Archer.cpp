#include "Archer.h"

Archer::Archer() : Ranged::Ranged()
{
	range = 120;
	ammunition = 25;
	missile_damage = 1;
	recruitment_cost = 500;
	upkeep_cost = 300;
}

Archer::~Archer()
{
}

char Archer::type_of_unit()
{
	return 'a';
}
