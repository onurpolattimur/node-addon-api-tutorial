#include "simple_math.h"
#include <exception>

int SimpleMath::add(int number_1, int number_2)
{
	return number_1 + number_2;
}

int SimpleMath::substract(int number_1, int number_2)
{
	return number_1 - number_2;
}

int SimpleMath::multiply(int number_1, int number_2)
{
	return number_1 * number_2;
}

int SimpleMath::divide(int number_1, int number_2)
{
	if (number_2 == 0) {
		throw std::exception("Oppps! Please study some math!");
	}
	return number_1 / number_2;
}
