#include "Matchlock.h"

Matchlock::Matchlock() : Ranged::Ranged()
{
	range = 90;
	ammunition = 15;
	missile_damage = 2;
	recruitment_cost = 700;
	upkeep_cost = 400;
}

Matchlock::~Matchlock()
{
}

char Matchlock::type_of_unit()
{
	return 'm';
}
