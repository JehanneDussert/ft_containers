#ifndef vector_FUNCTIONS_HPP
# define vector_FUNCTIONS_HPP

# include "Vector.hpp"

namespace ft {

/***************************/
/**	ADDITIONNAL FUNCTIONS **/
/**************************/

template <typename T, typename Alloc>
void	vector<T, Alloc>::_clear_tab(void)
{
		_alloc.destroy(this->_tab);
		_alloc.deallocate(this->_tab, this->_capacity);
}

/**********************/
/**	MEMBER FUNCTIONS **/
/**********************/

template <typename T, typename Alloc>
vector<T, Alloc>::vector (const allocator_type& alloc) : _tab(NULL), _size(0),
_max_size(alloc.max_size()), _alloc(alloc), _capacity(0) { return ; };

template <typename T, typename Alloc>
vector<T, Alloc>::vector (size_type n, const value_type& val,
const allocator_type& alloc) : _size(n), _max_size(alloc.max_size()), 
_alloc(alloc), _capacity(n)
{
	_tab = _alloc.allocate(n);
	for (size_type i = 0; i < n; i++)
		_alloc.construct(_tab[i], val);
	return ;
};

// capacity = espace alloué -> peut etre > a size (nb d'elemts) ex si on a pop un element, la size reduit mais capacity reste la meme
// allocate/desalloc -> change capacity ; construct etc -> change size

// template <class InputIterator>
//     vector (InputIterator first, InputIterator last, const allocator_type& alloc); //range constructor

template <typename T, typename Alloc>
vector<T, Alloc>::vector (const vector& x)
{
	_size = x.size();
	_capacity = x.capacity();
	for (size_type i = 0; i < _size; i++)
	{
		_alloc.allocate(_capacity);
		_alloc.construct(_tab[i], x[i]);
	}
}; 

template <typename T, typename Alloc>		
vector<T, Alloc>::~vector(void)
{
	_clear_tab();

	return ;
};

template <class T, class Alloc>
vector<T, Alloc>	&vector<T, Alloc>::operator=(const vector &x)
{
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_tab[i]);
	this->_size = x.size();
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_tab[i], x[i]);
	
	return *this;
}

/*
**	ITERATORS
*/

