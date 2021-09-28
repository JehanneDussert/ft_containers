#ifndef MAP_FUNCTIONS_HPP
# define MAP_FUNCTIONS_HPP

#include <functional>
#include <cmath>
# include "Map.hpp"

namespace ft
{

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::node_ptr	map<Key, T, Compare, Alloc>::_newNode(value_type& val)
{
	node_ptr tmp = _nodeAlloc.allocate(1);
	_pairAlloc.construct(&tmp->tab, val);

	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;

	return tmp;
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::node_ptr	map<Key, T, Compare, Alloc>::_deleteNode(node_ptr node, value_type val)
{
	if (!_size)
		_lastElem = _ghost;
	if (!node || node == _ghost)
		return node;
	else if (key_comp()(val.first, node->tab.first))
		node->left = _deleteNode(node->left, val);
	else if ((key_comp()(node->tab.first, val.first)))
		node->right = _deleteNode(node->right, val);
	else
	{
		if (!node->left && !node->right)
		{
			_pairAlloc.destroy(&node->tab);
			return NULL;
		}
		else if (!node->left)
		{
			node_ptr tmp = node->right;
			tmp->parent = node->parent;
			_pairAlloc.destroy(&node->tab);
			return tmp;
		}
		else if (!node->right)
		{
			node_ptr tmp = node->left;
			tmp->parent = node->parent;
			_pairAlloc.destroy(&node->tab);
			return tmp;
		}
		node_ptr tmp = minValueNode(node->right);
		_pairAlloc.destroy(&node->tab);
		_pairAlloc.construct(&node->tab, tmp->tab);
		node->right = _deleteNode(node->right, tmp->tab);
	}
	return node;
}

/**********************/
/**	MEMBER FUNCTIONS **/
/**********************/

/*
** Empty constructor
*/

template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) :
_pairAlloc(alloc), _comp(comp), _size(0), _root(NULL), _ghost(NULL), _lastElem(NULL)
{
	return ;
};

/*
** Range constructor
*/

template < class Key, class T, class Compare, class Alloc >
template <class InputIterator>
map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last, const key_compare& comp,
const allocator_type& alloc) : _pairAlloc(alloc), _comp(comp), _size(0), _root(NULL), _ghost(NULL), _lastElem(NULL)
{
	insert(first, last);

	return ;
};

/*
** Copy constructor
*/

template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>::map(const map& x) : _size(0), _root(NULL), _ghost(NULL), _lastElem(NULL)
{
	*this = x;
	return;
};

template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>	&map<Key, T, Compare, Alloc>::operator=(const map& x)
{
	clear();
	this->_comp = x._comp;
	this->_nodeAlloc = x._nodeAlloc;
	this->_pairAlloc = x._pairAlloc;
	insert(x.begin(), x.end());
	
	return *this;
};

/*
**	Destructor
*/

template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>::~map(void)
{
	clear();
	_nodeAlloc.deallocate(_root, _size);

	return ;
};

