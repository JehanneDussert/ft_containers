#include "Vector_functions.hpp"
#include <vector>

int main(void)
{
	std::cout << "** STD ONE **\n\n";
    std::vector<int> first;                                // empty vector of ints
	std::cout << "The contents of 1 are:";
  	for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::vector<int> second (4,100);                       // four ints with value 100
	std::cout << "The contents of 2 are:";
  	for (std::vector<int>::iterator itsec = second.begin(); itsec != second.end(); ++itsec)
    	std::cout << ' ' << *itsec;
  	std::cout << '\n';
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	// std::vector<int> fourth (third);                       // a copy of third

	std::cout << "\n\n** MINE **\n\n";
	ft::vector<int> v1;                                // empty vector of ints
	std::cout << "The contents of 1 are:";
	ft::vector<int>::iterator it2;
  	for (ft::vector<int>::iterator it2 = v1.begin(); it2 != v1.end(); ++it2)
    	std::cout << ' ' << *it2;
  	std::cout << "\n";

	ft::vector<int> v2(4,100);                       // four ints with value 100
	std::cout << "The contents of 2 are:";
  	for (ft::vector<int>::iterator itsec2 = v2.begin(); itsec2 != v2.end(); ++itsec2)
    	std::cout << ' ' << *itsec2;
  	std::cout << "\n";
	v1 = v2;
	ft::vector<int> v3(v2.begin(),v2.end());  // iterating through second
	// ft::vector<int> v4(v3);                       // a copy of third
                   // four ints with value 100
	std::cout << "The contents of 1 are:";
  	for (ft::vector<int>::iterator itv1 = v1.begin(); itv1 != v1.end(); ++itv1)
    	std::cout << ' ' << *itv1;
  	std::cout << "\n";
	std::cout << "The contents of 3 are:";
  	for (ft::vector<int>::iterator itv3 = v3.begin(); itv3 != v3.end(); ++itv3)
    	std::cout << ' ' << *itv3;
  	std::cout << "\n";


	std::cout << std::endl;
	std::cout << "Size:\t\t" << v1.size() << "\t\t\t" << v2.size() << std::endl;
	std::cout << "Capacity:\t" << v1.capacity() << "\t\t\t" << v2.capacity() << std::endl;
	std::cout << "Max size:\t" << v1.max_size() << "\t" << v2.max_size() << std::endl;
	v1.resize(10, 20);
	// std::cout << "New size v1:\t\t" << v1.size() << std::endl;

    return 0;
}