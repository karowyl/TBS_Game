#pragma once
#include "City.h"
#include "Army.h"
#include "Map.h"
/**Player class handles everything related to the player like turn, movement...*/
class Player
{
protected:
	City* city;
	Army* army;
	const Map* map;
	int movement_points;
	std::pair<int, int> enemy_army;

public:
	/*Constructor for Players*/
	Player();
	/*Constructor
	@param _map poiter to map*/
	Player(const Map &_map);
	/*Destructor*/
	~Player();
	/* This metod handles the player's turn
	@param turn_counter current number turn */
	void turn(int turn_counter);
	/*Prints army on the map*/
	void print_army();
	/*Sets enemy's coordinates */
	void set_enemy_army(std::pair<int, int> coord);
	/*Returns amry's coordinates */
	std::pair<int, int> get_army_coord();
	/*This method checks if the player's army is next to the opponent */
	bool is_enemy_nearby();
	/*This method return army's strength
	@return current army's strength*/
	int evaluate_army_strength();

private:
	/*This method summarises player's financial condition at the end of turn*/
	void upkeep();
	/*Helper method.Prints map character on position provided in 1st arg and in colour specified in 2nd arg 
	@param c coordinate
	@param color color in which to display */
	void print_in_console(COORD c, int color);
	/*This metod handles army's movement*/
	COORD army_movement();

};

