#include "Sword.h"

Sword::Sword() : Mele::Mele()
{
	melee_attack = 70;
	charge_bonus = 50;
	recruitment_cost = 550;
	upkeep_cost = 400;
}

Sword::~Sword()
{
}

char Sword::type_of_unit()
{
	return 's';
}
