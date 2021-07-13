#pragma once
/**The Unit class is parent class for all units*/
class Unit
{
protected:
	int count;
	int melee_attack;
	int charge_bonus;
	int upkeep_cost;
	int recruitment_cost;

public:
	/*Constructor for Unit*/
	Unit();
	/*Desctructor for Unit*/
	~Unit();
	/*The method returns the recruitment cost*/
	int get_recruitment_cost();
	/*The method returns the upkeep cost*/
	int get_upkeep_cost();
	/*The method returns the unit type as the first character of the unit name*/
	virtual char type_of_unit();

	/*The virtual method informs about building cost. It is used in related classes */
	virtual void print_info();
	/*The virtual method returns the unit type as the first character of the unit name*/
	virtual int battle_value();
};
