#pragma once
#include <exception>
/**Exception. When the player's army is too weak in battle*/
class Loss :
    public std::exception
{
public: 
	/*Constructor for Loss*/
    Loss() : exception("You have lost! The enemy army was too powerful!") {}
};

