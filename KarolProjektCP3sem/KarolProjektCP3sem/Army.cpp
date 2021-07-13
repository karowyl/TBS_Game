#include "Army.h"
#include "Archer.h"
#include "Matchlock.h"
#include "Pike.h"
#include "Sword.h"
#include "Cavalry.h"
#include "iostream"
#include <iomanip>

Army::Army()
{
}


//Gets city's coords and places Army on first coord that are available
Army::Army(std::pair<int, int> _coord)
{
	movement_range = 3;
	for(int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
		{
			if ((_coord.first + i >= 0 && _coord.second + j >= 0) && (i != 0 && j != 0))
			{
				coord = std::pair<int, int>{ _coord.first + i, _coord.second + j };
				return;
			}
		}
}

Army::~Army()
{
}


int Army::recruit_unit(char unit_class, int money)
{

	switch (unit_class)
	{
	case 'a':
		if (money >= (new Archer)->get_recruitment_cost())
		{
			army.push_back(new Archer);
			money -= (new Archer)->get_recruitment_cost();
		}
		else
		{
			std::cout << "\nSorry, You do not have enought money.\n";
			Sleep(1000);
		}
		break;

	case  'm':
		if (money >= (new Matchlock)->get_recruitment_cost())
		{
			army.push_back(new Matchlock);
			money -= (new Matchlock)->get_recruitment_cost();
		}
		else
		{
			std::cout << "\nSorry, You do not have enought money.\n";
			Sleep(1000);
		}
		break;

	case 'c':
		if (money >= (new Cavalry)->get_recruitment_cost())
		{
			army.push_back(new Cavalry);
			money -= (new Cavalry)->get_recruitment_cost();
		}
		else
		{
			std::cout << "\nSorry, You do not have enought money.\n";
			Sleep(1000);
		}
		break;

	case 'p':
		if (money >= (new Pike)->get_recruitment_cost())
		{
		army.push_back(new Pike);
		money -= (new Pike)->get_recruitment_cost();
		}
		else
		{
			std::cout << "\nSorry, You do not have enought money.\n";
			Sleep(1000);
		}
		break;

	case 's':
		if (money >= (new Sword)->get_recruitment_cost())
		{
		army.push_back(new Sword);
		money -= (new Sword)->get_recruitment_cost();
		}
		else
		{
			std::cout << "\nSorry, You do not have enought money.\n";
			Sleep(1000);
		}
		break;
	}
	return money;
}


void Army::move_army(int x, int y)
{
	coord.first = x;
	coord.second = y;
}

std::pair<int, int> Army::get_coord()
{
	return coord;
}

int Army::get_movement_range()
{
	return movement_range;
}

void Army::set_coord(COORD _c)
{
	coord.first = _c.X;
	coord.second = _c.Y;
}

void Army::use_movement(int x)
{
	movement_left -= x;
}

void Army::reset_movement()
{
	movement_left = movement_range;
}

int Army::get_movement_left()
{
	return movement_left;
}

void Army::print_army()
{
	int count_sword = 0;
	int count_pike = 0;
	int count_archer = 0;
	int count_matchlock = 0;
	int count_cavalry = 0;
	for (std::vector<Unit*>::iterator it = army.begin(); it != army.end(); ++it)
	{
		if ((*it)->type_of_unit() == 's')
			count_sword++;
		if ((*it)->type_of_unit() == 'p')
			count_pike++;
		if ((*it)->type_of_unit() == 'a')
			count_archer++;
		if ((*it)->type_of_unit() == 'm')
			count_matchlock++;
		if ((*it)->type_of_unit() == 'c')
			count_cavalry++;
	}  
	if (count_sword > 0)
	{
		std::cout << std::setw(9) << "Sword:" << std::setw(4) << count_sword << std::endl;
		for (std::vector<Unit*>::iterator it = army.begin(); it != army.end(); it++)
			if ((*it)->type_of_unit() == 's')
			{
				(*it)->print_info();
				break;
			}
	}
	if (count_pike > 0)
	{
		std::cout << std::setw(9) << "Pike:" << std::setw(4) << count_pike << std::endl;
		for (std::vector<Unit*>::iterator it = army.begin(); it != army.end(); it++)
			if ((*it)->type_of_unit() == 'p')
			{
				(*it)->print_info();
				break;
			}
	}
	if (count_matchlock > 0)
	{
		std::cout << std::setw(9) << "Machlock:" << std::setw(4) << count_matchlock << std::endl;
		for (std::vector<Unit*>::iterator it = army.begin(); it != army.end(); it++)
			if ((*it)->type_of_unit() == 'm')
			{
				(*it)->print_info();
				break;
			}
	}
	if (count_archer > 0)
	{ 
		std::cout << std::setw(9) << "Archer:" << std::setw(4) << count_archer << std::endl;
		for (std::vector<Unit*>::iterator it = army.begin(); it != army.end(); it++)
			if ((*it)->type_of_unit() == 'a')
			{
			(*it)->print_info();
			break;
			}
	}
	if (count_cavalry > 0)
	{
		std::cout << std::setw(9) << "Cavalry:" << std::setw(4) << count_cavalry << std::endl;
		for (std::vector<Unit*>::iterator it = army.begin(); it != army.end(); it++)
			if ((*it)->type_of_unit() == 'c')
			{
				(*it)->print_info();
				break;
			}
	}
	if (count_archer + count_matchlock + count_cavalry + count_pike + count_sword == 0)
		std::cout << "You haven't recruted any unit yet.\n";
	else
		std::cout << "Your army strength is " << calculate_strength() << " points.\n";
}

int Army::get_upkeep_cost()
{
	int cost = 0;
	int count_sword = 0;
	int count_pike = 0;
	int count_archer = 0;
	int count_matchlock = 0;
	int count_cavalry = 0;
	for (std::vector<Unit*>::iterator it = army.begin(); it != army.end(); ++it)
	{
		if ((*it)->type_of_unit() == 's')
			count_sword++;
		if ((*it)->type_of_unit() == 'p')
			count_pike++;
		if ((*it)->type_of_unit() == 'a')
			count_archer++;
		if ((*it)->type_of_unit() == 'm')
			count_matchlock++;
		if ((*it)->type_of_unit() == 'c')
			count_cavalry++;
	}
	cost = count_archer * (new Archer)->get_upkeep_cost() + count_sword * (new Sword)->get_upkeep_cost() + count_pike * (new Pike)->get_upkeep_cost() + count_matchlock * (new Matchlock)->get_upkeep_cost() + count_cavalry * (new Cavalry)->get_upkeep_cost();
	
	return cost;
}

void Army::create_enemy_army_template()
{
	if (army.empty())
	{
		for (int i = 0; i < 20; i++)
		{
			army.push_back(new Archer);
		}
		for (int i = 0; i < 30; i++)
		{
			army.push_back(new Pike);
		}
		for (int i = 0; i < 15; i++)
		{
			army.push_back(new Sword);
		}
		for (int i = 0; i < 20; i++)
		{
			army.push_back(new Cavalry);
		}
		for (int i = 0; i < 10; i++)
		{
			army.push_back(new Matchlock);
		}
	}
}

int Army::calculate_strength()
{
	int strength = 0;
	for (std::vector<Unit*>::iterator it = army.begin(); it != army.end(); ++it)
	{
		strength += (*it)->battle_value();
	}
	return strength;
}
