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
_alloc(alloc), _comp(comp), _size(0), _max_size(alloc.max_size()), _capacity(0), _tab(NULL),
_root(NULL), _last(NULL) { return ; };

/*
** Range constructor
*/

template < class Key, class T, class Compare, class Alloc >
template <class InputIterator>
map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last, const key_compare& comp,
const allocator_type& alloc) : _alloc(alloc), _comp(comp), _max_size(alloc.max_size())
{ insert(first, last); return ; };

/*
** Copy constructor
*/

template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>::map(const map& x) { *this = x; return; };

template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>	&map<Key, T, Compare, Alloc>::operator=(const map& x)
{
	this->_size = x.size(); this->_capacity = x.capacity();
	this->_comp = x._comp; this->_root = x._root; this->_last = x._last;
	this->_tab = x._tab;
	
	return *this;
};

/*
**	Iterators
*/	

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::begin()
{ return iterator(minValueNode(_tab)); }

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::begin() const
{ return const_iterator(minValueNode(_tab)); }

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::end()
{ return iterator(maxValueNode(_tab)); }

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::end() const
{ return const_iterator(maxValueNode(_tab)); }

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rbegin()
{ return reverse_iterator(maxValueNode(_tab)); }

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rbegin() const
{ return const_reverse_iterator(maxValueNode(_tab)); }

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rend()
{ return reverse_iterator(minValueNode(_tab)); };

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rend() const 
{ return const_reverse_iterator(minValueNode(_tab)); }

/*
**	Capacity
*/	

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::size() const
{ return this->_size; }

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::max_size() const
{ return this->_max_size; }

// template <class Key, class T, class Compare, class Alloc >
// void	map<Key, T, Compare, Alloc>::resize(size_type n, value_type val)
// {
// 	;
// }

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::capacity() const
{ return this->_capacity; }

template <class Key, class T, class Compare, class Alloc >
bool	map<Key, T, Compare, Alloc>::empty() const
{ return (!(_size) ? true : false); }

// template <class Key, class T, class Compare, class Alloc >
// void	map<Key, T, Compare, Alloc>::reserve(size_type n)
// {
// 	;
// }

