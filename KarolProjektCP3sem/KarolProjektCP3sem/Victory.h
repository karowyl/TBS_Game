#pragma once
#include <exception>
/**Exception. If the player wins the game, the program turns off*/
class Victory :
    public std::exception
{
public:
	/*Constructor for Victory*/
    Victory() : exception("You have won! Congratuations!") {}
};

