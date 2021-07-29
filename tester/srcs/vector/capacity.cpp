#include "../../includes/vector_test.hpp"

void	check_content(std::vector<int> &v1, ft::vector<int> &v2)
{
	int	err = 0;

	ft::vector<int>::iterator	it2_beg = v2.begin();
	ft::vector<int>::iterator	it2_end = v2.end();

	std::cout << "Content :\t";
	for (std::vector<int>::iterator it1 = v1.begin(); it1 != v1.end(); ++it1)
	{
		if (*it2_beg != *it1)
		{
			std::cout << "\n\e[0;31m[💥]\e[0m\t"; //[REAL] " << *it1 << "\t[YOURS] " << *it2_beg;
			err++;
		}
		++it2_beg;
	}
	if (!err)
		std::cout << "\e[0;32m[⭐️]\e[0m\t";
	std::cout << '\n';
}

void	check_size(std::vector<int> &v1, ft::vector<int> &v2)
{
	std::cout << "Size :\t";
	if (v1.size() != v2.size())
		std::cout << "\e[0;31m[💥]\e[0m\t"; //[REAL] " << v1.size() << " [YOURS] " << v2.size() << "\n";
	else
		std::cout << "\e[0;32m[⭐️]\e[0m\t";
}

void	check_capacity(std::vector<int> &v1, ft::vector<int> &v2)
{
	// corriger constructeur par copie
	std::cout << "Capacity :\t";
	if (v1.capacity() != v2.capacity())
		std::cout << "\e[0;31m[☠💥]\e[0m\t"; //[REAL] " << v1.capacity() << " [YOURS] " << v2.capacity() << "\n";
	else
		std::cout << "\e[0;32m[⭐️]\e[0m\t";
}