/*
**	Iterators
*/	

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::begin()
{
	// std::cout << "min is " << minValueNode(_root)->tab.first << std::endl;
	return iterator(minValueNode(_root));
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::begin() const
{
	return const_iterator(minValueNode(_root));
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::end()
{
	if (!_root || !size())
		return iterator(_lastElem);
	return iterator(_lastElem->right);
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::end() const
{
	if (!_root || !size())
		return const_iterator(_lastElem);
	return const_iterator(_lastElem->right);
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rbegin()
{ return reverse_iterator(_ghost); }

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rbegin() const
{ return const_reverse_iterator(_ghost); }

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rend()
{ return reverse_iterator(begin()); };

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rend() const 
{ return const_reverse_iterator(begin()); }

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
	return _nodeAlloc.max_size();
}

template <class Key, class T, class Compare, class Alloc >
bool	map<Key, T, Compare, Alloc>::empty() const
{
	return (!(_size) ? true : false);
}

/*
**	Element access
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::mapped_type&	map<Key, T, Compare, Alloc>::operator[](const key_type& k)
{
	return (*((this->insert(value_type(k, mapped_type()))).first)).second;
}

/*
**	Modifiers
*/

template<class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>	map<Key, T, Compare, Alloc>::insert(const value_type& val)
{
	ft::pair<iterator, bool>	ret;

	if (count(val.first))
		ret.second = false;
	else
	{
		_root = _insert(_root, val);
		ret.second = true;
	}
	ret.first = find(val.first);

	return ret;
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
	(void)position;
	return insert(val).first;
}

template<class Key, class T, class Compare, class Alloc>
template <class InputIterator>
void map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
	while (first != last)
		insert(*first++);
}

template<class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::erase(iterator position)
{
	if (!_root)
		return ;
	--_size;
	_root = _deleteNode(_root, value_type(position->first, position->second));
	return ;
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::erase(const key_type& k)
{
	iterator pos = find(k);
	if (!count(k) || !_root)
		return 0;
	--_size;
	_root = _deleteNode(_root, value_type(k, find(k)->second));
	return 1;
}

template<class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
{
	while (first != last)
	{
		--_size;
		_root = _deleteNode(_root, value_type(first->first, first->second));
		++first;
	}
}

template<class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::swap(map& x)
{
	map<Key, T, Compare, Alloc>	tmp;

	tmp._comp = this->_comp;
	tmp._nodeAlloc = this->_nodeAlloc;
	tmp._pairAlloc = this->_pairAlloc;
	tmp._root = this->_root;
	tmp._ghost = this->_ghost;
	tmp._lastElem = this->_lastElem;
	tmp._size = this->_size;

	this->_comp = x._comp;
	this->_nodeAlloc = x._nodeAlloc;
	this->_pairAlloc = x._pairAlloc;
	this->_root = x._root;
	this->_ghost = x._ghost;
	this->_lastElem = x._lastElem;
	this->_size = x._size;

	x._comp = tmp._comp;
	x._nodeAlloc = tmp._nodeAlloc;
	x._pairAlloc = tmp._pairAlloc;
	x._root = tmp._root;
	x._ghost = tmp._ghost;
	x._lastElem = tmp._lastElem;
	x._size = tmp._size;
}

template <class Key, class T, class Compare, class Alloc >
void map<Key, T, Compare, Alloc>::clear()
{
	// if (_ghost)
	// 	_nodeAlloc.deallocate(_ghost, 1);
	if (_root)
		_pairAlloc.destroy(&_root->tab);
	_size = 0;
	_root = NULL;
	_ghost = NULL;
	_lastElem = NULL;

	return ;
}

/*
**	Observers
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::key_compare map<Key, T, Compare, Alloc>::key_comp() const { return key_compare(); };

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::value_compare	map<Key, T, Compare, Alloc>::value_comp() const { return value_compare(key_compare()); }

/*
**	Operations
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::find(const key_type& k)
{
	iterator	it = begin(); iterator	ite = end();

	while (it != ite)
	{
		if (!key_comp()(k, it->first) && !key_comp()(it->first, k))
			break ;
		if (it._node == _lastElem)
			return ++ite;
		++it;
	}
	return it;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::find(const key_type& k) const
{
	const_iterator	it = begin(); const_iterator	ite = end();

	while (it != ite)
	{
		if (!key_comp()(k, it->first) && !key_comp()(it->first, k))
			break ;
		if (it._node == _lastElem)
			return ++ite;
		++it;
	}
	return it;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::count(const key_type& k) const
{
	if (!_root)
		return 0;
	const_iterator	it = begin(); const_iterator	ite = end();
	if (!key_comp()(k, it->first) && !key_comp()(it->first, k))
		return 1;
	while (it != ite)
	{
		if (!key_comp()(k, it->first) && !key_comp()(it->first, k))
			return 1;
		++it;
	}
	return 0;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::lower_bound(const key_type& k)
{
	iterator it = begin(), ite = end();
	while (it != ite)
	{
		if (!_comp(it->first, k))
			break;
		++it;
	}
	return it;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const
{
	const_iterator it = begin(), ite = end();
	while (it != ite)
	{
		if (!_comp(it->first, k))
			break;
		++it;
	}
	return it;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{
	iterator it = begin(), ite = end();
	while (it != ite)
	{
		if (_comp(k, it->first))
			break;
		++it;
	}
	return it;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{
	const_iterator it = begin(), ite = end();
	while (it != ite)
	{
		if (_comp(k, it->first))
			break;
		++it;
	}
	return it;
}

template <class Key, class T, class Compare, class Alloc >
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, typename ft::map<Key, T, Compare, Alloc>::iterator>
map<Key, T, Compare, Alloc>::equal_range(const key_type& k)
{
	ft::pair<iterator, iterator>	ret; 
	ret.first = lower_bound(k), ret.second = upper_bound(k);
	
	return ret;
}

template <class Key, class T, class Compare, class Alloc >
ft::pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator, typename ft::map<Key, T, Compare, Alloc>::const_iterator> 
map<Key, T, Compare, Alloc>::equal_range(const key_type& k) const
{
	ft::pair<const_iterator, const_iterator>	ret;
	ret.first = lower_bound(k), ret.second = upper_bound(k);

	return ret;
}

/*
**	Allocator
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::allocator_type	map<Key, T, Compare, Alloc>::get_allocator() const
{
	return this->_pairAlloc;
}

template<class Key, class T, class Compare, class Alloc>
void    map<Key, T, Compare, Alloc>::_setGhost(bool add)
{
	if (!_ghost)
		_ghost = _nodeAlloc.allocate(1);
	if (add)
	{
		_lastElem = maxValueNode(_root);
		_lastElem->right = _ghost;
	}
	if (size() == 0)
		_lastElem = NULL;
	_ghost->right = NULL;
	_ghost->left = NULL;
	_ghost->parent = _lastElem;
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::node_ptr    map<Key, T, Compare, Alloc>::_insert(node_ptr node, value_type val)
{
	// std::cout << "value to insert " << val.first << std::endl;
	if (!_root || !node || node == _ghost)
	{
		node = _newNode(val);
		if (!_root)
			_root = node;
		else if (node == _ghost)
			_lastElem = node;
		_size++;
	}
	else if (key_comp()(val.first, node->tab.first))
	{
		node->left = _insert(node->left, val);
		node->left->parent = node;
	}
	else
	{
		node->right = _insert(node->right, val);
		node->right->parent = node;
	}
	if (!_ghost || !key_comp()(val.first, _lastElem->tab.first))
	{	
		if (_ghost)
			!key_comp()(node->tab.first, _lastElem->tab.first) ? _setGhost(true) : _setGhost(false);
		else
			_setGhost(true);
	}
	return node;
}

template<class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::inorder(node_ptr root)
{
	if (root != NULL)
	{
		inorder(root->left);
		std::cout << root->tab.first << ' ';
		std::cout << root->tab.second << ' ';
		inorder(root->right);
	}
}

/**************************************/
/*** NON MEMBER FUNCTIONS OVERLOADS ***/
/**************************************/

/*
** RELATIONAL OPERATORS
*/

template<class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
    return (lhs == rhs ? false : true);
}

template<class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	return ft::lexicographical_compare(lhs.begin(), --lhs.end(), rhs.begin(), --rhs.end());
}

template<class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (rhs < lhs ? false : true);
}

template<class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (rhs < lhs ? true : false);
}

template<class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (lhs < rhs ? false : true);
}

template<class Key, class T, class Compare, class Alloc>
void	swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs)
{
	lhs.swap(rhs);
}

};

#endif