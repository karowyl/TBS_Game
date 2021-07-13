#include "Map.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <exception>

Map::Map()
{
}

Map::Map(std::string &_map_file_name) : map_file_name(_map_file_name)
{
	try
	{
		read_file();
		locate_enemy_city();
		locate_player_city();
		display_map();
	}
	catch (const char* msg)
	{
		std::cout << msg;
		throw;
	}
	catch (...)
	{
		throw;
	}
}

Map::~Map()
{
}


int Map::get_x() const
{
	return x;
}

int Map::get_y() const
{
	return y;
}

std::pair<int, int> Map::get_player_city() const
{
	return player_city;
}

std::pair<int, int> Map::get_enemy_city() const
{
	return enemy_city;
}


//assumes that the file has correct structure (!)
void Map::read_file()
{
	try {
		std::fstream file(this->map_file_name, std::ios::in);
		std::string temp;
		std::stringstream ss;

		std::getline(file, temp); //sets x and y
		ss << temp;
		ss >> temp;
		this->y = std::stoi(temp);
		ss >> temp;
		this->x = std::stoi(temp);
		this->map.resize(y);

		int i = 0; //x counter for the loop
		while (std::getline(file, temp))
		{
			ss.str(std::string()); //empty the stream
			ss.clear(); //removes eof flag
			ss << temp;
			while (ss >> temp)
				map[i].push_back(convert_to_map_element(temp));
			i++;
		}
		file.close();
	}
	catch (const char* msg) //throw exption to higher lvl
	{
		throw;
	}
	catch (...) //przechwytujemy wszytkie pozosta³e wyjatki i wyrzucamy wlasny wyjatek z informacja ze chodzi o mape
	{
		throw "Map file incorrect!\n";
	}
}

char Map::convert_to_map_element(std::string& arg)
{
	if (arg == "C")
		return 'C';
	if (arg == "E")
		return 'E';
	try
	{

		int temp = std::stoi(arg);
		switch (temp)
		{
		case 30: //mountain
			return 30;
			break;
		case 5: //forest
			return 5;
			break;
		case 176: //grass
			return 176;
			break;
		case 61: //river
			return 61;
			break;
		default:
			throw 1;
			break;
		}
	}
	catch (...)
	{
		throw "Undefined map symbol! Please use only allowed characters!\n";
	}
	
}

void Map::locate_player_city()
{
	std::pair<int, int> coord(0, 0);

	for (std::vector<std::vector<char>>::iterator it = map.begin(); it != map.end(); ++it, ++coord.second)
	{
		for (std::vector<char>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2, ++coord.first)
			if (*it2 == 'C')
			{
				player_city = std::move(coord);
				return;
			}
		coord.first = 0;
	}
	throw "Player's City not found!";
}

void Map::locate_enemy_city()
{
	std::pair<int, int> coord(0, 0);

	for (std::vector<std::vector<char>>::iterator it = map.begin(); it != map.end(); ++it, ++coord.second)
	{
		for (std::vector<char>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2, ++coord.first)
			if (*it2 == 'E')
			{
				enemy_city = std::move(coord);
				return;
			}
	}
	throw "Enemy's City not found!";
}

void Map::display_map() const
{
	system("cls");
	CONSOLE_FONT_INFOEX cf = { 0 };
	cf.cbSize = sizeof cf;
	cf.dwFontSize.X = 28;
	cf.dwFontSize.Y = 35;
	wcscpy_s(cf.FaceName, L"Terminal");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 500, 500, TRUE); // 800 width, 100 height
	SetConsoleTextAttribute(console, 15);
	for (std::vector<std::vector<char>>::const_iterator it = map.begin(); it != map.end(); ++it)
	{
		for (std::vector<char>::const_iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
			std::cout << *it2;
		std::cout << std::endl;
	}
}

char Map::operator[](std::pair<int, int> c) const
{
	return map[c.second][c.first];
}

