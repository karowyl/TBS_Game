#include "Army.h"
#include "Map.h"
#include "Game.h"
#include "GameMenu.h"
#include "Player.h"
#include "ExitGame.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Setting the console window ------>BEGINNING
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
	//<------END

	std::string map_file;

	if (argc == 2)
	{
		map_file = argv[1];
	}
	else if (argc < 2)
	{
		map_file = "../../mapa.txt";
	}
	else
	{
		std::cout << "You gave too many arguments! \nPlease try again!\n";
		Sleep(3000);
		return 0;
	}
	
	std::string save_file = "";
	
	try
	{
		GameMenu game_menu(map_file, save_file);
	}
	catch (ExitGame e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Fatal error. Closing the game...\n";
	}

	system("PAUSE");
	return 0;
}