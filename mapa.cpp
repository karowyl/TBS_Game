#include <iostream>

int main()
{
	std::cout << (char)30 << (char)30 << (char)30 << (char)30 << (char)30 << (char)30 << (char)30 << (char)176 << 'E' << std::endl;
	std::cout << (char)30 << (char)30 << (char)30 << (char)30 << (char)30 << (char)5 << (char)5 << (char)176 << (char)176 << std::endl;
	std::cout << (char)30 << (char)30 << (char)5 << (char)30 << (char)30 << (char)5 << (char)5 << (char)176 << (char)176 << std::endl;
	std::cout << (char)30 << (char)5 << (char)5 << (char)5 << (char)30 << (char)30 << (char)5 << (char)176 << (char)61 << std::endl;
	std::cout << (char)30 << (char)5 << (char)5 << (char)176 << (char)61 << (char)30 << (char)5 << (char)61 << (char)176 << std::endl;
	std::cout << (char)30 << 'C' << 'A' << (char)176 << (char)176 << (char)61 << (char)61 << (char)30 << (char)176 << std::endl;
	std::cout << (char)5 << (char)176 << (char)176 << (char)176 << (char)176 << (char)30 << (char)30 << (char)5 << (char)5 << std::endl;

	return 0;
}


