#include "Mele.h"

Mele::Mele() : Unit::Unit()
{
	melee_attack = 10;
	charge_bonus = 10;
	bonus_vs_cav = 5;
}

Mele::~Mele()
{
}



int Mele::battle_value()
{
	return melee_attack + charge_bonus + bonus_vs_cav;
}
