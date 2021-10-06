#include "srcs/Vector/Vector_functions.hpp"
#include "srcs/Utils/ReverseIterator.hpp"
#include <vector>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include "srcs/Map/Map_functions.hpp"
#include "srcs/Stack/Stack_functions.hpp"
#include <list>
#include <stack>
#include <map>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

void	print_content(TESTED_NAMESPACE::vector<int> &v)
{
	TESTED_NAMESPACE::vector<int>::iterator	it = v.begin();
	TESTED_NAMESPACE::vector<int>::iterator	ite = v.end();

	TESTED_NAMESPACE::vector<int>::const_iterator	cit = v.begin();
	TESTED_NAMESPACE::vector<int>::const_iterator	cite = v.end();
	
	TESTED_NAMESPACE::vector<int>::reverse_iterator	rev = v.rbegin();
	TESTED_NAMESPACE::vector<int>::reverse_iterator	reve = v.rend();

	std::cout << "Content :\n";
	for (; it != ite; ++it)
		std::cout << "\t\t" << *it << '\n';
	std::cout << "\n";

	std::cout << "Const it content :\n";
	for (; cit != cite; ++cit)
		std::cout << "\t\t" << *cit << '\n';
	std::cout << "\n";

	std::cout << "Reverse content :\n";
	for (; rev != reve; ++rev)
		std::cout << "\t\t" << *rev << '\n';
	std::cout << "\n";
}

void	print_size(TESTED_NAMESPACE::vector<int> &v)
{
	std::cout << "EMPTY\t\t" << v.empty() << std::endl;
	std::cout << "SIZE\t\t" << v.size() << std::endl;
	std::cout << "MAX_SIZE\t" << v.max_size() << std::endl;
}

void	print_capacity(TESTED_NAMESPACE::vector<int> &v)
{
	std::cout << "CAPACITY\t" << v.capacity() << std::endl;
}
void	print_content(TESTED_NAMESPACE::map<int, int> &m)
{
	TESTED_NAMESPACE::map<int, int>::iterator	it = m.begin();
	TESTED_NAMESPACE::map<int, int>::iterator	ite = m.end();
	
	TESTED_NAMESPACE::map<int, int>::reverse_iterator	rev = m.rbegin();
	TESTED_NAMESPACE::map<int, int>::reverse_iterator	reve = m.rend();

	std::cout << "Content :\n";
	for (; it != ite; ++it)
		std::cout << "\t\t" << "Key: " << it->first << "\tVal: " << it->second << '\n';
	std::cout << "\n";

	std::cout << "Reverse content :\n";
	for (; rev != reve; ++rev)
		std::cout << "\t\t" << "Key: " << rev->first << "\tVal: " << rev->second << '\n';
	std::cout << "\n";
}

void	print_size(TESTED_NAMESPACE::map<int, int> &v)
{
	std::cout << "EMPTY\t\t" << v.empty() << std::endl;
	std::cout << "SIZE\t\t" << v.size() << std::endl;
	std::cout << "MAX_SIZE\t" << v.max_size() << std::endl;
}