/* -- Operator overloads iterator -- */

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator::reference	vector<T, Alloc>::iterator::operator*(void) const
{
	return (*this->_value);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator::pointer	vector<T, Alloc>::iterator::operator->(void) const
{
	return (this->_value);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator&			vector<T, Alloc>::iterator::operator=(const iterator& x)
{
	if (this == &x)
		return *this;
	this->_value = x._value;
	return *this;
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::iterator::operator==(const iterator& x) const
{
	return (this->_value == x._value ? true : false);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::iterator::operator!=(const iterator& x) const
{
	return (this == x ? false : true);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator&			vector<T, Alloc>::iterator::operator++(void)
{
	this->_value++;

	return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator				vector<T, Alloc>::iterator::operator++(int)
{
	ft::vector<int>::iterator	tmp(*this);

	this->operator++();
	return tmp;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator&			vector<T, Alloc>::iterator::operator--(void)
{
	this->_value--;

	return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator				vector<T, Alloc>::iterator::operator--(int)
{
	ft::vector<int>::iterator	tmp(*this);

	this->operator--();
	return tmp;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator			vector<T, Alloc>::iterator::operator+(ptrdiff_t n)
{
	return iterator(this->_value + n);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator			vector<T, Alloc>::iterator::operator-(ptrdiff_t n)
{
	return iterator(this->_value - n);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator			vector<T, Alloc>::iterator::operator+(const iterator& x)
{
	return iterator(this->_value + x._value);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator			vector<T, Alloc>::iterator::operator-(const iterator& x)
{
	return iterator(this->_value - x._value);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::iterator::operator<(const iterator& x) const
{
	return (this->_value < x._value ? true : false);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::iterator::operator>(const iterator& x) const
{
	return (this < x ? false : true);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::iterator::operator<=(const iterator& x) const
{
	return (this->_value <= x._value ? true : false);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::iterator::operator>=(const iterator& x) const
{
	return (this <= x ? false : true);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator&			vector<T, Alloc>::iterator::operator+=(ptrdiff_t n)
{
	this->_value += n;

	return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator&			vector<T, Alloc>::iterator::operator-=(ptrdiff_t n)
{
	this->_value -= n;

	return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator::reference			vector<T, Alloc>::iterator::operator[](size_type n)
{
	return this->_value[n];
}

// template <typename T, typename Alloc>
// typename vector<T, Alloc>::iterator::const_reference			vector<T, Alloc>::iterator::operator[](size_type n) const
// {
// 	return this->_value[n];
// }

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator::difference_type			vector<T, Alloc>::iterator::operator[](const iterator& x) const
{
	return this->_value - x._value;
}

/* -- Operator overloads const_iterator -- */

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator::reference	vector<T, Alloc>::const_iterator::operator*(void) const
{
	return (*this->_value);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator::pointer	vector<T, Alloc>::const_iterator::operator->(void) const
{
	return (this->_value);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator&			vector<T, Alloc>::const_iterator::operator=(const const_iterator& x)
{
	if (this == &x)
		return *this;
	this->_value = x._value;
	return *this;
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::const_iterator::operator==(const const_iterator& x) const
{
	return (this->_value == x._value ? true : false);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::const_iterator::operator!=(const const_iterator& x) const
{
	return (this == x ? false : true);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator&			vector<T, Alloc>::const_iterator::operator++(void)
{
	this->_value++;

	return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator				vector<T, Alloc>::const_iterator::operator++(int)
{
	ft::vector<int>::const_iterator	tmp(*this);

	this->operator++();
	return tmp;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator&			vector<T, Alloc>::const_iterator::operator--(void)
{
	this->_value--;

	return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator				vector<T, Alloc>::const_iterator::operator--(int)
{
	ft::vector<int>::const_iterator	tmp(*this);

	this->operator--();
	return tmp;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::const_iterator::operator+(ptrdiff_t n)
{
	return const_iterator(this->_value + n);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::const_iterator::operator-(ptrdiff_t n)
{
	return const_iterator(this->_value - n);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::const_iterator::operator+(const const_iterator& x)
{
	return const_iterator(this->_value + x._value);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::const_iterator::operator-(const const_iterator& x)
{
	return const_iterator(this->_value - x._value);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::const_iterator::operator<(const const_iterator& x) const
{
	return (this->_value < x._value ? true : false);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::const_iterator::operator>(const const_iterator& x) const
{
	return (this < x ? false : true);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::const_iterator::operator<=(const const_iterator& x) const
{
	return (this->_value <= x._value ? true : false);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::const_iterator::operator>=(const const_iterator& x) const
{
	return (this <= x ? false : true);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator&			vector<T, Alloc>::const_iterator::operator+=(ptrdiff_t n)
{
	this->_value += n;

	return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator&			vector<T, Alloc>::const_iterator::operator-=(ptrdiff_t n)
{
	this->_value -= n;

	return *this;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator::reference			vector<T, Alloc>::const_iterator::operator[](size_type n)
{
	return this->_value[n];
}

// template <typename T, typename Alloc>
// typename vector<T, Alloc>::const_iterator::const_reference			vector<T, Alloc>::const_iterator::operator[](size_type n) const
// {
// 	return this->_value[n];
// }

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator::difference_type			vector<T, Alloc>::const_iterator::operator[](const const_iterator& x) const
{
	return this->_value - x._value;
}

/*
** Iterator functions
*/

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
{
	return iterator(_tab);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
{
	return const_iterator(_tab);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
{
	return iterator(&_tab[_size]);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
{
	return const_iterator(&_tab[_size]);
}

// template <typename T, typename Alloc>
// vector<T, Alloc>::reverse_iterator<T, Alloc>::rbegin()
// {
// 	return reverse_iterator(_tab);
// }

// template <typename T, typename Alloc>
// vector<T, Alloc>::rconst_reverse_iterator<T, Alloc>::rbegin() const;
// {
// 	return const_reverse_iterator(_tab);
// }

// template <typename T, typename Alloc>
// vector<T, Alloc>::reverse_iterator<T, Alloc>::rend()
// {
// 	return reverse_iterator(_tab[_size]);
// }

// template <typename T, typename Alloc>
// vector<T, Alloc>::rconst_reverse_iterator<T, Alloc>::rend() const;
// {
// 	return const_reverse_iterator(_tab[_size]);
// }

/*
** CAPACITY
*/

template <class T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
{
	return this->_size;
}

template <class T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
{
	return this->_max_size;
}

template <class T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
{
	return this->_capacity;
}

template <class T, class Alloc>
bool vector<T, Alloc>::empty() const
{
	return (!(_size) ? true : false);
}

template <class T, class Alloc>
void vector<T, Alloc>::reserve(size_type n)
{
	vector<T, Alloc>	tmp(this);

	_clear_tab();
	_alloc.allocate(n);
	_capacity = n;
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_tab[i], tmp[i]);
	//_clear_tab(tmp);
}

template <class T, class Alloc>
void vector<T, Alloc>::resize(size_type n, value_type val)
{
	//Notice that this function changes the actual content of the container by inserting or erasing elements from it.
	if (n < _size)
		for (size_type i = n; i < _size; i++)
			_alloc.destroy(_tab[i]);
	else
	{
		if (n > _capacity)
			reserve(n);
		for (size_type i = _size; i < n; i++)
			_alloc.construct(_tab[i], val);
	}
}

/*
** ELEMENT ACCESS
*/

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n)
{
	return _tab[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const
{
	return _tab[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n)
{
	if (n >= _size - 1)
		throw OutOfRangeException();
	return (*this)[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
{
	if (n >= _size - 1)
		throw OutOfRangeException();
	return (*this)[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::front()
{
	return (*this)[0];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
{
	return (*this)[0];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::back()
{
	return (*this)[_size - 1];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
{
	return (*this)[_size - 1];
}

/*
** MODIFIERS
*/

template <typename T, typename Alloc>
void vector<T, Alloc>::clear()
{
	for (; _size > 0; _size--)
		_alloc.destroy(_tab[_size]);
}

template <typename T, typename Alloc>
void  vector<T, Alloc>::push_back(const value_type& val)
{
	if (_size + 1 >= _capacity)
		reserve(_size + 1);
	++_size;
	_alloc.construct(_tab[_size], val);
}

template <typename T, typename Alloc>
void vector<T, Alloc>::pop_back()
{
	_alloc.destroy(_tab[_size]);
	--_size;
}

//Removes from the vector either a single element (position) or a range of elements ([first,last)).

// template <typename T, typename Alloc>
// iterator  vector<T, Alloc>::erase(iterator position)
// {
// 	;
// }

// template <typename T, typename Alloc>
// iterator  vector<T, Alloc>::erase(iterator first, iterator last)
// {
// 	;
// }

// template <typename T, typename Alloc>
// void	vector<T, Alloc>::swap(vector &x)
// {
// 	swap(this, x);
// }

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
	for (size_t i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return false;
	return true;
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return (lhs == rhs ? false : true);
}

template <class T, class Alloc>
bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	// to change
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (rhs < lhs ? false : true);
}

template <class T, class Alloc>
bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (rhs < lhs ? true : false);
}

template <class T, class Alloc>
bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (lhs < rhs ? false : true);
}

/*
** SWAP
*/

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
    vector<T, Alloc>    tmp(x);
    x = y;
    y = tmp;

	return ;
}

/*********************************/
/*** TEMPLATE SPECIALIZATIONS ***/
/********************************/

}
#endif