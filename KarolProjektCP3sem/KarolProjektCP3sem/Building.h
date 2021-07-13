#pragma once
/** The Building class is parent class for all buildings.*/
class Building
{
	protected:
		int cost;
		
	public:
		/*Constructor for Building*/
		Building();
		/*Destructor for Building*/
		~Building();
		/*The method returns building cost*/
		int get_cost();
		/*The virtual method returns the building type as the first character of the building name*/
		virtual char type_of_building();
		/*The virtual method informs about income or multipier income. It is used in related classes */
		virtual void print_info();
};

