#include <iostream>
#include "simple_math.h"
int main()
{
	SimpleMath simpleMath;
	std::cout << simpleMath.add(1, 2) << std::endl;
	std::cout << simpleMath.substract(6, 4) << std::endl;
	std::cout << simpleMath.multiply(3, 5) << std::endl;
	std::cout << simpleMath.divide(12, 0) << std::endl;
    std::cout << "Hello World!\n";
}

