#ifndef VECTOR_FUNCTIONS_HPP
# define VECTOR_FUNCTIONS_HPP

# include "Vector.hpp"

namespace ft {

/***************************/
/**	ADDITIONNAL FUNCTIONS **/
/**************************/

template <typename T, typename Alloc>
void	vector<T, Alloc>::_clear_tab(void)
{
	clear();
	_alloc.deallocate(_tab, _capacity);
}

/**********************/
/**	MEMBER FUNCTIONS **/
/**********************/

/*
** Default constructor
*/

template <typename T, typename Alloc>
vector<T, Alloc>::vector(const allocator_type& alloc) : _tab(NULL), _size(0),
_max_size(alloc.max_size()), _alloc(alloc), _capacity(0) { return ; };

/*
** Fill constructor
*/

template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, const value_type& val,
const allocator_type& alloc) : _size(n), _max_size(alloc.max_size()), 
_alloc(alloc), _capacity(n)
{
	_tab = _alloc.allocate(n);
	for (size_type i = 0; i < n; i++)
		_alloc.construct(&_tab[i], val);
	return ;
}

/*
** Range constructor
*/

template <typename T, typename Alloc>
template <class InputIterator>
vector<T, Alloc>::vector(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first,
InputIterator last, const allocator_type& alloc) : _size(0), _max_size(alloc.max_size()), _alloc(alloc), _capacity(0)
{
	_capacity += iterator_len(first, last);
	_tab = _alloc.allocate(_capacity);
	for (; first != last; ++first)
		_alloc.construct(&_tab[_size++], *first);
}

/*
** Copy constructor
*/


// prbl here

template <typename T, typename Alloc>
vector<T, Alloc>::vector(const vector& x)
{
	_size = x.size();
	_capacity = x.capacity();
	_max_size = x.max_size();
	_tab = _alloc.allocate(_capacity);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&_tab[i], x[i]);
};

template <typename T, typename Alloc>
vector<T, Alloc>::~vector(void)
{
	clear();

	return ;
};

