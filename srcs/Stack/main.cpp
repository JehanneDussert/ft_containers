#include "Stack_functions.hpp"

int main(void)
{
    ft::stack<int>  s1;
    ft::stack<int>  s2;

	std::cout << s1.empty() << std::endl;
	std::cout << s1.size() << std::endl;
	s1.push(10);
	std::cout << s1.empty() << std::endl;
	std::cout << s1.size() << std::endl;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	std::cout << s1.size() << std::endl;
	s1.pop();
	std::cout << s1.size() << std::endl;
	std::cout << s1.top() << std::endl;

	s2.push(8);
	s2.push(4);
	std::cout << s2.size() << std::endl;
	std::cout << s2.top() << std::endl;

	std::cout << (s1 < s2) << std::endl;
	std::cout << (s1 == s2) << std::endl;

    return 0;
}
