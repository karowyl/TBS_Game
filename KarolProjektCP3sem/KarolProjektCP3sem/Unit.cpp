#include "Unit.h"

Unit::Unit()
{
	count = 10;
	melee_attack = 1;
	charge_bonus = 1;
	upkeep_cost = 300;
	recruitment_cost = 600;
}

Unit::~Unit()
{
}

int Unit::get_recruitment_cost()
{
	return recruitment_cost;
}

int Unit::get_upkeep_cost()
{
	return upkeep_cost;
}

char Unit::type_of_unit()
{
	return 'u';
}

void Unit::print_info()
{
}


int Unit::battle_value()
{
	return melee_attack + charge_bonus;
}