template <class T, class Alloc>
vector<T, Alloc>	&vector<T, Alloc>::operator=(const vector &x)
{
	vector<T, Alloc>	tmp;

	if (this == &x)
		return *this;
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(&_tab[i]);
	if (x.size() > tmp._capacity)
		tmp._capacity = x.size();
	if (x.capacity() < _capacity)
		tmp._capacity = _capacity;
	tmp._tab = _alloc.allocate(tmp._capacity);
	const_iterator first = x.begin(); const_iterator last = x.end();
	for (size_type i = 0; first != last; ++first)
		tmp._alloc.construct(&tmp._tab[i++], *first);
	_tab = tmp._tab; _size = x.size(); _capacity = tmp._capacity;

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
	return (this->_value != x._value ? true : false);
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
	ft::vector<T, Alloc>::iterator	tmp(*this);

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
	ft::vector<T, Alloc>::iterator	tmp(*this);

	this->operator--();
	return tmp;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator			vector<T, Alloc>::iterator::operator+(difference_type n)
{
	return iterator(this->_value + n);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator			vector<T, Alloc>::iterator::operator-(difference_type n)
{
	return iterator(this->_value - n);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::difference_type	vector<T, Alloc>::iterator::operator-(const iterator& x) const
{
	return (this->_value - x.getValue());
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::iterator::operator<(const iterator& x) const
{
	return (this->_value < x._value ? true : false);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::iterator::operator>(const iterator& x) const
{
	return (this->_value < x._value ? false : true);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::iterator::operator<=(const iterator& x) const
{
	return (this->_value <= x._value ? true : false);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::iterator::operator>=(const iterator& x) const
{
	return (this->_value <= x._value ? false : true);
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

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator::const_reference			vector<T, Alloc>::iterator::operator[](size_type n) const
{
	return this->_value[n];
}

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
	return (this->_value == x._value ? false : true);
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
	ft::vector<T, Alloc>::const_iterator	tmp(*this);

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
	ft::vector<T, Alloc>::const_iterator	tmp(*this);

	this->operator--();
	return tmp;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::const_iterator::operator+(difference_type n)
{
	return const_iterator(this->_value + n);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::const_iterator::operator-(difference_type n)
{
	return const_iterator(this->_value - n);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::difference_type			vector<T, Alloc>::const_iterator::operator-(const const_iterator& x) const
{
	return (this->_value - x.getValue());
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::const_iterator::operator<(const const_iterator& x) const
{
	return (this->_value < x._value ? true : false);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::const_iterator::operator>(const const_iterator& x) const
{
	return (this->_value < x._value ? false : true);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::const_iterator::operator<=(const const_iterator& x) const
{
	return (this->_value <= x._value ? true : false);
}

template <typename T, typename Alloc>
bool	vector<T, Alloc>::const_iterator::operator>=(const const_iterator& x) const
{
	return (this->_value <= x._value ? false : true);
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

template<typename T, typename Alloc>
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
	vector<T, Alloc>	tmp;
	iterator first = begin(); iterator last = end();

	if (n > _capacity)
	{
		_size = 0 ;
		_capacity = n;
		tmp._tab = _alloc.allocate(n);
		for (; first != last; ++first)
			_alloc.construct(&tmp._tab[_size++], *first);
		_tab = tmp._tab;
	}
}

template <class T, class Alloc>
void vector<T, Alloc>::resize(size_type n, value_type val)
{
	if (n < _size)
		for (; n < _size; _size--)
			_alloc.destroy(&_tab[_size]);
	else
	{
		if (n <= _capacity)
			;
		else if (n <= _capacity * 2)
			reserve(_capacity * 2);
		else
			reserve(n);
		for (; _size < n; _size++)
			_alloc.construct(&_tab[_size], val);
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
	if (n < this->_size)
		return ((*this)[n]);
	std::ostringstream ostr;
	ostr << "Out of Range error: vector::_M_range_check";
	throw std::out_of_range(ostr.str());
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
{
	if (n < this->_size)
		return ((*this)[n]);
	std::ostringstream ostr;
	ostr << "Out of Range error: vector::_M_range_check";
	throw std::out_of_range(ostr.str());
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
template <class InputIterator>
void vector<T, Alloc>::assign(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
{
	size_type	n = iterator_len(first, last);
	if (n > _capacity)
	{
		_clear_tab();
		_tab = _alloc.allocate(n);
		_capacity = n;
	}
	else
		clear();
	_size = n;
	for (size_type i = 0; first != last; ++first)
		_alloc.construct(&_tab[i++], *first);
}

template <typename T, typename Alloc>
void  vector<T, Alloc>::assign(size_type n, const value_type& val)
{
	if (n > _capacity)
	{
		_clear_tab();
		_tab = _alloc.allocate(n);
		_capacity = n;
	}
	else
		clear();
	_size = n;
	for (size_type i = 0; i < n; i++)
		_alloc.construct(&_tab[i], val);
}	

template <typename T, typename Alloc>
void  vector<T, Alloc>::push_back(const value_type& val)
{
	if (_size + 1 > _capacity)
		resize(_size + 1, val);
	else
		_alloc.construct(&_tab[_size++], val);
}

template <typename T, typename Alloc>
void vector<T, Alloc>::pop_back()
{
	_alloc.destroy(&_tab[_size]);
	--_size;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator position, const value_type& val)
{
	size_type i = position - begin();
	insert(position, 1, val);

	return iterator(this->begin() + i);
}

template<typename T, typename Alloc>
void	vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
{
	vector<T, Alloc>	tmp;
	iterator first = begin(); iterator last = end();
	size_type	index = 0;

	if (!n)
		return ;
	tmp = *this;
	_size += n;
	if (_size > _capacity * 2)
		_capacity = _size;
	else if (_size > _capacity)
		_capacity = _capacity * 2; 
	tmp._tab = _alloc.allocate(_capacity);
	for (; first != position; ++first)
		_alloc.construct(&tmp._tab[index++], *first);
	for(size_type i = index + n; index < i; index++)
		_alloc.construct(&tmp._tab[index], val);
	for (; index < _size; ++first)
		_alloc.construct(&tmp._tab[index++], *first);
	_tab = _alloc.allocate(_capacity);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&_tab[i], tmp[i]);
	tmp._clear_tab();
}

template<typename T, typename Alloc>
template <class InputIterator>
void	vector<T, Alloc>::insert(iterator position, InputIterator first,
typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last)
{
	vector<T, Alloc>	tmp;
	iterator	first_it = begin(); iterator	last_it = end();
	size_type	index = 0;
	size_type	len = iterator_len(first, last);

	if (!len)
		return ;
	resize(_size + len);
	tmp._tab = _alloc.allocate(_capacity);
	for (; first_it != position; ++first_it)
		_alloc.construct(&tmp._tab[index++], *first_it);
	for (; first != last; ++first)
		_alloc.construct(&tmp._tab[index++], *first);
	for (; first_it != last_it; ++first_it)
		_alloc.construct(&tmp._tab[index++], *first_it);
	_tab = tmp._tab;
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase (iterator first, iterator last)
{
	iterator			it = begin(); iterator	it_tmp = first;
	size_type			len = iterator_len(first, last);
	
	while (last != end())
	{
		*first = *last;
		first++;
		last++;
	}
	while (len--)
		_alloc.destroy(&_tab[--_size]);

	return it_tmp;
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator position)
{
	return erase(position, position + 1);
}

template <typename T, typename Alloc>
void vector<T, Alloc>::clear()
{
	while (_size > 0)
		_alloc.destroy(&_tab[--_size]);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::allocator_type	vector<T, Alloc>::get_allocator() const
{
	return this->_alloc;
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::swap(vector &x)
{
	vector<T, Alloc>	tmp(*this);

	if (this == &x)
		return ;
	_clear_tab(); _tab = _alloc.allocate(x.capacity());
	_size = 0; _capacity = x.capacity();
	for (; _size < x.size(); _size++)
		_tab[_size] = x._tab[_size];
	x._clear_tab(); x._tab = _alloc.allocate(tmp.capacity());
	x._size = 0; x._capacity = tmp.capacity();
	for (; x._size < tmp.size(); x._size++)
		x._tab[x._size] = tmp._tab[x._size];
}

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
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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
	x.swap(y);

	return ;
}

/*********************************/
/*** TEMPLATE SPECIALIZATIONS ***/
/********************************/

}
#endif