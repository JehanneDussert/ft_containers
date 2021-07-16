#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <iterator>

namespace ft
{

	template<bool Cond, class E = void>
	struct enable_if {};

	template<class E> 
	struct enable_if<true, E>
	{
		typedef E type;
	};
}

#endif