#include "srcs/Vector/Vector_functions.hpp"
#include "srcs/Utils/ReverseIterator.hpp"
#include <vector>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include "srcs/Map/Map_functions.hpp"
#include "test.hpp"

// int main(void)
// {
// 	// std::cout << "** STD ONE **\n\n";
//     // std::vector<int> first;                                // empty vector of ints
// 	// std::cout << "The contents of 1 are:";
//   	// for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
//     // 	std::cout << ' ' << *it;
//   	// std::cout << '\n';

// 	// std::vector<int> second (4,100);                       // four ints with value 100
// 	// std::cout << "The contents of 2 are:";
//   	// for (std::vector<int>::iterator itsec = second.begin(); itsec != second.end(); ++itsec)
//     // 	std::cout << ' ' << *itsec;
//   	// std::cout << '\n';
// 	// std::vector<int> third (second.begin(),second.end());  // iterating through second
// 	// std::cout << "Copy constructor.\n";
// 	// std::vector<int> fourth (third);                       // a copy of third

// 	// std::cout << "\n\n** MINE **\n\n";
// 	// ft::vector<int> v1;                                // empty vector of ints
// 	// std::cout << "The contents of 1 are:";
// 	// ft::vector<int>::iterator it2;
//   	// for (ft::vector<int>::iterator it2 = v1.begin(); it2 != v1.end(); ++it2)
//     // 	std::cout << ' ' << *it2;
//   	// std::cout << "\n";

// 	// ft::vector<int> v2(4,100);                       // four ints with value 100
// 	// std::cout << "The contents of 2 are:";
//   	// for (ft::vector<int>::iterator itsec2 = v2.begin(); itsec2 != v2.end(); ++itsec2)
//     // 	std::cout << ' ' << *itsec2;
//   	// std::cout << "\n";
// 	// if (v1.empty())
// 	// 	std::cout << "v1 is empty\n";
// 	// else
// 	// 	std::cout << "v1 is not empty\n";
// 	// std::cout << "Copy v2 in v1\n";
// 	// v1 = v2;
// 	// if (v1.empty())
// 	// 	std::cout << "v1 is empty\n";
// 	// else
// 	// 	std::cout << "v1 is not empty\n";
// 	// ft::vector<int> v3(v2.begin(),v2.end());  // iterating through second
// 	// std::cout << "Copy constructor.\n";
// 	// ft::vector<int> v4(v3);                       // a copy of third
//     //                // four ints with value 100
// 	// std::cout << "The contents of 1 are:";
//   	// for (ft::vector<int>::iterator itv1 = v1.begin(); itv1 != v1.end(); ++itv1)
//     // 	std::cout << ' ' << *itv1;
//   	// std::cout << "\n";
// 	// std::cout << "The contents of 3 are:";
//   	// for (ft::vector<int>::iterator itv3 = v3.begin(); itv3 != v3.end(); ++itv3)
//     // 	std::cout << ' ' << *itv3;
//   	// std::cout << "\n";

// 	// std::cout << "\nLexicographical_compare:\n";	
// 	// std::vector<int> foo (3,100);   // three ints with a value of 100
//   	// std::vector<int> bar (2,200);   // two ints with a value of 200
// 	// ft::vector<int> foo1(3, 100);
// 	// ft::vector<int> bar1(2, 200);
// 	// if (foo< bar) std::cout << "[REAL] foo is less than bar\n";
// 	// if (foo1< bar1) std::cout << "[MINE] foo is less than bar\n";
// 	// if (foo> bar) std::cout << "[REAL] foo is less than bar\n";
// 	// if (foo1> bar1) std::cout << "[MINE] foo is less than bar\n";

// 	// std::cout << "\nEqual:\n";
// 	// int myints[] = {20,40,60,80,100};
//   	// std::vector<int>myvector (myints,myints+5);
//   	// ft::vector<int>myvector1 (myints,myints+5);
// 	// if ( std::equal (myvector.begin(), myvector.end(), myints) )
// 	// 	std::cout << "[REAL] The contents of both sequences are equal.\n";
// 	// else
// 	// 	std::cout << "[REAL] The contents of both sequences differ.\n";
// 	// if (ft::equal (myvector1.begin(), myvector1.end(), myints) )
// 	// 	std::cout << "[MINE] The contents of both sequences are equal.\n";
// 	// else
// 	// 	std::cout << "[MINE] The contents of both sequences differ.\n";
// 	// myvector[3] = 81; myvector1[3] = 81;
// 	// if ( std::equal (myvector.begin(), myvector.end(), myints) )
// 	// 	std::cout << "[REAL] The contents of both sequences are equal.\n";
// 	// else
// 	// 	std::cout << "[REAL] The contents of both sequences differ.\n";
// 	// if (ft::equal (myvector1.begin(), myvector1.end(), myints) )
// 	// 	std::cout << "[MINE] The contents of both sequences are equal.\n";
// 	// else
// 	// 	std::cout << "[MINE] The contents of both sequences differ.\n";

