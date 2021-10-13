#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <iterator>
# include <sstream>
# include "ReverseIterator.hpp"
# include "RandomIterator.hpp"

# ifndef __APPLE__
#  define __APPLE__ 0
# endif

namespace ft
{

	template<bool Cond, class E = void>
	struct enable_if {};

	template<class E> 
	struct enable_if<true, E>
	{
		typedef E type;
	};

	template <class I> struct is_integral { static const bool value = false;};
	template <> struct is_integral<bool> { static const bool value = true; };
	template <> struct is_integral<char> { static const bool value = true; };
	template <> struct is_integral<short int> { static const bool value = true; };
	template <> struct is_integral<int> { static const bool value = true; };
	template <> struct is_integral<long int> { static const bool value = true; };
	template <> struct is_integral<long long int> { static const bool value = true; };
	template <> struct is_integral<unsigned char> { static const bool value = true; };
	template <> struct is_integral<unsigned short int> { static const bool value = true; };
	template <> struct is_integral<unsigned int> { static const bool value = true; };
	template <> struct is_integral<unsigned long int> { static const bool value = true; };
	template <> struct is_integral<unsigned long long int> { static const bool value = true; };
	
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
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
	template<class T>
	struct node
	{
		private:
			bool _unused;
			#if __APPLE__ == 0
				int _unused_linux;
			#endif
		public:
			T		tab;
			node	*right;
			node	*left;
			node	*parent;
	};

	template<typename T>
	node<T>	*minValueNode(node<T>	*node)
	{
		while (node && node->left != NULL)
			node = node->left;
		return node;
	}

	template<typename T>
	node<T>	*maxValueNode(node<T>	*node)
	{
		while (node && node->right != NULL)// && node->right != node->ghost)
			node = node->right;
		return node;
	}

	template <class T1, class T2> struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair(void) : first(), second() { return ;};
		template<class U, class V>
		pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) { return ; };
		pair(const first_type& a, const second_type& b) : first(a), second(b) { return ; };
		pair& operator=(const pair& pr) { first = pr.first; second = pr.second; return *this; };
	};

template <class T1, class T2>
bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); };

template <class T1, class T2>
bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); };

template <class T1, class T2>
bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first < rhs.first && lhs.second < rhs.second); };

template <class T1, class T2>
bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first <= rhs.first && lhs.second <= rhs.second); };

template <class T1, class T2>
bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first > rhs.first && lhs.second > rhs.second); };

template <class T1, class T2>
bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first >= rhs.first && lhs.second >= rhs.second); };

template <class T1,class T2>
pair<T1,T2> make_pair (T1 x, T2 y) { return ( pair<T1,T2>(x,y) ); };

}

#endif