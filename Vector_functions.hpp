#ifndef VECTOR_FUNCTIONS_HPP
# define VECTOR_FUNCTIONS_HPP

# include "Vector.hpp"

/*
**	MEMBER FUNCTIONS
*/

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector (const allocator_type& alloc = allocator_type()) : _tab(NULL), _size(0), _alloc(alloc) { return ; };

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector (size_type n, const value_type& val = value_type(),
const allocator_type& alloc = allocator_type()) : _size(n), value_type(val),
allocator_type(allocator_type) { return ; };

// template <class InputIterator>
//     Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); //range constructor

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector (const vector& x)
{
    // copy constructor
    *this = x;
}; 

template <typename T, typename Alloc>		
Vector<T, Alloc>::~Vector(void) { return ; };

/*
** NON-MEMBER FUNCTION OVERLOADS
*/

template <typename T, typename Alloc>
reference Vector<T, Alloc>::operator[] (size_type n)
{
	return _tab[n];
}

template <typename T, typename Alloc>
const_reference Vector<T, Alloc>::operator[] (size_type n) const
{
	return _tab[n];
}

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    if (lhs.size() != rhs.size())
        return false;
	for (size_type i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return false;
	return true;
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    lhs == rhs ? return false : return true;
}

template <class T, class Alloc>
bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return std::lexicograpphical_comppare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	rhs < lhs ? return false : return true;
}

template <class T, class Alloc>
bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	rhs < lhs ? return true : return false;
}

template <class T, class Alloc>
bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	lhs < rhs ? return false : return true;
}

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
    vector<T, Alloc>    tmp = x;
    x = y;
    y = tmp;

	return ;
}

template <class T, class Alloc>
size_type size() const
{
	return this->_size;
}

#endif