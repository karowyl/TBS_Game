#pragma once
#include <utility>
#include <vector>
#include "Building.h"
#include "Army.h"
class City
{
private:
	//city's coord on map
	std::pair<int, int> coord;
	std::vector<Building*> city;
	int money;
	Army* army;

public:
	/*Constructor for City*/
	City();
	/*Constructor 
	@param _army pointer to army
	@param _coord city's coordinates*/
	City(std::pair<int, int> _coord, Army &_army);
	/*Returns x city's coordinate*/
	int get_x();
	/*Returns y city's coordinate*/
	int get_y();
	/*Returns city's coordinates
	@return coordinates*/
	std::pair<int, int> get_coord();
	/*Adds new build to the list of buildings
	@param building_class first letter of the type of building
	@param money city's current money
	@return updated money*/
	int build_structure(char building_class, int money);
	/*Calculates the army's upkeep cost
	@return upkeep*/
	int calc_upkeep();
	/*Prints list of building in the city*/
	void print_buildings();
	/*This method prints info about the city */
	void print_info();
	/*This method prints buildings construction menu*/
	void build_buildings();
	/*This method prints army recruitment menu */
	void recruitment();
	/*This method gives income for the city
	@return updated income*/
	int get_income();
	/*The metod adds income for new turn and checks the user for bankruptcy 
	@param income user's income for a given round*/
	int turn_income(int income);
	/*The method checks if the player has stables in the city*/
	bool has_stables();
	/*The method checks if the player has barracks in the city*/
	bool has_barracks();
	~City();
};

