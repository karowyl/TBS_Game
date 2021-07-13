#include "City.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Building.h"
#include "Barracks.h"
#include "Market.h"
#include "Stables.h"
#include "Crops_farm.h"
#include "Archer.h"
#include "Matchlock.h"
#include "Pike.h"
#include "Sword.h"
#include "Cavalry.h"
#include "bankruptcy.h"
#include <iomanip>

#define TIME 3000

City::City()
{
	coord = std::pair<int, int>{ 0, 0 };
	money = 0;
}

City::City(std::pair<int, int> _coord, Army &_army) : coord(_coord)
{
	money = 1000;
	army = &_army;
}

int City::get_x()
{
	return coord.first;
}

int City::get_y()
{
	return coord.second;
}

std::pair<int, int> City::get_coord()
{
	return coord;
}

int City::build_structure(char building_class, int money)
{
	switch (building_class)
	{
	case 'm':
		if (money >= (new Market)->get_cost())
		{
		city.push_back(new Market);
		money -= (new Market)->get_cost();
		}
		else
		{
			std::cout << "\nYou do not have enought money\n";
			Sleep(1000);
		}
		break;

	case  's':
		if (money >= (new Stables)->get_cost())
		{
			city.push_back(new Stables);
			money -= (new Stables)->get_cost();
		}
		else
		{
			std::cout << "\nYou do not have enought money\n";
			Sleep(1000);
		}
		break;

	case 'c':
		if (money >= (new Crops_farm)->get_cost())
		{
			city.push_back(new Crops_farm);
			money -= (new Crops_farm)->get_cost();
		}
		else
		{
			std::cout << "\nYou do not have enought money\n";
			Sleep(1000);
		}
		break;

	case 'b':
		if (money >= (new Barracks)->get_cost())
		{
			city.push_back(new Barracks);
			money -= (new Barracks)->get_cost();
		}
		else
		{
			std::cout << "\nYou do not have enought money\n";
			Sleep(1000);
		}
		break;
	}
	return money;
}

int City::calc_upkeep()
{
	return army->get_upkeep_cost();
}

void City::print_buildings()
{
	int count_market = 0;
	int count_crops = 0;
	int count_stables = 0;
	int count_baracks = 0;

	for (std::vector<Building*>::iterator it = city.begin(); it != city.end(); it++)
	{
		if ((*it)->type_of_building() == 'm')
			count_market++;
		if ((*it)->type_of_building() == 'c')
			count_crops++;
		if ((*it)->type_of_building() == 's')
			count_stables++;
		if ((*it)->type_of_building() == 'b')
			count_baracks++;
	}
	if (count_market > 0)
	{
		std::cout << std::setw(9) << "Market:" << std::setw(4) << count_market << std::endl;
		//for (std::vector<Building*>::iterator it = city.begin(); it != city.end(); it++)
		//	if ((*it)->type_of_building() == 'm')
		//	{
		//		//(*it)->print_info();
		//		break;
		//	}
	}
	if (count_crops > 0)
	{
		std::cout << std::setw(9) << "Crops:" << std::setw(4) << count_crops << std::endl;
		//for (std::vector<Building*>::iterator it = city.begin(); it != city.end(); it++)
			//if ((*it)->type_of_building() == 'c')
			//{
			//	//(*it)->print_info();
			//	break;
			//}
	}
	if (count_stables > 0)
	{
		std::cout << std::setw(9) << "Stables:" << std::setw(4) << count_stables << std::endl;
		//for (std::vector<Building*>::iterator it = city.begin(); it != city.end(); it++)
			//if ((*it)->type_of_building() == 's')
			//{
			//	//(*it)->print_info();
			//	break;
			//}
	}
	if(count_baracks > 0)
		std::cout << std::setw(9) << "Baracks:" << std::setw(4) << count_baracks << std::endl;
	if (count_baracks + count_crops + count_market + count_stables == 0)
		std::cout << "You do not have any buildings yet.\n";

}

void City::print_info()
{
	CONSOLE_FONT_INFOEX cf = { 0 };
	cf.cbSize = sizeof cf;
	cf.dwFontSize.X = 12;		
	cf.dwFontSize.Y = 17;
	wcscpy_s(cf.FaceName, L"Terminal");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 500, 500, TRUE); // 800 width, 100 height
	//system("cls");
	//--------------------------------------------------------------

	COORD c = { 0, 0 };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleCursorPosition(h, c);
	//SetConsoleTextAttribute(h, 15);
	//std::cout << "City coordinates: (" << this->coord.first << ", " << this->coord.second << ")\n";
	//std::cout << "Money in treasury: " << this->money << std::endl;
	//std::cout << "Upkeep next turn: " << this->calc_upkeep() << std::endl;
	//std::cout << "\'b\' Infrastructure.\n";
	//this->print_buildings();
	//std::cout << "\'a\' Army.\n\n";
	//std::cout << "Press \'e\' to return to map, \'b\' to enter infrastructure management menu or \'a\' to enter army management menu.";

	system("cls");
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 15);
	std::cout << "City coordinates: (" << this->coord.first << ", " << this->coord.second << ")\n";
	std::cout << "Money in treasury: " << this->money << std::endl;
	std::cout << "Upkeep next turn: " << this->calc_upkeep() << std::endl;
	//std::cout << "\'b\' Infrastructure.\n";
	//this->print_buildings();
	//std::cout << "\'a\' Army.\n\n";
	std::cout << "\n\nPress \'e\' to return to map, \'b\' to enter infrastructure management menu or \'a\' to enter army management menu.\n";


	char button_pressed;
	while (1)
	{
		system("cls");
		SetConsoleCursorPosition(h, c);
		SetConsoleTextAttribute(h, 15);
		std::cout << "City coordinates: (" << this->coord.first << ", " << this->coord.second << ")\n";
		std::cout << "Money in treasury: " << this->money << std::endl;
		std::cout << "Upkeep next turn: " << army->get_upkeep_cost() << std::endl;
		std::cout << "Wealth generated by city: " << this->get_income() << std::endl;
		std::cout << "Income next turn: " << this->get_income() - army->get_upkeep_cost() << std::endl;
		std::cout << "\nInfrastructure:\n"; this->print_buildings();
		std::cout << "Army:\n";  army->print_army();
		std::cout << "\n\nPress \'e\' to return to map, \'b\' to enter infrastructure management menu or \'a\' to enter army management menu.\n\n";

		switch (tolower(_getch()))
		{
		case 'e':
			goto McGonagall; //"I've always wanted to use that spell."
			break;
		case 'b':
			//print_buildings();
			build_buildings();
			break;
		case 'a':
			//army->print_army();
			recruitment();
			break;
		default:
			break;
		}
	}
	McGonagall:
	return;
}

