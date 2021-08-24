#ifndef MAP_FUNCTIONS_HPP
# define MAP_FUNCTIONS_HPP

# include "Map.hpp"

namespace ft
{

/**********************/
/**	MEMBER FUNCTIONS **/
/**********************/

/*
** Empty constructor
*/

template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) :
_alloc(alloc), _comp(comp), _size(0), _max_size(alloc.max_size()), _capacity(0) { return ; };

/*
** Range constructor
*/

template < class Key, class T, class Compare, class Alloc >
template <class InputIterator>
map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last, const key_compare& comp,
const allocator_type& alloc) : _alloc(alloc), _comp(comp) { (void)first; (void)last; return ; };

/*
** Copy constructor
*/

template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>::map(const map& x) { *this = x; return *this; };

template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>	&map<Key, T, Compare, Alloc>::operator=(const map& x)
{
	this->_size = x.size(); this->_capacity = x.capacity();
	this->_comp = x._comp;
	// Need to copy content
	
	return ;
};

/*
**	Capacity
*/	

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::size() const
{
	return this->_size;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::max_size() const
{
	return this->_max_size;
}

// template <class Key, class T, class Compare, class Alloc >
// void	map<Key, T, Compare, Alloc>::resize(size_type n, value_type val)
// {
// 	;
// }

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::capacity() const
{
	return this->_capacity;
}

template <class Key, class T, class Compare, class Alloc >
bool	map<Key, T, Compare, Alloc>::empty() const
{
	return (!(_size) ? true : false);
}

// template <class Key, class T, class Compare, class Alloc >
// void	map<Key, T, Compare, Alloc>::reserve(size_type n)
// {
// 	;
// }

/*
**	Element access
*/

// template <class Key, class T, class Compare, class Alloc >
// mapped_type&	map<Key, T, Compare, Alloc>::operator[](const key_type& k)
// {
// 	;
// }

/*
**	Modifiers
*/

// pair<iterator,bool> insert(const value_type& val);
// iterator insert(iterator position, const value_type& val);
// template <class InputIterator>
// void insert(InputIterator first, InputIterator last);
// void erase(iterator position);
// size_type erase(const key_type& k);
// void erase(iterator first, iterator last);
// void swap(map& x);
// void clear();

/*
**	Observers
*/

// key_compare key_comp() const;
// value_compare value_comp() const;

/*
**	Operations
*/

// iterator find(const key_type& k);
// const_iterator find(const key_type& k) const;
// size_type count(const key_type& k) const;
// iterator lower_bound(const key_type& k);
// const_iterator lower_bound(const key_type& k) const;
// iterator upper_bound(const key_type& k);
// const_iterator upper_bound(const key_type& k) const;
// pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
// pair<iterator,iterator>             equal_range(const key_type& k);

/*
**	Allocator
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::allocator_type	map<Key, T, Compare, Alloc>::get_allocator() const
{
	return this->_alloc;
}

// template <class Key, class T, class Compare, class Alloc >
// void	map<Key, T, Compare, Alloc>::addNode(const value_type& pair)
// {
// 	;
// }

};

#endif