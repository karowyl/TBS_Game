#pragma once
#include <exception>
/**Exception. Class is used to exit the game*/
class ExitGame :
    public std::exception
{
public:
	/*Constructor for ExitGame*/
    ExitGame();
};

