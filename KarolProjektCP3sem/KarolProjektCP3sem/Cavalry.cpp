#include "Cavalry.h"

Cavalry::Cavalry() : Unit::Unit()
{
	charge_bonus = 200;
	upkeep_cost = 650;
	recruitment_cost = 1000;
}

Cavalry::~Cavalry()
{
}

char Cavalry::type_of_unit()
{
	return 'c';
}

int Cavalry::battle_value()
{
	return melee_attack + charge_bonus;
}
