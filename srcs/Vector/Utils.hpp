#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <iterator>
# include <sstream>
# include "Vector.hpp"

namespace ft
{

	template<bool Cond, class E = void>
	struct enable_if {};

	template<class E> 
	struct enable_if<true, E>
	{
		typedef E type;
	};

	// ?
	// template <class I = int>
	// struct is_integral {};
	
	// template<class I> 
	// struct is_integral<true, I>
	// {
	// 	typedef I type;
	// };

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1) return false;
			else if (*first1 < *first2) return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || !comp(*first2, *first1)) return false;
			else if (comp(*first1, *first2)) return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	typedef size_t										size_type;
	// template<typename T, typename Alloc>
	template <class InputIterator>
	size_type	iterator_len(InputIterator first, InputIterator last)
	{
		size_type i = 0;
		while (first != last)
		{
			first++;
			i++;
		}
		return i;
	}
}

#endif