#ifndef VECTOR_FUNCTIONS_HPP
# define VECTOR_FUNCTIONS_HPP

# include "Vector.hpp"

/***************************/
/**	ADDITIONNAL FUNCTIONS **/
/**************************/

template <typename T, typename Alloc>
Vector<T, Alloc>::_clear_tab(Vector<T, Alloc> tab)
{
	for (size_t j = tab.capacity(); j > 0; j--)
	{
		for (; tab.size() > 0; tab.size()--)
			_alloc.destroy(tab[i]);
		_alloc.deallocate(tab[j]);
	}
}

/**********************/
/**	MEMBER FUNCTIONS **/
/**********************/

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector (const allocator_type& alloc = allocator_type()) : _tab(NULL), _size(0),
_max_size(alloc.max_size()), _alloc(alloc), _capacity(0) { return ; };

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector (size_type n, const value_type& val = value_type(),
const allocator_type& alloc = allocator_type()) : _size(n), _max_size(alloc.max_size()), 
_alloc(alloc), _capacity(n)
{
	_tab = _alloc.allocate(n);
	for (size_t i = 0; i < n; i++)
		_alloc.construct(_tab[i], val);
	return ;
};

// capacity = espace alloué -> peut etre > a size (nb d'elemts) ex si on a pop un element, la size reduit mais capacity reste la meme
// allocate/desalloc -> change capacity ; construct etc -> change size

// template <class InputIterator>
//     Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); //range constructor

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector (const vector& x)
{
	_size = x.size();
	_capacity = x.capacity();
	for (size_t i = 0; i < _size; i++)
	{
		_alloc.allocate(_capacity);
		_alloc.construct(_tab[i], x[i]);
	}
}; 

template <typename T, typename Alloc>		
Vector<T, Alloc>::~Vector(void)
{
	_clear_tab();

	return ;
};

template <class T, class Alloc>
Vector<T, Alloc>	&Vector::operator=(const vector& x);
{
	for (size_t i = 0; i < _size; i++)
		_alloc.destroy(_tab[i]);
	this->_size = x.size();
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_tab[i], x[i]);
	
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

template <class T, class Alloc>
void Vector<T, Alloc>::reserve(size_type n)
{
	Vector<T, Alloc>	tmp(this);

	_clear_tab(this);
	_alloc.allocate(n);
	_capacity = n;
	for (size_t i = 0; i < _size; i++)
		_alloc.construct(_tab[i], tmp[i]);
	_clear_tab(tmp);
}

template <class T, class Alloc>
void Vector<T, Alloc>::resize(size_type n, value_type val = value_type())
{
	//Notice that this function changes the actual content of the container by inserting or erasing elements from it.
	if (n < _size)
		for (size_t i = n; i < _size; i++)
			_alloc.destroy(_tab[i]);
	else
	{
		if (n > _capacity)
			reserve(n);
		for (size_t i = _size; i < n; i++)
			_alloc.construct(_tab[i], val);
	}
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
reference Vector<T, Alloc>::at(size_type n)
{
	if (_n >= _size - 1)
		throw OutOfRangeException();
	return (*this)[n];
}

template <typename T, typename Alloc>
const_reference Vector<T, Alloc>::at(size_type n) const
{
	if (_n >= _size - 1)
		throw OutOfRangeException();
	return (*this)[n];
}

template <typename T, typename Alloc>
reference Vector<T, Alloc>::front()
{
	return (*this)[0];
}

template <typename T, typename Alloc>
const_reference Vector<T, Alloc>::front() const
{
	return (*this)[0];
}

template <typename T, typename Alloc>
reference Vector<T, Alloc>::back()
{
	return (*this)[_size - 1];
}

template <typename T, typename Alloc>
const_reference Vector<T, Alloc>::back() const
{
	return (*this)[_size - 1];
}

/*
** MODIFIERS
*/

template <typename T, typename Alloc>
void Vector<T, Alloc>::clear()
{
	for (; _size > 0; _size--)
		_alloc.destroy(_tab[i]);
}

template <typename T, typename Alloc>
void  Vector<T, Alloc>::push_back(const value_type& val)
{
	if (_size + 1 >= _capacity)
		reserve(_size + 1);
	++_size;
	_alloc.construct(_tab[_size], val);
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::pop_back()
{
	_alloc.destroy(_tab[_size]);
	--_size;
}

//Removes from the vector either a single element (position) or a range of elements ([first,last)).

template <typename T, typename Alloc>
iterator  Vector<T, Alloc>::erase(iterator position)
{
	;
}

template <typename T, typename Alloc>
iterator  Vector<T, Alloc>::erase(iterator first, iterator last)
{
	;
}

template <typename T, typename Alloc>
void swap (vector& x)
{
	swap(this, x);
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
    Vector<T, Alloc>    tmp(x);
    x = y;
    y = tmp;

	return ;
}

/*********************************/
/*** TEMPLATE SPECIALIZATIONS ***/
/********************************/

#endif