// 	// std::cout << std::endl;
// 	// std::cout << "Size:\t\t" << v1.size() << "\t\t\t" << v2.size() << std::endl;
// 	// std::cout << "Capacity:\t" << v1.capacity() << "\t\t\t" << v2.capacity() << std::endl;
// 	// std::cout << "Max size:\t" << v1.max_size() << "\t" << v2.max_size() << std::endl;
// 	// v1.resize(10, 20);
// 	// std::cout << "New size v1:\t\t" << v1.size() << std::endl;
// 	// for (size_t i = 0; i < v1.size(); i++)
// 	// 	std::cout << "v1 [" << i << "] | " << v1[i] << std::endl;
// 	// try 
// 	// {
// 	// 	v1.at(20)=100;      // vector::at throws an out-of-range
// 	// }
// 	// catch (const std::out_of_range& oor) {
//     // 	std::cerr << "Out of Range error: " << oor.what() << '\n';
//   	// }

// 	// std::cout << "Front: " << v1.front() << std::endl;
// 	// std::cout << "Back: " << v1.back() << std::endl;

// 	// v1.assign(v3.begin(), v3.end());
// 	// std::cout << "Size:\t\t" << v1.size() << "\t\t\t" << v2.size() << std::endl;
// 	// std::cout << "Cont.:\n";
// 	// for (size_t i = 0; i < v1.size(); i++)
// 	// 	std::cout << "v1 [" << i << "] | " << v1[i] << std::endl;

// 	// v1.assign(15, 8);
// 	// std::cout << "Size:\t\t" << v1.size() << "\t\t\t" << v2.size() << std::endl;
// 	// std::cout << "Cont.:\n";
// 	// for (size_t i = 0; i < v1.size(); i++)
// 	// 	std::cout << "v1 [" << i << "] | " << v1[i] << std::endl;
	
// 	// v1.push_back(9);
// 	// std::cout << "v1 back: " << v1.back() << std::endl;
// 	// v1.pop_back();
// 	// std::cout << "v1 pop: " << v1.back() << std::endl;

// 	// std::cout << "\nBef swap:\n";
// 	// for (size_t i = 0; i < v1.size(); i++)
// 	// 	std::cout << v1[i] << ' ';
// 	// std::cout <<  std::endl;
// 	// for (size_t i = 0; i < v2.size(); i++)
// 	// 	std::cout << v2[i] << ' ';
// 	// std::cout <<  std::endl;
// 	// v1.swap(v2);
// 	// std::cout << "Af swap:\n";
// 	// for (size_t i = 0; i < v1.size(); i++)
// 	// 	std::cout << v1[i] << ' ';
// 	// std::cout <<  std::endl;
// 	// for (size_t i = 0; i < v2.size(); i++)
// 	// 	std::cout << v2[i] << ' ';
// 	// std::cout <<  std::endl;
// 	// swap(v1, v2);
// 	// std::cout << "Af swap:\n";
// 	// for (size_t i = 0; i < v1.size(); i++)
// 	// 	std::cout << v1[i] << ' ';
// 	// std::cout <<  std::endl;
// 	// for (size_t i = 0; i < v2.size(); i++)
// 	// 	std::cout << v2[i] << ' ';
// 	// std::cout <<  std::endl;

// 	// std::cout << "\nBefore insert:\n";
// 	// for (size_t i = 0; i < v1.size(); i++)
// 	// 	std::cout << "\n" << i << " | " << v1[i];
// 	// std::cout << std::endl;
// 	// v1.insert(v1.begin(), 2);
// 	// std::cout << "\nSINGLE ELEMENT | Inserting one value:\n";
// 	// for (size_t i = 0; i < v1.size(); i++)
// 	// 	std::cout << "\n" << i << " | " << v1[i];
// 	// std::cout << std::endl;

// 	// const int val = 4;
// 	// size_t n = 3;
// 	// std::cout << "\nFILL | Inserting multiple values:\n";
// 	// v1.insert(v1.begin(), n, val);
// 	// for (size_t i = 0; i < v1.size(); i++)
// 	// 	std::cout << "\n" << i << " | " << v1[i];
// 	// std::cout << std::endl;

// 	// std::cout << "\nRANGE | Inserting multiple values:\n";
// 	// v1.insert(v1.begin() + 3, v2.begin(), v2.begin() + 2);
// 	// for (size_t i = 0; i < v1.size(); i++)
// 	// 	std::cout << "\n" << i << " | " << v1[i];
// 	// std::cout << std::endl;

