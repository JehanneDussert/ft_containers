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
_alloc(alloc), _comp(comp), _size(0), _tab(NULL) { return ; };

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
map<Key, T, Compare, Alloc>	&map<Key, T, Compare, Alloc>::operator=(const map& x) { (void)x; return ; };

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::allocator_type	map<Key, T, Compare, Alloc>::get_allocator() const
{
	return this->_alloc;
}

};

#endif