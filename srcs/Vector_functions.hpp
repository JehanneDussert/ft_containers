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
InputIterator last, const allocator_type& alloc) : _max_size(alloc.max_size()), _alloc(alloc), _capacity(0)
{
	size_type	n = 0;
	while (first + n != last)
	{
		n++;
		_capacity++;
	}
	_tab = _alloc.allocate(_capacity);
	for (size_type i = 0; first != last; ++first)
		_alloc.construct(&_tab[i++], *first);
	_size = _capacity;
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
	tmp._capacity = x.capacity();
	tmp._tab = _alloc.allocate(tmp._capacity);
	const_iterator first = x.begin(); const_iterator last = x.end();
	for (size_type i = 0; first != last; ++first)
		tmp._alloc.construct(&tmp._tab[i++], *first);
	_tab = tmp._tab; _size = x.size(); _capacity = tmp.capacity();

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
	vector<T, Alloc>	tmp;
	iterator first = begin(); iterator last = end();

	_size = 0;
	std::cout << "Size is : " << _size << std::endl;
	std::cout << "[bef] n : " << n << "\tcapacity : " << _capacity << "\tsize : " << _size << std::endl;
	if (n > _size)
	{
		if (n > _capacity * 2)
			_capacity = n;
		else
		{
			_capacity *= 2;
			n = _capacity;
		}
	}
	// std::cout << "[af] n : " << n << "\tcapacity : " << _capacity << "\tsize : " << _size << "\n\n";
	tmp._tab = _alloc.allocate(n);
	for (; first != last; ++first)
		_alloc.construct(&tmp._tab[_size++], *first);
	// _clear_tab();
	_tab = _alloc.allocate(n);
	// _capacity = n;
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&_tab[i], tmp[i]);
	tmp._clear_tab();
	std::cout << "Size is : " << _size << std::endl;
}

template <class T, class Alloc>
void vector<T, Alloc>::resize(size_type n, value_type val)
{
	if (n < _size)
		for (size_type i = n; i < _size; i++)
			_alloc.destroy(&_tab[i]);
	else
	{
		if (n > _capacity)
			reserve(n);
		for (; _size < n; _size++)
		{
			std::cout << "index is : " << _size << "\t" << n << std::endl;
			_alloc.construct(&_tab[_size++], val);
			std::cout << "Size here is : " << _size << std::endl;
		}
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
	std::ostringstream ostr; ostr << "Vector.";

	if (n >= _size - 1)
		throw std::out_of_range(ostr.str());
	return (*this)[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
{
	std::ostringstream ostr; ostr << "Vector.";

	if (n >= _size - 1)
		throw std::out_of_range(ostr.str());
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
template <class InputIterator>
void vector<T, Alloc>::assign(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
{
	size_type	n = 0;
	while (first + n != last)
		n++;
	if (n > _capacity)
	{
		_clear_tab();
		_tab = _alloc.allocate(n);
	}
	else
		clear();
	_capacity = n; _size = n;
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
	}
	else
		clear();
	_capacity = n; _size = n;
	for (size_type i = 0; i < n; i++)
		_alloc.construct(&_tab[i], val);
}	

template <typename T, typename Alloc>
void  vector<T, Alloc>::push_back(const value_type& val)
{
	if (_size + 1 > _capacity)
		resize(_size + 1, val);
	else
		_alloc.construct(&_tab[_size], val);
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
	vector<T, Alloc>	tmp;
	iterator first = begin(); iterator last = end();
	size_type	index = 0;

	_size++;
	tmp = *this;
	if (_size > _capacity)
		_capacity++;
	tmp._tab = _alloc.allocate(_capacity);
	for (; first != position; ++first)
		_alloc.construct(&tmp._tab[index++], *first);
	tmp._tab[index] = val;
	for (; first != last; ++first)
		_alloc.construct(&tmp._tab[++index], *first);
	*this = tmp;

	return iterator(this->begin() + (_size));
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
	if (_size > _capacity)
		_capacity = _size;
	tmp._tab = _alloc.allocate(_capacity);
	for (; first != position; ++first)
		_alloc.construct(&tmp._tab[index++], *first);
	for (size_type i = index + n; index < i; ++first)
		_alloc.construct(&tmp._tab[index++], val);
	for (; first != last; ++first)
		_alloc.construct(&tmp._tab[index++], *first);
	*this = tmp;
}

template<typename T, typename Alloc>
template <class InputIterator>
void	vector<T, Alloc>::insert(iterator position, InputIterator first,
typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last)
{
	vector<T, Alloc>	tmp;
	iterator	first_it = begin(); iterator	last_it = end();
	size_type	index = 0;
	size_type	len = 0;

	while (first + len != last)
		len++;
	if (!len)
		return ;
	tmp = *this;
	_size += len;
	if (_size > _capacity)
		_capacity = _size;
	tmp._tab = _alloc.allocate(_capacity);
	for (; first_it != position; ++first_it)
		_alloc.construct(&tmp._tab[index++], *first_it);
	for (; first != last; ++first)
		_alloc.construct(&tmp._tab[index++], *first);
	for (; first_it != last_it; ++first_it)
		_alloc.construct(&tmp._tab[index++], *first_it);
	*this = tmp;
}

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase (iterator first, iterator last)
{
	vector<T, Alloc>	tmp;
	iterator	first_it = begin(); iterator	last_it = end(); iterator	tmp_it = first;
	size_type	index = 0;

	tmp = *this;
	tmp._tab = _alloc.allocate(_capacity);
	for (; first_it != first; ++first_it)
		_alloc.construct(&tmp._tab[index++], *first_it);
	while (first_it != last)
	{
		first_it++;
		tmp._size--;
	}
	for (; first_it != last_it; ++first_it)
		_alloc.construct(&tmp._tab[index++], *first_it);
	*this = tmp;

	return tmp_it;
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

template <typename T, typename Alloc>
void	vector<T, Alloc>::swap(vector &x)
{
	vector<T, Alloc>	tmp(x);

	x = *this;
	*this = tmp;
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
	// to change
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