// 	// std::cout << "\nSINGLE ELEMENT | Erasing one value:\n";
// 	// v2.erase(v2.begin() + 2);
// 	// for (size_t i = 0; i < v2.size(); i++)
// 	// 	std::cout << "\n" << i << " | " << v2[i];
// 	// std::cout << std::endl;

// 	// std::cout << "\nRANGE | Erasing multiple values:\n";
// 	// v1.erase(v1.begin() + 3, v1.begin() + 5);
// 	// for (size_t i = 0; i < v1.size(); i++)
// 	// 	std::cout << "\n" << i << " | " << v1[i];
// 	// std::cout << std::endl;
// 	// ft::vector<int>::reverse_iterator	rit1 = v1.rbegin();
// 	// ft::vector<int>::reverse_iterator	rit2 = v2.rbegin();
// 	// (void)rit1;
// 	// (void)rit2;

// 	// typedef std::iterator_traits<int*> traits;
// 	// if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
// 	// 	std::cout << "int* is a random-access iterator";

// 	// typedef ft::vector<int>::iterator_traits<int*> traits1;
// 	// if (typeid(traits1::iterator_category)==typeid(std::random_access_iterator_tag))
// 	// 	std::cout << "int* is a random-access iterator";

// 	// std::cout << std::boolalpha;
// 	// std::cout << "is_integral:" << std::endl;
// 	// std::cout << "char: " << std::is_integral<char>::value << std::endl;
// 	// std::cout << "int: " << std::is_integral<int>::value << std::endl;
// 	// std::cout << "float: " << std::is_integral<float>::value << std::endl;

// 	// std::cout << std::boolalpha;
// 	// std::cout << "is_integral:" << std::endl;
// 	// std::cout << "char: " << ft::is_integral<char>::value << std::endl;
// 	// std::cout << "int: " << ft::is_integral<int>::value << std::endl;
// 	// std::cout << "float: " << ft::is_integral<float>::value << std::endl;

// 	// ft::map<int, int>			ft_map;
// 	// ft::map<int, int>::node_ptr	root = NULL;
// 	// ft::pair <int,int>			foo1;
//   	// ft::pair <int,int>			bar1;
// 	// foo1 = ft::make_pair (10,20);
//   	// bar1 = ft::make_pair (30.5,'A');

// 	// // ft_map.insert(foo1);
//     // root = ft_map.insert(root, foo1);
//     // root = ft_map.insert(root, bar1);
// 	// std::cout << "Inorder BST:\n";
// 	// ft_map.inorder(root);
// 	// std::cout << std::endl;

// 	// ft::pair <int,int>			foo2;
//   	// ft::pair <int,int>			bar2;
// 	// foo2 = ft::make_pair (60,900);
//   	// bar2 = ft::make_pair (1.5,'z');
//     // root = ft_map.insert(root, foo2);
//     // root = ft_map.insert(root, bar2);
// 	// std::cout << "Inorder BST:\n";
// 	// ft_map.inorder(root);
// 	// std::cout << std::endl;

// 	ft::map<int, int>			ft_map;
// 	ft::pair <int,int>			foo;
// 	foo = ft::make_pair(5, 10);
// 	ft_map.insert(foo);

// 	ft::pair <int,int>			bar;
// 	bar = ft::make_pair(2, 7);
// 	ft_map.insert(bar);

// 	ft::pair <int,int>			kikoo;
// 	std::cout << "-- insert val\n";
// 	kikoo = ft::make_pair(90, 4);
// 	ft_map.insert(kikoo);
// 	ft::pair <int,int>			lol;
// 	lol = ft::make_pair(1, 8);
// 	ft_map.insert(lol);

// 	// ft::pair <int,int>			xd;
// 	// xd = ft::make_pair(90, 3);
// 	// ft_map.insert(xd);

// 	ft::pair <int,int>			mdlol;
// 	mdlol = ft::make_pair(9, 6);
// 	ft_map.insert(mdlol);

// 	ft::pair <int,int>			test;
// 	std::cout << "\n\n-- insert key\n";
// 	test = ft::make_pair(0, 2);
// 	ft_map.insert(test);


// 	ft::pair <int,int>			right;
// 	right = ft::make_pair(100, 66);
// 	ft_map.insert(right);

// 	ft::pair <int,int>			right1;
// 	right1 = ft::make_pair(3, 28);
// 	ft_map.insert(right1);
// 	std::cout << "\nEND\n";

// 	std::cout << "-- Before erase --\n";
// 	ft::map<int, int>::const_iterator it = ft_map.begin();
// 	for (; it != ft_map.end(); ++it)
// 	{
//     	std::cout << "Key: " << it->first;
//     	std::cout << "\t\tVal: " << it->second << std::endl;
// 		// std::cout << "Map: " << ft_map[it->second] << "\t\tVal: " << ft_map[it->first] << "\n\n";
// 	}

