#include "srcs/Vector_functions.hpp"
#include <vector>

// DONE : enable_if, is_integral, equal/lexicographical compare,

// TO DO : reverse iterator for rbegin rend
// iterators_traits, reverse_iterator, 
// std::pair, std::make_pair, must be reimplemented.

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
	std::cout << "Copy constructor.\n";
	std::vector<int> fourth (third);                       // a copy of third

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
	if (v1.empty())
		std::cout << "v1 is empty\n";
	else
		std::cout << "v1 is not empty\n";
	std::cout << "Copy v2 in v1\n";
	v1 = v2;
	if (v1.empty())
		std::cout << "v1 is empty\n";
	else
		std::cout << "v1 is not empty\n";
	ft::vector<int> v3(v2.begin(),v2.end());  // iterating through second
	std::cout << "Copy constructor.\n";
	ft::vector<int> v4(v3);                       // a copy of third
                   // four ints with value 100
	std::cout << "The contents of 1 are:";
  	for (ft::vector<int>::iterator itv1 = v1.begin(); itv1 != v1.end(); ++itv1)
    	std::cout << ' ' << *itv1;
  	std::cout << "\n";
	std::cout << "The contents of 3 are:";
  	for (ft::vector<int>::iterator itv3 = v3.begin(); itv3 != v3.end(); ++itv3)
    	std::cout << ' ' << *itv3;
  	std::cout << "\n";

	std::cout << "\nLexicographical_compare:\n";	
	std::vector<int> foo (3,100);   // three ints with a value of 100
  	std::vector<int> bar (2,200);   // two ints with a value of 200
	ft::vector<int> foo1(3, 100);
	ft::vector<int> bar1(2, 200);
	if (foo< bar) std::cout << "[REAL] foo is less than bar\n";
	if (foo1< bar1) std::cout << "[MINE] foo is less than bar\n";
	if (foo> bar) std::cout << "[REAL] foo is less than bar\n";
	if (foo1> bar1) std::cout << "[MINE] foo is less than bar\n";

	std::cout << "\nEqual:\n";
	int myints[] = {20,40,60,80,100};
  	std::vector<int>myvector (myints,myints+5);
  	ft::vector<int>myvector1 (myints,myints+5);
	if ( std::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "[REAL] The contents of both sequences are equal.\n";
	else
		std::cout << "[REAL] The contents of both sequences differ.\n";
	if (ft::equal (myvector1.begin(), myvector1.end(), myints) )
		std::cout << "[MINE] The contents of both sequences are equal.\n";
	else
		std::cout << "[MINE] The contents of both sequences differ.\n";
	myvector[3] = 81; myvector1[3] = 81;
	if ( std::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "[REAL] The contents of both sequences are equal.\n";
	else
		std::cout << "[REAL] The contents of both sequences differ.\n";
	if (ft::equal (myvector1.begin(), myvector1.end(), myints) )
		std::cout << "[MINE] The contents of both sequences are equal.\n";
	else
		std::cout << "[MINE] The contents of both sequences differ.\n";

	std::cout << std::endl;
	std::cout << "Size:\t\t" << v1.size() << "\t\t\t" << v2.size() << std::endl;
	std::cout << "Capacity:\t" << v1.capacity() << "\t\t\t" << v2.capacity() << std::endl;
	std::cout << "Max size:\t" << v1.max_size() << "\t" << v2.max_size() << std::endl;
	v1.resize(10, 20);
	std::cout << "New size v1:\t\t" << v1.size() << std::endl;
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << "v1 [" << i << "] | " << v1[i] << std::endl;
	try 
	{
		v1.at(20)=100;      // vector::at throws an out-of-range
	}
	catch (const std::out_of_range& oor) {
    	std::cerr << "Out of Range error: " << oor.what() << '\n';
  	}

	std::cout << "Front: " << v1.front() << std::endl;
	std::cout << "Back: " << v1.back() << std::endl;

	v1.assign(v3.begin(), v3.end());
	std::cout << "Size:\t\t" << v1.size() << "\t\t\t" << v2.size() << std::endl;
	std::cout << "Cont.:\n";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << "v1 [" << i << "] | " << v1[i] << std::endl;

	v1.assign(15, 8);
	std::cout << "Size:\t\t" << v1.size() << "\t\t\t" << v2.size() << std::endl;
	std::cout << "Cont.:\n";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << "v1 [" << i << "] | " << v1[i] << std::endl;
	
	v1.push_back(9);
	std::cout << "v1 back: " << v1.back() << std::endl;
	v1.pop_back();
	std::cout << "v1 pop: " << v1.back() << std::endl;

	std::cout << "\nBef swap:\n";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << v1[i] << ' ';
	std::cout <<  std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << ' ';
	std::cout <<  std::endl;
	v1.swap(v2);
	std::cout << "Af swap:\n";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << v1[i] << ' ';
	std::cout <<  std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << ' ';
	std::cout <<  std::endl;
	swap(v1, v2);
	std::cout << "Af swap:\n";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << v1[i] << ' ';
	std::cout <<  std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << ' ';
	std::cout <<  std::endl;

	std::cout << "\nBefore insert:\n";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << "\n" << i << " | " << v1[i];
	std::cout << std::endl;
	v1.insert(v1.begin(), 2);
	std::cout << "\nSINGLE ELEMENT | Inserting one value:\n";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << "\n" << i << " | " << v1[i];
	std::cout << std::endl;

	const int val = 4;
	size_t n = 3;
	std::cout << "\nFILL | Inserting multiple values:\n";
	v1.insert(v1.begin(), n, val);
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << "\n" << i << " | " << v1[i];
	std::cout << std::endl;

	std::cout << "\nRANGE | Inserting multiple values:\n";
	v1.insert(v1.begin() + 3, v2.begin(), v2.begin() + 2);
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << "\n" << i << " | " << v1[i];
	std::cout << std::endl;

	std::cout << "\nSINGLE ELEMENT | Erasing one value:\n";
	v2.erase(v2.begin() + 2);
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << "\n" << i << " | " << v2[i];
	std::cout << std::endl;

	std::cout << "\nRANGE | Erasing multiple values:\n";
	v1.erase(v1.begin() + 3, v1.begin() + 5);
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << "\n" << i << " | " << v1[i];
	std::cout << std::endl;

    return 0;
}