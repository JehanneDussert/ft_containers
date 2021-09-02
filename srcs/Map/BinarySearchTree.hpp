#ifndef BINARYSEARCHTREE_HPP
# define BINARYSEARCHTREE_HPP

# include "Map.hpp"

namespace ft
{
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr	map<Key, T, Compare, Alloc>::newNode(node_ptr val)
	{
		node_ptr tmp = val;
		
		// tmp->left = NULL; tmp->right = NULL;
		return tmp;
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr    map<Key, T, Compare, Alloc>::insert(node_ptr node, value_type val)
	{
		if (node == NULL)
		{
			if (_tab == NULL)
				_root = newNode(new node_type(val));
			// parent
			node = newNode(new node_type(val));
			_size++;
		}
		else if (_comp(val.first, node->tab.first))
			node->left = insert(node->left, val);
		else
			node->right = insert(node->right, val);

		std::cout << "Size: " << _size << std::endl;
		std::cout << "Node content: " << node->tab.first << ' ' << node->tab.second << '\n';
		if (node->parent)
			std::cout << "Parent content: " << node->parent->tab.first << ' ' << node->parent->tab.second << std::endl;
		return node;
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr map<Key, T, Compare, Alloc>::minValueNode(node_ptr node) const
	{
		while (node && node->left != NULL)
			node = node->left;

		return node;
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr map<Key, T, Compare, Alloc>::maxValueNode(node_ptr node) const
	{
		while (node && node->right != NULL)
			node = node->right;

		return node;
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr	map<Key, T, Compare, Alloc>::deleteNode(node_ptr root, value_type val)
	{
		if (root == NULL)
			return root;
		else if (_comp(val.first, root->tab.first))
			root->left = deleteNode(root->left, val);
		else if (!_comp(val.first, root->tab.first)) // if (val.first > root->tab.first) mais prbl car !_comp si val == root...
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
			root->tab = tmp->tab;
			root->right = deleteNode(root->right, tmp->tab);
		}
		return root;
	}

	template<class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::showMeTheTruth()
	{
		inorder(_tab);
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