void City::build_buildings()
{
	std::cout << "Press \'m\' to build market\n   Building cost: " << (new Market)->get_cost() << std::endl;
	std::cout << "Press \'c\' to build crops farm\n   Building cost: " << (new Crops_farm)->get_cost() << std::endl;
	std::cout << "Press \'s\' to build stables\n   Building cost: " << (new Stables)->get_cost() << std::endl;
	std::cout << "Press \'b\' to build barracks\n   Building cost: " << (new Barracks)->get_cost() << std::endl;
	std::cout << "Press \'e\' to return\n";


	char button_pressed;
	while (1)
	{
		switch (tolower(_getch()))
		{
		case 'm':
			money = this->build_structure('m', money);
			return;
			break;
		case 'c':
			money = this->build_structure('c', money);
			return;
			break;
		case 's':
			money = this->build_structure('s', money);
			return;
			break;
		case 'b':
			money = this->build_structure('b', money);
			return;
			break;
		case 'e':
			return;
		}

	}
}

void City::recruitment()
{
	if (!has_barracks())
	{
		std::cout << "You have to build barracks to recruit units!\n";
		Sleep(TIME);
		return;
	}

	std::cout << "Press \'a\' to recruit archer\n   Recruitment cost: " << (new Archer)->get_recruitment_cost() << "\n   Upkeep cost: " << (new Archer)->get_upkeep_cost() << std::endl;
	std::cout << "Press \'m\' to recruit matchlock\n   Recruitment cost: " << (new Matchlock)->get_recruitment_cost() << "\n   Upkeep cost: " << (new Matchlock)->get_upkeep_cost() << std::endl;
	std::cout << "Press \'c\' to recruit cavalry\n   Recruitment cost: " << (new Cavalry)->get_recruitment_cost() << "\n   Upkeep cost: " << (new Cavalry)->get_upkeep_cost() << std::endl;
	std::cout << "Press \'p\' to recruit pike\n   Recruitment cost: " << (new Pike)->get_recruitment_cost() << "\n   Upkeep cost: " << (new Pike)->get_upkeep_cost() << std::endl;
	std::cout << "Press \'s\' to recruit sword\n   Recruitment cost: " << (new Sword)->get_recruitment_cost() << "\n   Upkeep cost: " << (new Sword)->get_upkeep_cost() << std::endl;
	std::cout << "Press \'e\' to return\n";


	char button_pressed;
	while (1)
	{
		switch (tolower(_getch()))
		{
		case 'm':
			money = army->recruit_unit('m', money);
			return;
			break;
		case 'a':
			money = army->recruit_unit('a', money);
			return;
			break;
		case 's':
			money = army->recruit_unit('s', money);
			return;
			break;
		case 'p':
			money = army->recruit_unit('p', money);
			return;
			break;
		case 'c':
			if (!has_stables())
			{
				std::cout << "You have to build stables to recruit cavalery!\n";
				Sleep(TIME);
				break;
			}
			money = army->recruit_unit('c', money);
			return;
			break;
		case 'e':
			return;
		}

	}
}

int City::get_income()
{
	int income = 0;
	int count_market = 0;
	int count_crops = 0;
	int count_stables = 0;

	for (std::vector<Building*>::iterator it = city.begin(); it != city.end(); it++)
	{
		if ((*it)->type_of_building() == 'm')
			count_market++;
		if ((*it)->type_of_building() == 'c')
			count_crops++;
		if ((*it)->type_of_building() == 's')
			count_stables++;
	}

	income = (count_crops * (new Crops_farm)->get_income() + count_stables * (new Stables)->get_income()) * (1+(count_market * (new Market)->get_income_multiplier()));

	return income;
}

int City::turn_income(int income)
{
	money += income;
	if (money < 0)
		throw Bankruptcy();
	return 0;
}

bool City::has_stables()
{
	for (std::vector<Building*>::iterator it = city.begin(); it < city.end(); ++it)
	{
		if ((*it)->type_of_building() == 's')
			return true;
	}

	return false;
}

bool City::has_barracks()
{
	for (std::vector<Building*>::iterator it = city.begin(); it < city.end(); ++it)
	{
		if ((*it)->type_of_building() == 'b')
			return true;
	}

	return false;
}

City::~City()
{
}
