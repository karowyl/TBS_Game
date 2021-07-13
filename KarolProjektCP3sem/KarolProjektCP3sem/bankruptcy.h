#pragma once
#include <exception>
/**Exception. When the player is the bankrupt then he loses the game. */
class Bankruptcy :
    public std::exception
{
public:
	/*Constructor for Bankruptcy*/
    Bankruptcy() : exception("Bankruptcy!\nYour treasury buckled under the weight of your upkeep. You lost the game being unable to balance your economy.") {}
};

