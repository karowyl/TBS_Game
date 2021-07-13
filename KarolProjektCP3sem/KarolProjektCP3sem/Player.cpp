#include "Player.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Crops_farm.h"
#include "Stables.h"
#include <vector>
#include "City.h"

Player::Player()
{
    city = nullptr;
    army = nullptr;
    map = nullptr;
    movement_points = 0;
}

Player::Player(const Map &_map)
{
    map = &_map;
    army = new Army(map->get_player_city());
    city = new City(map->get_player_city(), *army);
    print_army();
}

Player::~Player()
{
}

void Player::turn(int turn_counter)
{
	COORD c = { 0, 0 };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
	SetConsoleCursorPosition(h, c);
    SetConsoleTextAttribute(h, 47); //green BG
    std::cout << (*map)[std::pair<int, int>(c.X, c.Y)];
    SetConsoleTextAttribute(h, 15); //return to default
	
	upkeep();
    army->reset_movement();

    unsigned char pressed_bttn;
    bool turn = true;

	while (turn) //until player skips turn
	{
        pressed_bttn = _getch();
        if (pressed_bttn == 0xE0) //for arrows - navigation, if 1st val is escape its special sign
        {
            switch (_getch()) 
            { // the real value
            case 72:
                // code for arrow up
                if (c.Y - 1 < 0)
                    break;
                print_in_console(c, 15);
                c.Y -= 1;
                print_in_console(c, 47);
                break;
            case 75:
                // code for arrow left
                if (c.X - 1 < 0)
                    break;
                print_in_console(c, 15);
                c.X -= 1;
                print_in_console(c, 47);
                break;
            case 77:
                // code for arrow right
                if (c.X + 1 == map->get_x())
                    break;
                print_in_console(c, 15);
                c.X += 1;
                print_in_console(c, 47);
                break;
            case 80:
                // code for arrow down
                if (c.Y + 1 == map->get_y())
                    break;
                print_in_console(c, 15);
                c.Y += 1;
                print_in_console(c, 47);
                break;
            }
        }
        else
        {
            switch (tolower(pressed_bttn))
            {
            case 'n':
                //end turn
                print_in_console(c, 15);
                turn = 0;
                break;
            case 's':
                //if we're selecting the army
                if ((c.X == (army->get_coord()).first && c.Y == (army->get_coord()).second) && army->get_movement_left() > 0)
                {
                    COORD tc = c;
                    c = army_movement();
                    SetConsoleCursorPosition(h, tc);
                    SetConsoleTextAttribute(h, 15);
                    std::cout << (*map)[std::pair<int, int>(tc.X, tc.Y)];
                    army->set_coord(c);
                    print_in_console(c, 47);
                    continue;
                }
                //if we're selecting the city
                else if (c.X == (city->get_coord()).first && c.Y == (city->get_coord()).second)
                {
                    //enter menu
                    city->print_info();
                    //after player left the menu restore the proper interface
                    map->display_map();
                    print_army();
                    GetConsoleCursorInfo(out, &cursorInfo);
                    cursorInfo.bVisible = false; // set the cursor visibility
                    SetConsoleCursorInfo(out, &cursorInfo);
                    COORD c = { 0, map->get_y() + 1 };
                    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleCursorPosition(h, c);
                    std::cout << "Turn number: " << turn_counter;
                }
                   
                print_in_console(c, 228);
                break;
            }
        }
	}
}

void Player::print_army()
{
    COORD c;
    c.X = (short)(army->get_coord()).first;
    c.Y = (short)(army->get_coord()).second;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, c);
    std::cout << "A";
}

void Player::set_enemy_army(std::pair<int, int> coord)
{
    enemy_army.first = coord.first;
    enemy_army.second = coord.second;
}

std::pair<int, int> Player::get_army_coord()
{
    return army->get_coord();
}

bool Player::is_enemy_nearby()
{
    for(int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
        {
            if (army->get_coord().first + j == enemy_army.first && army->get_coord().second + i == enemy_army.second)
                return true;
        }

    return false;
}

int Player::evaluate_army_strength()
{
    return army->calculate_strength();
}

void Player::upkeep()
{
	int income = 0;

	income = (city->get_income() - army->get_upkeep_cost());
    city->turn_income(income);

}

void Player::print_in_console(COORD c, int color)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, c);
    SetConsoleTextAttribute(h, color); //return to default
    if (((army->get_coord()).first == c.X && (army->get_coord()).second == c.Y) || (this->enemy_army.first == c.X &&  this->enemy_army.second == c.Y))
        std::cout << 'A';
    else
        std::cout << (*map)[std::pair<int, int>(c.X, c.Y)];
        //std::cout << map->operator[](std::pair<int, int>(c.X, c.Y));
    SetConsoleTextAttribute(h, 15); //return to default
}

COORD Player::army_movement()
{
    COORD tc = { (army->get_coord()).first, (army->get_coord()).second };
    unsigned char pressed_bttn;
    int movement_cost = 0;
    while (movement_cost < army->get_movement_range())
    {
        pressed_bttn = _getch();
        if (pressed_bttn == 0xE0) //for arrows - navigation, if 1st val is escape its special sign
        {
            switch (_getch())
            { // the real value
            case 72:
                // code for arrow up
                if (tc.Y - 1 < 0)
                    break;
                print_in_console(tc, 15);
                tc.Y -= 1;
                print_in_console(tc, 78);
                movement_cost++;
                break;
            case 75:
                // code for arrow left
                if (tc.X - 1 < 0)
                    break;
                print_in_console(tc, 15);
                tc.X -= 1;
                print_in_console(tc, 78);
                movement_cost++;
                break;
            case 77:
                // code for arrow right
                if (tc.X + 1 == map->get_x())
                    break;
                print_in_console(tc, 15);
                tc.X += 1;
                print_in_console(tc, 78);
                movement_cost++;
                break;
            case 80:
                // code for arrow down
                if (tc.Y + 1 == map->get_y())
                    break;
                print_in_console(tc, 15);
                tc.Y += 1;
                print_in_console(tc, 78);
                movement_cost++;
                break;
            }
        }
        else
        {
            switch (tolower(pressed_bttn))
            {
            case 'm':
                print_in_console(tc, 15);
                army->use_movement(movement_cost);
                return tc;
                break;
            }
        }
    }
    army->use_movement(movement_cost);
    print_in_console(tc, 15);
    return tc;
}
