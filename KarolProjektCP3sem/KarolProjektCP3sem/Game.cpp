#include "Game.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "Victory.h"
#include "Loss.h"
#include "bankruptcy.h"

//strength of enemy army on default is like ~21k 

Game::Game(std::string &map_file) //for new game
{
	try {
		map = new Map(map_file);
		map->display_map();

		player = new Player(*map);
		enemy = new Enemy(*map);
		player->set_enemy_army(enemy->get_army_coord());

		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO     cursorInfo;

		max_number_of_turns = 40;
		for (turn_counter = 0; turn_counter < max_number_of_turns; turn_counter++)
		{
			COORD c = { 0, map->get_y() + 1 };
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(h, c);
			std::cout << "Turn number: " << std::setw(2) << turn_counter << std::endl;
			std::cout << "Turns left: " << std::setw(3) << max_number_of_turns - turn_counter;
			
			GetConsoleCursorInfo(out, &cursorInfo);
			cursorInfo.bVisible = false; // set the cursor visibility
			SetConsoleCursorInfo(out, &cursorInfo);

			player->turn(turn_counter);

			//if player put hit army near (so |AA| = 1) the enmy army, they will fight
			if (player->is_enemy_nearby())
			{
				battle();
			}

			GetConsoleCursorInfo(out, &cursorInfo);
			cursorInfo.bVisible = true; // set the cursor visibility
			SetConsoleCursorInfo(out, &cursorInfo);
		}
		system("cls");
		SetConsoleCursorPosition(out, COORD{ 0, 0 });
		SetConsoleTextAttribute(out, 12); //green BG
		std::cout << "YOU LOST.\nEnemy's reinforcements arrived.";
		SetConsoleTextAttribute(out, 15); //return to default
		_getch();
	}
	catch (Victory n)
	{
		//This is mostly setting the window to look nice and then saying the user have won and thats it.
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		system("cls");
		CONSOLE_FONT_INFOEX cf = { 0 };
		cf.cbSize = sizeof cf;
		cf.dwFontSize.X = 14;
		cf.dwFontSize.Y = 16;
		wcscpy_s(cf.FaceName, L"Terminal");
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions
		MoveWindow(console, r.left, r.top, 900, 500, TRUE); // 500 width, 500 height
		SetConsoleCursorPosition(out, COORD{ 0, 0 });
		SetConsoleTextAttribute(out, 226); //green BG
		std::cout << "YOU WON.\nEnemy has been crushed.\n\n";
		SetConsoleTextAttribute(out, 15); //return to default
		system("Pause");
	}
	catch (Loss n)
	{
		//This is mostly setting the window to look nice and then saying the user have lost and thats it.
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);		
		system("cls");
		CONSOLE_FONT_INFOEX cf = { 0 };
		cf.cbSize = sizeof cf;
		cf.dwFontSize.X = 14;
		cf.dwFontSize.Y = 16;
		wcscpy_s(cf.FaceName, L"Terminal");
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions
		MoveWindow(console, r.left, r.top, 900, 500, TRUE); // 500 width, 500 height
		SetConsoleCursorPosition(out, COORD{ 0, 0 });
		SetConsoleTextAttribute(out, 12); //green BG
		std::cout << "YOU LOST.\nYour army has been crushed by the enemy.";
		SetConsoleTextAttribute(out, 15); //return to default
		system("PAUSE");
	}
	catch (Bankruptcy n)
	{
		//This is mostly setting the window to look nice and then saying the user have lost and thats it.
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		system("cls");
		CONSOLE_FONT_INFOEX cf = { 0 };
		cf.cbSize = sizeof cf;
		cf.dwFontSize.X = 14;
		cf.dwFontSize.Y = 16;
		wcscpy_s(cf.FaceName, L"Terminal");
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions
		MoveWindow(console, r.left, r.top, 900, 500, TRUE); // 500 width, 500 height
		SetConsoleCursorPosition(out, COORD{ 0, 0 });
		SetConsoleTextAttribute(out, 12); //green BG
		std::cout << n.what() << std::endl;
		SetConsoleTextAttribute(out, 15); //return to default
		system("PAUSE");
	}
	catch (...)
	{
		throw;
	}
}


Game::~Game()
{
}


void Game::exit()
{
}

void Game::battle()
{
	if (player->evaluate_army_strength() >= enemy->evaluate_army_strength())
		throw Victory();
	else
		throw Loss();
}

void Game::end_turn()
{
}

void Game::new_game()
{
}


//places the army on the map, on the filed right to the player's city
//void Game::load_player_army()
//{
//	std::vector<std::vector<char>>::iterator row_iterator = (map->map).begin() + city->get_y();
//	//std::vector<char>::iterator col_iterator = 
//	row_iterator[city->get_x() + 1];//this is where the army should be.
//	//must find iterator to C[x-1][y-1]
//	//std::vector<std::vector<char>>::iterator a = (map->map[]).begin() + city->get_x() - 1;
//}
