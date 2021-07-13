#include "Vector_functions.hpp"

int main(void)
{
    //ft::vector<int> test(1, 2);
	ft::vector<int>				v;
	ft::vector<int>				v2(10);
	ft::vector<int>::iterator	it;

	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;


	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	v2.push_back(5);
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;


    return 0;
}