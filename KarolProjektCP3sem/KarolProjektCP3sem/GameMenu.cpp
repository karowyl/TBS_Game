#include "GameMenu.h"
#include "ExitGame.h"
#include <string>
#include <iostream>
#include <Windows.h>

GameMenu::GameMenu(std::string& map_file, std::string& save_file)
{
	do 
	{
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

		system("cls"); 
		std::cout << "Welcome in my game! Have fun!\n";
		std::cout << "Your have to destroy powerful enemy before the he gets reiforcments! You can defeat him now but once united with second army the emeny will be unstoppable!\n\n";
		std::cout << "Type \"start\" to start a game or \"exit\" to leave.\n";
		std::string choice;
		std::cin >> choice;

		if (choice == "start")
		{
			if (save_file == "") //if player is starting new game
			{
				try
				{
					game = new Game(map_file);
				}
				catch (...)
				{
					std::cerr << "Failed to create new game.\n";
					throw;
				}
			}
		}
		else if (choice == "exit")
		{
			throw ExitGame();
		}
	} while (1);
}

GameMenu::~GameMenu()
{
}
