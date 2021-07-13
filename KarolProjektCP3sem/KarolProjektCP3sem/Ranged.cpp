#include "Ranged.h"
#include "Unit.h"

Ranged::Ranged() : Unit::Unit()
{
	range = 120;
	ammunition = 20;
	missile_damage = 1;
}

Ranged::~Ranged()
{
}

int Ranged::battle_value()
{
	return melee_attack + charge_bonus + range * missile_damage;
}