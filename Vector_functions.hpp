#ifndef VECTOR_FUNCTIONS_HPP
# define VECTOR_FUNCTIONS_HPP

# include "Vector.hpp"

/**********************/
/**	MEMBER FUNCTIONS **/
/**********************/

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector (const allocator_type& alloc = allocator_type()) : _tab(NULL), _size(0), _max_size(0), _alloc(alloc), _capacity(0) { return ; };

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector (size_type n, const value_type& val = value_type(),
const allocator_type& alloc = allocator_type()) : _size(n), _alloc(alloc) { return ; };

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

template <class T, class Alloc>
Vector<T, Alloc>	&Vector::operator=(const vector& x);
{
	// TO COMPLETE
	// The container preserves its current allocator, which is used to allocate storage in case of reallocation.
	// Any elements held in the container before the call are either assigned to or destroyed.

	this->_size = x.size();
	for (size_type i = 0; i < _size; i++)
		this->_tab[i] = x[i];
	
	return *this;
}

/*
**	ITERATORS
*/

template <typename T, typename Alloc>
Vector<T, Alloc>::iterator<T, Alloc>::begin()
{
	return iterator(_tab);
}

template <typename T, typename Alloc>
Vector<T, Alloc>::const_iterator<T, Alloc>::begin() const
{
	return const_iterator(_tab);
}

template <typename T, typename Alloc>
Vector<T, Alloc>::iterator<T, Alloc>::end()
{
	return iterator(_tab[_size]);
}

template <typename T, typename Alloc>
Vector<T, Alloc>::const_iterator<T, Alloc>::end() const
{
	return const_iterator(_tab[_size]);
}

template <typename T, typename Alloc>
Vector<T, Alloc>::reverse_iterator<T, Alloc>::rbegin()
{
	return reverse_iterator(_tab);
}

template <typename T, typename Alloc>
Vector<T, Alloc>::rconst_reverse_iterator<T, Alloc>::rbegin() const;
{
	return const_reverse_iterator(_tab);
}

template <typename T, typename Alloc>
Vector<T, Alloc>::reverse_iterator<T, Alloc>::rend()
{
	return reverse_iterator(_tab[_size]);
}

template <typename T, typename Alloc>
Vector<T, Alloc>::rconst_reverse_iterator<T, Alloc>::rend() const;
{
	return const_reverse_iterator(_tab[_size]);
}

/*
** CAPACITY
*/

template <class T, class Alloc>
size_type Vector<T, Alloc>::size() const
{
	return this->_size;
}

template <class T, class Alloc>
size_type Vector<T, Alloc>::max_size() const
{
	return this->_max_size;
}

template <class T, class Alloc>
size_type Vector<T, Alloc>::capacity() const
{
	return this->_capacity;
}

template <class T, class Alloc>
bool Vector<T, Alloc>::empty() const
{
	!(_size) ? return true : return false;
}

/*
** ELEMENT ACCESS
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

template <typename T, typename Alloc>
reference Vector<T, Alloc>::at (size_type n)
{
	if (_n >= _size - 1)
		throw OutOfRangeException();
	return _tab[n];
}

template <typename T, typename Alloc>
const_reference Vector<T, Alloc>::at (size_type n) const
{

}

/*
** MODIFIERS
*/


/*
** ALLOCATOR
*/

/**************************************/
/*** NON MEMBER FUNCTIONS OVERLOADS ***/
/**************************************/

/*
** RELATIONAL OPERATORS
*/

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

/*
** SWAP
*/

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
    vector<T, Alloc>    tmp = x;
    x = y;
    y = tmp;

	return ;
}

/*********************************/
/*** TEMPLATE SPECIALIZATIONS ***/
/********************************/

#endif