#include "../srcs/Vector_functions.hpp"
#include <vector>

void	check_size(std::vector<int> &v1, ft::vector<int> &v2)
{
	std::cout << "Size test:\t";
	if (v1.size() != v2.size())
		std::cout << "\e[0;31mError. Wrong size.\e[0m\t[REAL] " << v1.size() << " [YOURS] " << v2.size() << "\n";
	else
		std::cout << "\e[0;32mOK\e[0m\t";
}

void	check_capacity(std::vector<int> &v1, ft::vector<int> &v2)
{
	// corriger constructeur par copie
	std::cout << "Capacity test:\t";
	if (v1.capacity() != v2.capacity())
		std::cout << "\e[0;31mError. Wrong capacity.\e[0m\t[REAL] " << v1.capacity() << " [YOURS] " << v2.capacity() << "\n";
	else
		std::cout << "\e[0;32mOK\e[0m\t";
}

void	check_content(std::vector<int> &v1, ft::vector<int> &v2)
{
	int	err = 0;

	ft::vector<int>::iterator	it2_beg = v2.begin();
	ft::vector<int>::iterator	it2_end = v2.end();

	std::cout << "Content test:\t";
	for (std::vector<int>::iterator it1 = v1.begin(); it1 != v1.end(); ++it1)
	{
		if (*it2_beg != *it1)
		{
			std::cout << "\n\e[0;31mError. Wrong content.\e[0m\n[REAL] " << *it1 << "\t[YOURS] " << *it2_beg;
			err++;
		}
		++it2_beg;
	}
	if (!err)
		std::cout << "\e[0;32mOK\e[0m";
	std::cout << '\n';
}

void	assign_test()
{
	std::vector<int>			v1;
	ft::vector<int>				v2;

	std::cout << "| FILL |\n\n";
	v1.assign(5, 100);
	v2.assign(5, 100);

	check_size(v1, v2);
	check_capacity(v1, v2);
	check_content(v1, v2);

	v1.push_back(5); 
	std::cout << "New size should be " << v1.size() << std::endl;
	v1.push_back(4); v1.push_back(3); v1.push_back(2); v1.push_back(1);
	v2.push_back(5); v2.push_back(4); v2.push_back(3); v2.push_back(2); v2.push_back(1);
	v1.pop_back(); v2.pop_back();
	v1.pop_back(); v2.pop_back();

	check_size(v1, v2);
	check_capacity(v1, v2);
	check_content(v1, v2);

	std::vector<int>			v3;
	ft::vector<int>				v4;

	std::cout << "\n| RANGE |\n\n";
	v3.assign(v1.begin() + 1, v1.begin() + 7);
	v4.assign(v2.begin() + 1, v2.begin() + 7);

	check_size(v3, v4);
	check_capacity(v3, v4);
	check_content(v3, v4);

	v3.push_back(5); v3.push_back(4); v3.push_back(3); v3.push_back(2); v3.push_back(1);
	v4.push_back(5); v4.push_back(4); v4.push_back(3); v4.push_back(2); v4.push_back(1);
	v3.pop_back(); v4.pop_back();
	v3.pop_back(); v4.pop_back();

	check_size(v3, v4);
	check_capacity(v3, v4);
	check_content(v3, v4);
}

void	vector_test(void)
{
	assign_test();
}
