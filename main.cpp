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
	// std::vector<int> third (second.begin(),second.end());  // iterating through second
	// std::vector<int> fourth (third);                       // a copy of third

	std::cout << "\n\n** MINE **\n\n";
	ft::vector<int> v1;                                // empty vector of ints
	std::cout << "The contents of 1 are:";
	ft::vector<int>::iterator it2;
  	for (ft::vector<int>::iterator it2 = v1.begin(); it2 != v1.end(); ++it2)
    	std::cout << ' ' << *it2;
  	std::cout << "\n";

	ft::vector<int> v2(4,100);                       // four ints with value 100
	std::cout << "\nThe contents of 2 are:";
  	for (ft::vector<int>::iterator itsec2 = v2.begin(); itsec2 != v2.end(); ++itsec2)
    	std::cout << ' ' << *itsec2;
  	std::cout << "\n";
	v1 = v2;
	// ft::vector<int> v3(v2.begin(),v2.end());  // iterating through second
	// ft::vector<int> v4(v3);                       // a copy of third
                   // four ints with value 100
	std::cout << "\nThe contents of 1 are:";
  	for (ft::vector<int>::iterator itv1 = v1.begin(); itv1 != v1.end(); ++itv1)
    	std::cout << ' ' << *itv1;
  	std::cout << "\n";

    return 0;
}