void	vector()
{
	std::cout << "VECTOR\n\n";
	std::cout << "********************\n\n";

	std::cout << "constructor & empty & size\n";
	std::cout << "#################################\n";

	TESTED_NAMESPACE::vector<int>	v;
	TESTED_NAMESPACE::vector<int>	v1;
	TESTED_NAMESPACE::vector<int>	v_fill(8, 10);
	TESTED_NAMESPACE::vector<int>	v_range(v_fill.begin() + 2, v_fill.end() - 3);
	TESTED_NAMESPACE::vector<int>	v_copy(v_range);
	TESTED_NAMESPACE::vector<int>	const v_const(5, 2);

	std::cout << "\nempty vector\n";
	std::cout << "#################################\n";
	print_content(v); print_size(v); print_capacity(v);

	std::cout << "\nfill vector\n";
	std::cout << "#################################\n";
	print_content(v_fill); print_size(v_fill); print_capacity(v_fill);
	std::cout << "FRONT\t\t" << v_fill.front() << std::endl;
	std::cout << "BACK\t\t" << v_fill.back() << std::endl;
	std::cout << "AT\t\t" << v_fill.at(2) << std::endl;

	std::cout << "\nrange vector\n";
	std::cout << "#################################\n";
	print_content(v_range); print_size(v_range); print_capacity(v_range);
	std::cout << "FRONT\t\t" << v_range.front() << std::endl;
	std::cout << "BACK\t\t" << v_range.back() << std::endl;
	std::cout << "AT\t\t" << v_range.at(2) << std::endl;

	std::cout << "\ncopy vector\n";
	std::cout << "#################################\n";
	print_content(v_copy); print_size(v_copy); print_capacity(v_copy);
	std::cout << "FRONT\t\t" << v_copy.front() << std::endl;
	std::cout << "BACK\t\t" << v_copy.back() << std::endl;
	std::cout << "AT\t\t" << v_copy.at(2) << std::endl;

	std::cout << "\nconst vector\n";
	std::cout << "#################################\n";
	std::cout << "FRONT\t\t" << v_const.front() << std::endl;
	std::cout << "BACK\t\t" << v_const.back() << std::endl;
	std::cout << "AT\t\t" << v_const.at(2) << std::endl;

	std::cout << "\nassign (fill)\n";
	std::cout << "#################################\n";
	v.assign(5, 54);
	v.push_back(6);
	print_content(v); print_size(v); print_capacity(v);
	std::cout << "FRONT\t\t" << v.front() << std::endl;
	std::cout << "BACK\t\t" << v.back() << std::endl;
	std::cout << "AT\t\t" << v.at(2) << std::endl;

	std::cout << "\nassign (range)\n";
	std::cout << "#################################\n";
	v1.assign(v_fill.begin() + 1, v_fill.begin() + 3);
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "FRONT\t\t" << v1.front() << std::endl;
	std::cout << "BACK\t\t" << v1.back() << std::endl;
	std::cout << "AT\t\t" << v1.at(1) << std::endl;

	std::cout << "\nclear\n";
	std::cout << "#################################\n";
	v1.clear();
	print_content(v1); print_size(v1); print_capacity(v1);

	std::cout << "\ninsert (7, 4, 10)\n";
	std::cout << "#################################\n";
	v1.insert(v1.begin(), 10);
	v1.insert(v1.begin(), 4);
	v1.insert(v1.begin(), 7);
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "FRONT\t\t" << v1.front() << std::endl;
	std::cout << "BACK\t\t" << v1.back() << std::endl;
	std::cout << "AT\t\t" << v1.at(1) << std::endl;

	std::cout << "\nerase (7)\n";
	std::cout << "#################################\n";
	v1.erase(v1.begin(), v1.begin() + 1);
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "FRONT\t\t" << v1.front() << std::endl;
	std::cout << "BACK\t\t" << v1.back() << std::endl;
	std::cout << "AT\t\t" << v1.at(1) << std::endl;

	std::cout << "\noperators\n";
	std::cout << "#################################\n";
	std::cout << "* v1 becomes a copy of v_fill\n";

	v1 = v_fill;

	std::cout << "v1 = v2:\t" << (v1 == v_fill) << std::endl;
	std::cout << "v1 != v2:\t" << (v1 != v_fill) << std::endl;

	std::cout << "\n* Pop last elem of v1\n";
	v1.pop_back();

	std::cout << "v1 < v2:\t" << (v1 < v_fill) << std::endl;
	std::cout << "v1 > v2:\t" << (v1 > v_fill) << std::endl;

	std::cout << "\n* Check operator[] | v1[2] = 10\n";
	std::cout << "v1[2] = " << v1[2] << std::endl;

	std::cout << "\nreserve\n";
	std::cout << "#################################\n";
	v1.reserve(18);
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "FRONT\t\t" << v1.front() << std::endl;
	std::cout << "BACK\t\t" << v1.back() << std::endl;
	std::cout << "AT\t\t" << v1.at(1) << std::endl;

	std::cout << "\nresize\n";
	std::cout << "#################################\n";
	v1.resize(2);
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "FRONT\t\t" << v1.front() << std::endl;
	std::cout << "BACK\t\t" << v1.back() << std::endl;
	std::cout << "AT\t\t" << v1.at(1) << std::endl;

	v_range.push_back(18);
	v_range.push_back(7);
	v_range.push_back(2);
	v_range.push_back(1);
	v_range.push_back(98);

	std::cout << "\nswap\n";
	std::cout << "#################################\n";
	std::cout << "* Before swap:\n";
	std::cout << "v1 is :\n";
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "\nv_range is :\n";
	print_content(v_range); print_size(v_range); print_capacity(v_range);

	v1.swap(v_range);

	std::cout << "\n* After swap:\n";
	std::cout << "v1 is :\n";
	print_content(v1); print_size(v1); print_capacity(v1);
	std::cout << "\nv_range is :\n";
	print_content(v_range); print_size(v_range); print_capacity(v_range);
}

