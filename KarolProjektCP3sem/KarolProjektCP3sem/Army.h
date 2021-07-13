#pragma once
#include "Unit.h"
#include <string>
#include <vector>
#include <Windows.h>
/**This class represents player's army*/
class Army
{
private:
	std::pair<int, int> coord;
	int upkeep_cost;
	int movement_range;
	int movement_left;
	int capacity;
	int replenishment_rate;
	std::vector< Unit* > army;
	
public:
	Army();
	/*Constructor. 
	@param _coord city's coordinates. used to determine army's position on the map */
	Army(std::pair<int, int> _coord);
	/*Destructor for Army*/
	~Army();

	/*The method recruits unit and returns updated money in the city
	@param unit_class first letter of unit which player wants to recruit 
	@param money the current money in the city
	@return updated money in the city*/
	int recruit_unit(char unit_class, int money);
	/*This metod is used to move the army
	@param x coordinate of x
	@param y coordinate of y */
	void move_army(int x, int y);
	/*This method gives information about coordinate of army
	@return coordinates of the army as a pair of integers*/
	std::pair<int, int> get_coord();
	/*This method returns army's total movement range
	@return army's total movement range*/
	int get_movement_range();
	/*This mathod sets amy's coordinates
	@param _c new coodinates */
	void set_coord(COORD _c);
	/*This method decreases available movement points
	@param x number of point to be subtracted */
	void use_movement(int x);
	/*This methd resets amry's movement points*/
	void reset_movement();
	/*This methos returns movement points left
	@return  movement points left*/
	int get_movement_left();
	/*The method informs the player about his army*/
	void print_army();
	/*The method calculates and returns the upkeep cost*/
	int get_upkeep_cost();
	/*The method creates the enemy's army*/
	void create_enemy_army_template();
	/*The method calculates and returns the strength of the army*/
	int calculate_strength();
};
