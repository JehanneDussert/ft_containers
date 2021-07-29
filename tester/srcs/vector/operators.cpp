#include "../../includes/vector_test.hpp"

void	operators_test(void)
{
	ft::vector<int>				v1(10, 8);
	ft::vector<int>				v2;

	std::cout << "\n| VECTOR |\n";
	v2 = v1;
	std::cout << "operator= :\t";
	if (v1 != v2)
		std::cout << "\e[0;31m[💥]\e[0m\t";
	else if (v1 == v2)
	{
		std::cout << "\e[0;32m[⭐️]\e[0m\t";
		std::cout << "operator!= :\t"; std::cout << "\e[0;32m[⭐️]\e[0m\t";
		std::cout << "operator== :\t"; std::cout << "\e[0;32m[⭐️]\e[0m\t";
	}
	else
	{		
		std::cout << "\e[0;31m[💥]\e[0m\t";
		std::cout << "operator!= :\t"; std::cout << "\e[0;31m[💥]\e[0m\t";
		std::cout << "operator== :\t"; std::cout << "\e[0;31m[💥]\e[0m\t";
	}
	if (v1[1] == v2[1])
		std::cout << "operator[] :\t"; std::cout << "\e[0;32m[⭐️]\e[0m\t";
	
	v1.pop_back();
	if (v1 < v2)
		{ std::cout << "\noperator< :\t"; std::cout << "\e[0;32m[⭐️]\e[0m\t"; }
	else
		{ std::cout << "operator< :\t"; std::cout << "\e[0;31m[💥]\e[0m\t"; }
	if (!(v1 > v2))
		{ std::cout << "operator> :\t"; std::cout << "\e[0;32m[⭐️]\e[0m\t"; }
	else
		{ std::cout << "operator> :\t"; std::cout << "\e[0;31m[💥]\e[0m\t"; }
	
	v1 = v2;
	if (v1 >= v2)
		{ std::cout << "operator>= :\t"; std::cout << "\e[0;32m[⭐️]\e[0m\t"; }
	else
		{ std::cout << "operator>= :\t"; std::cout << "\e[0;31m[💥]\e[0m\t"; }
	if (v1 <= v2)
		{ std::cout << "operator<= :\t"; std::cout << "\e[0;32m[⭐️]\e[0m\t"; }
	else
		{ std::cout << "operator<= :\t"; std::cout << "\e[0;31m[💥]\e[0m\t"; }

	std::cout << "\n\n| ITERATOR |\n";
	// *
	// ->
	// =
	// ==
	// !=
	// ++
	// ++(int)
	// --
	// --(int)
	// +
	// - x 2
	// <
	// >
	// <=
	// >=
	// +=
	// -=
	// [] x 3

	std::cout << "\n\n";
}
