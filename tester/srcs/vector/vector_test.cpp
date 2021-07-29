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

int main(void)
{
	// std::cout << "1️⃣  Constructors\n\n";
	std::cout << "2️⃣  Operators\n\n";
	operators_test();
	// std::cout << "3️⃣  Begin & end\n\n";
	// std::cout << "4️⃣  Rbegin & rend\n\n";
	// std::cout << "5️⃣  Size, max_size, capacity, empty\n\n";
	// std::cout << "6️⃣  Reserve & resize\n\n";
	std::cout << "7️⃣  Assign\n\n";
	assign_test();
	// std::cout << "8️⃣  Push_back & pop_back\n\n";
	// std::cout << "9️⃣  Insert & erase\n\n";
	// std::cout << "🔟  Swap x 2\n\n";
	// std::cout << "1️⃣1️⃣  Clear\n\n";
	// std::cout << "1️⃣2️⃣  Get allocator\n\n";

	return 0;
}
