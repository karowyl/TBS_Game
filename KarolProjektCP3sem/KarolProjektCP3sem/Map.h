#pragma once
#include <string>
#include <vector>
#include <Windows.h>

/**This class reads map from a file and print it in console.
File must have following structure:
size_x size_y
[fields]*/
class Map
{
private:
	int x;
	int y;
	
	std::pair<int, int> player_city;
	std::pair<int, int> enemy_city;
	std::string map_file_name;
	std::vector<std::vector<char>> map;



public: 
	friend class Game;
	/*Constructor for Map*/
	Map();
	/*Constructor for Map
	@param _map_file_name file with the map */
	Map(std::string &_map_file_name);
	/*Destructor for Map*/
	~Map();
	/* Returns Width of map
	@return width of map*/
	int get_x() const;
	/* Returns Height of map
	@return height od map*/
	int get_y() const;
	/* Returns coordinate with the place of player's city
	@return coordinate with the place of player's city*/
	std::pair<int, int> get_player_city() const;
	/*Returns coordinate with the place of enemy's city
	Returns coordinate with the place of enemy's city*/
	std::pair<int, int> get_enemy_city() const;
	/*This method displays map in console*/
	void display_map() const;
	/*Subscript operator overloading
	@param c coordinates 
	@return character under coorindates c*/
	char operator[](std::pair<int, int> c) const; //


private:
	/*This method reads map from file*/
	void read_file();
	/*changes string from map to character
	@param arg string form file
	@return character*/
	char convert_to_map_element(std::string& arg); 
	/*This method locates player's city on the map and save to variable player_city*/
	void locate_player_city();
	/*This method locates enemy's city on the map and save to variable enemy_city*/
	void locate_enemy_city();
};