// 	std::cout << "-- After erase --\n";
// 	ft_map.erase(0);
// 	for (ft::map<int, int>::const_iterator it = ft_map.begin(); it != ft_map.end(); ++it)
// 	{
//     	std::cout << "Key: " << it->first;
//     	std::cout << "\t\tVal: " << it->second << std::endl;
// 		// std::cout << "Map: " << ft_map[it->second] << "\t\tVal: " << ft_map[it->first] << "\n\n";
// 	}
// 	std::cout << "-- After erase --\n";
// 	ft_map.erase(100);
// 	for (ft::map<int, int>::const_iterator it = ft_map.begin(); it != ft_map.end(); ++it)
// 	{
//     	std::cout << "Key: " << it->first;
//     	std::cout << "\t\tVal: " << it->second << std::endl;
// 		// std::cout << "Map: " << ft_map[it->second] << "\t\tVal: " << ft_map[it->first] << "\n\n";
// 	}

// 	ft_map.erase(ft_map.begin(), ft_map.end());
// 	std::cout << "erase everything\n";
// 	for (ft::map<int, int>::const_iterator it = ft_map.begin(); it != ft_map.end(); ++it)
// 	{
//     	std::cout << "Key: " << it->first;
//     	std::cout << "\t\tVal: " << it->second << std::endl;
// 		// std::cout << "Map: " << ft_map[it->second] << "\t\tVal: " << ft_map[it->first] << "\n\n";
// 	}
	
// 	/* begin */

// 	// std::map<int, int>			std_map;
// 	// std::pair <int,int>			foo1;
// 	// foo1 = std::make_pair(5, 10);
// 	// std_map.insert(foo1);

// 	// std::pair <int,int>			bar1;
// 	// bar1 = std::make_pair(2, 7);
// 	// std_map.insert(bar1);

// 	// std::pair <int,int>			kikoo1;
// 	// kikoo1 = std::make_pair(90, 4);
// 	// std_map.insert(kikoo1);
// 	// std::pair <int,int>			lol1;
// 	// lol1 = std::make_pair(1, 8);
// 	// std_map.insert(lol1);

// 	// // std::pair <int,int>			xd1;
// 	// // xd1 = std::make_pair(90, 3);
// 	// // std_map.insert(xd1);

// 	// std::pair <int,int>			mdlol1;
// 	// mdlol1 = std::make_pair(9, 6);
// 	// std_map.insert(mdlol1);

// 	// std::pair <int,int>			test1;
// 	// test1 = std::make_pair(0, 2);
// 	// std_map.insert(test1);
// 	// std::cout << "-- Before erase --\n";
// 	// for (std::map<int, int>::const_iterator it = std_map.begin(); it != std_map.end(); ++it)
// 	// {
//     // 	std::cout << "Key: " << it->first;
//     // 	std::cout << "\t\tVal: " << it->second << std::endl;
// 	// 	std::cout << "Map: " << it->first << "\t\tVal: " << std_map[it->first] << "\n\n";
// 	// }
// 	// // ft::map<int, int>::const_iterator it = ft_map.begin();
// 	// std::cout << "-- After erase --\n";
// 	// std_map.erase(std_map.begin());
// 	// for (std::map<int, int>::const_iterator it = std_map.begin(); it != std_map.end(); ++it)
// 	// {
//     // 	std::cout << "Key: " << it->first;
//     // 	std::cout << "\t\tVal: " << it->second << std::endl;
// 	// 	std::cout << "Map: " << it->first << "\t\tVal: " << std_map[it->first] << "\n\n";
// 	// }

// 	/* end */

//     return 0;
// }



#include <map>
#include <iostream>
#include <string>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

#define _pair TESTED_NAMESPACE::pair

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T1, typename T2>
void	printReverse(TESTED_NAMESPACE::map<T1, T2> &mp)
{
	typename TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}



#include <list>

#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator iterator;

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	_pair<iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert(MAP &mp, U param, V param2)
{
	iterator tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param, param2);
	std::cout << "insert return: " << printPair(tmp);
	printSize(mp);
}

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp, mp2;

	ft_insert(mp, T3(42, "lol"));
	ft_insert(mp, T3(42, "mdr"));

	ft_insert(mp, T3(50, "mdr"));
	// ft_insert(mp, T3(35, "funny"));

	// ft_insert(mp, T3(45, "bunny"));
	// ft_insert(mp, T3(21, "fizz"));
	// ft_insert(mp, T3(38, "buzz"));

	// ft_insert(mp, mp.begin(), T3(55, "fuzzy"));

	// std::cout << "HERE\n";
	// ft_insert(mp2, mp2.begin(), T3(1337, "beauty"));
	// ft_insert(mp2, mp2.end(), T3(1000, "Hello"));
	// ft_insert(mp2, mp2.end(), T3(1500, "World"));

	return (0);
}