void	stack()
{
	std::cout << "\n\nSTACK\n\n";
	std::cout << "********************\n\n";

	std::cout << "\nconstructor & empty & size\n";
	std::cout << "#################################\n";

	TESTED_NAMESPACE::stack<int> stack;
	TESTED_NAMESPACE::stack<int> copy_stack;

	std::cout << stack.size() << std::endl;
	std::cout << stack.empty() << std::endl;

	stack.push(10);
	stack.push(2);
	stack.push(4);
	stack.push(18);

	std::cout << stack.size() << std::endl;
	std::cout << stack.empty() << std::endl;

	std::cout << "\ncopy stack\n";
	std::cout << "#################################\n";

	copy_stack = stack;
	std::cout << "SIZE\t| Srcs: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Srcs: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t| Srcs: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;

	std::cout << "\npop last elem (18)\n";
	std::cout << "#################################\n";

	stack.pop();

	std::cout << "SIZE\t| Srcs: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Srcs: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t| Srcs: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;

	std::cout << "\ncompare stack1 < stack2\n";
	std::cout << "#################################\n";

	std::cout << "stack1 = stack2:\t" << (stack == copy_stack) << std::endl;
	std::cout << "stack1 != stack2:\t" << (stack != copy_stack) << std::endl;
	std::cout << "stack1 < stack2:\t" << (stack < copy_stack) << std::endl;
	std::cout << "stack1 > stack2:\t" << (stack > copy_stack) << std::endl;

	std::cout << "\nswap\n";
	std::cout << "#################################\n";
	std::cout << "* Before swap:\n";
	std::cout << "SIZE\t| Srcs: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Srcs: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t| Srcs: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;
	std::cout << "SIZE\t| Srcs: " << copy_stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Srcs: " << copy_stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t| Srcs: " << copy_stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;

	swap(stack, copy_stack);

	std::cout << "* After swap:\n";
	std::cout << "SIZE\t| Srcs: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Srcs: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t| Srcs: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;
	std::cout << "SIZE\t| Srcs: " << copy_stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "EMPTY\t| Srcs: " << copy_stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "TOP\t| Srcs: " << copy_stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;
}