/*
**	Element access
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::mapped_type&	map<Key, T, Compare, Alloc>::operator[](const key_type& k)
{
	return (*((this->insert(value_type(k,mapped_type()))).first)).second;
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
		_tab = insert(_tab, val);
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

	// return iterator(position);
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
	if (!_tab)
		return ;
	_tab = deleteNode(_tab, value_type(position->first, position->second));
	--_size;
	return ;
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::erase(const key_type& k)
{
	if (!count(k) || !_tab)
		return 0;
	_tab = deleteNode(_tab, value_type(k, find(k)->second));
	--_size;
	return 1;
}

template<class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
{
	while (first != last)
	{
		deleteNode(*first++);
		--_size;
	}
}

template<class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::swap(map& x)
{
	map<Key, T, Compare, Alloc>	tmp;

	tmp._alloc = get_allocator(); tmp._comp = key_comp();
	tmp._size = size(); tmp._max_size = max_size();
	tmp._capacity = capacity(); tmp._tab = _tab; tmp._root = _root;

	_alloc = x.get_allocator(); _comp = x.key_comp();
	_size = x.size(); _max_size = x.max_size();
	_capacity = x.capacity(); _tab = x._tab; _root = x._root;

	x._alloc = tmp.get_allocator(); x._comp = tmp.key_comp();
	x._size = tmp.size(); x._max_size = tmp.max_size();
	x._capacity = tmp.capacity(); x._tab = tmp._tab; x._root = tmp._root;
}

template <class Key, class T, class Compare, class Alloc >
void map<Key, T, Compare, Alloc>::clear()
{
	return ;
}

/*
**	Observers
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::key_compare map<Key, T, Compare, Alloc>::key_comp() const { return _comp; };

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::value_compare	map<Key, T, Compare, Alloc>::value_comp() const { return value_compare(_comp); }

/*
**	Operations
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::find(const key_type& k)
{
	iterator	it = begin(); iterator	ite = end();

	if (!count(k))
		return ite;
	while (it != ite)
	{
		++it;
		if (it->first == k)
			break;
	}
	
	return it;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::find(const key_type& k) const
{
	const_iterator	it = begin(); const_iterator	ite = end();

	if (!count(k))
		return ite;
	while (it != ite)
	{
		++it;
		if (it->first == k)
			break;
	}
	return it;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::count(const key_type& k) const
{
	if (!_tab)
		return 0;
	const_iterator	it = begin(); const_iterator	ite = end();
	while (it != ite)
	{
		if (!_comp(k, it->first) && !_comp(it->first, k))
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
		++it;
		if (!_comp(it->first, k))
			break;
	}
	return it;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const
{
	const_iterator it = begin(), ite = end();
	while (it != ite)
	{
		++it;
		if (!_comp(it->first, k))
			break;
	}
	return it;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{
	iterator it = begin(), ite = end();
	while (it != ite)
	{
		++it;
		if (_comp(k, it->first))
			break;
	}
	return it;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{
	const_iterator it = begin(), ite = end();
	while (it != ite)
	{
		++it;
		if (_comp(k, it->first))
			break;
	}
	return it;
}

template <class Key, class T, class Compare, class Alloc >
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, typename ft::map<Key, T, Compare, Alloc>::iterator>
map<Key, T, Compare, Alloc>::equal_range(const key_type& k)
{
	ft::pair<iterator, iterator>	ret = value_type(lower_bound(k), lower_bound(k));
	
	return ret;
}

template <class Key, class T, class Compare, class Alloc >
ft::pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator, typename ft::map<Key, T, Compare, Alloc>::const_iterator> 
map<Key, T, Compare, Alloc>::equal_range(const key_type& k) const
{
	ft::pair<const_iterator, const_iterator>	ret = value_type(lower_bound(k), lower_bound(k));

	return ret;
}

/*
**	Allocator
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::allocator_type	map<Key, T, Compare, Alloc>::get_allocator() const
{ return this->_alloc; }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::node_ptr	map<Key, T, Compare, Alloc>::newNode(node_ptr val)
	{
		node_ptr tmp = val;
		
		tmp->left = NULL; tmp->right = NULL;
		return tmp;
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr    map<Key, T, Compare, Alloc>::insert(node_ptr node, value_type val)
	{
		if (node == NULL)
		{
			node = newNode(new node_type(val));
			_root = node;
			_size++;
			node->parent = NULL;
		}
		else if (_comp(val.first, node->tab.first))
		{
			if (!node->left)
			{
				node->left = newNode(new node_type(val));
				node->left->parent = node;
				_size++;
			}
			else
				insert(node->left, val);
		}
		else
		{
			if (!node->right)
			{
				node->right = newNode(new node_type(val));
				node->right->parent = node;
				_size++;
			}
			else
				insert(node->right, val);
		}

		return node;
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr map<Key, T, Compare, Alloc>::minValueNode(node_ptr node) const
	{
		while (node->left != NULL)
			node = node->left;

		return node;
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr map<Key, T, Compare, Alloc>::maxValueNode(node_ptr node) const
	{
		while (node->right != NULL)
			node = node->right;

		return node;
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr	map<Key, T, Compare, Alloc>::deleteNode(node_ptr root, value_type val)
	{
		if (root == NULL)
			return root;
		else if (_comp(val.first, root->tab.first) && !(!_comp(val.first, root->tab.first) && !_comp(root->tab.first, val.first)))
			root->left = deleteNode(root->left, val);
		else if (!_comp(val.first, root->tab.first)&& !(!_comp(val.first, root->tab.first) && !_comp(root->tab.first, val.first))) // if (val.first > root->tab.first) mais prbl car !_comp si val == root...
			root->right = deleteNode(root->right, val);
		else
		{
			if (!root->left && !root->right)
				return NULL;
			else if (!root->left)
			{
				node_ptr tmp = root->right; delete root;// _alloc.destroy(root); 
				return tmp;
			}
			else if (root->right == NULL)
			{
				node_ptr tmp = root->left; delete root; //_alloc.destroy(root);
				return tmp;
			}
			node_ptr tmp = minValueNode(root->right);
			root = tmp;
			root->right = deleteNode(root->right, tmp->tab);
		}
		return root;
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

};

#endif