void	map()
{
	std::cout << "\n\nMAP\n\n";
	std::cout << "********************\n\n";

	std::cout << "constructor & insert\n";
	std::cout << "#################################\n";

	TESTED_NAMESPACE::map<int, int>	m;
	TESTED_NAMESPACE::map<int, int>	m1;
	TESTED_NAMESPACE::map<int, int>	const m2;

	TESTED_NAMESPACE::pair <int,int>			foo;
  	TESTED_NAMESPACE::pair <int,int>			bar;
	TESTED_NAMESPACE::pair <int,int>			foo1;
  	TESTED_NAMESPACE::pair <int,int>			bar1;
	TESTED_NAMESPACE::pair <int,int>			foo2;
  	TESTED_NAMESPACE::pair <int,int>			bar2;
	TESTED_NAMESPACE::pair <int,int>			n1;
  	TESTED_NAMESPACE::pair <int,int>			n2;
	TESTED_NAMESPACE::pair <int,int>			n3;
  	TESTED_NAMESPACE::pair <int,int>			n4;
	TESTED_NAMESPACE::pair <int,int>			n5;
  	TESTED_NAMESPACE::pair <int,int>			n6;

	foo = TESTED_NAMESPACE::make_pair(10, 20);
  	bar = TESTED_NAMESPACE::make_pair(30, 78);
	foo1 = TESTED_NAMESPACE::make_pair(2, 198);
  	bar1 = TESTED_NAMESPACE::make_pair(12, 78);
	foo2 = TESTED_NAMESPACE::make_pair(10, 19);
  	bar2 = TESTED_NAMESPACE::make_pair(85, 5);
  	n1 = TESTED_NAMESPACE::make_pair(38, 2);
  	n2 = TESTED_NAMESPACE::make_pair(0, 56);
  	n3 = TESTED_NAMESPACE::make_pair(1, 2);
  	n4 = TESTED_NAMESPACE::make_pair(99, 7845);
  	n5 = TESTED_NAMESPACE::make_pair(89732, 2);
  	n6 = TESTED_NAMESPACE::make_pair(-1982, 2);

	m1.insert(foo);
	m1.insert(bar);
	m1.insert(foo1);
	m1.insert(bar1);
	m1.insert(foo2);
	m1.insert(bar2);
	m1.insert(n1);
	m1.insert(n2);
	m1.insert(n3);
	m1.insert(n4);
	m1.insert(n5);
	m1.insert(n6);

	TESTED_NAMESPACE::map<int, int>	m_range(++m1.begin(), --m1.end());
	TESTED_NAMESPACE::map<int, int>	m_copy(m_range);

	std::cout << "\nempty map\n";
	std::cout << "#################################\n";
	print_content(m); print_size(m);

	std::cout << "\ninsert(val)\n";
	std::cout << "#################################\n";
	print_content(m1); print_size(m1);

	std::cout << "\nrange map\n";
	std::cout << "#################################\n";
	print_content(m_range); print_size(m_range);

	std::cout << "\ncopy map\n";
	std::cout << "#################################\n";
	print_content(m_copy); print_size(m_copy);

  	TESTED_NAMESPACE::pair <int,int>			elem;
	elem = TESTED_NAMESPACE::make_pair(-8, 76823);
	m_copy.insert(++(++(m_copy.begin())), elem);

	std::cout << "\ninsert map (pos, val)\n";
	std::cout << "#################################\n";
	print_content(m_copy); print_size(m_copy);

	std::cout << "\ninsert map (begin, end)\n";
	std::cout << "#################################\n";
	m.insert(m_copy.begin(), --(--(m_copy.end())));
	print_content(m); print_size(m);

	std::cout << "\nerase(pos)\n";
	std::cout << "#################################\n";
	std::cout << "* Before erase:\n";
	print_content(m_copy); print_size(m_copy);

	m_copy.erase(++m_copy.begin());

	std::cout << "* After erase:\n";
	print_content(m_copy); print_size(m_copy);

	std::cout << "\nerase(key)\n";
	std::cout << "#################################\n";
	std::cout << "* Before erase:\n";
	print_content(m_copy); print_size(m_copy);

	m_copy.erase(12);
	
	std::cout << "* After erase:\n";
	print_content(m_copy); print_size(m_copy);

	std::cout << "\nerase(begin, end)\n";
	std::cout << "#################################\n";
	std::cout << "* Before erase:\n";
	print_content(m_copy); print_size(m_copy);

	m_copy.erase(m_copy.begin(), --m_copy.end());
	
	std::cout << "* After erase:\n";
	print_content(m_copy); print_size(m_copy);

	std::cout << "\nswap\n";
	std::cout << "#################################\n";
	std::cout << "* Before swap:\n";
	print_content(m_copy); print_size(m_copy);
	print_content(m); print_size(m);

	m_copy.swap(m);

	std::cout << "* After swap:\n";
	print_content(m_copy); print_size(m_copy);
	print_content(m); print_size(m);

	std::cout << "\nFind\n";
	std::cout << "#################################\n";
	std::cout << "res: " << m_copy.find(38)->first << std::endl;

	std::cout << "\nCount\n";
	std::cout << "#################################\n";
	std::cout << "res: " << m_copy.count(38) << std::endl;

	std::cout << "\nClear\n";
	std::cout << "#################################\n";
	m_copy.clear();
	print_content(m_copy); print_size(m_copy);
}

int main(void)
{
	vector();
	stack();
	map();

    return 0;
}


