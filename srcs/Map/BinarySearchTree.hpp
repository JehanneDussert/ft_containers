#ifndef BINARYSEARCHTREE_HPP
# define BINARYSEARCHTREE_HPP

# include "Map.hpp"

namespace ft
{
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr	map<Key, T, Compare, Alloc>::newNode(key_type value)
	{
		node_ptr tmp;
		
		tmp->key = value;
		tmp->left = NULL; tmp->right = NULL;
		return tmp;
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr    map<Key, T, Compare, Alloc>::insert(node_ptr node, key_type key)
	{
		if (node == NULL)
			return newNode(key);
		if (key < node->key)
			node->left = insert(node->left, key);
		else
			node->right = insert(node->right, key);

		return node;
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr	map<Key, T, Compare, Alloc>::minValueNode(node_ptr node)
	{
		node_ptr tmp = node;
	
		while (tmp && tmp->left != NULL)
			tmp = tmp->left;
	
		return tmp;
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::node_ptr	map<Key, T, Compare, Alloc>::deleteNode(node_ptr root, key_type key)
	{
		if (root == NULL)
			return root;
		else if (key < root->key)
			root->left = deleteNode(root->left, key);
		else if (key > root->key)
			root->right = deleteNode(root->right, key);
		else
		{
			if (!root->left && !root->right)
				return NULL;
			else if (!root->left)
			{
				node_ptr tmp = root->right; free(root);// _alloc.destroy(root); 
				return tmp;
			}
			else if (root->right == NULL)
			{
				node_ptr tmp = root->left; free(root); //_alloc.destroy(root);
				return tmp;
			}
			node_ptr tmp = minValueNode(root->right);
			root->key = tmp->key;
			root->right = deleteNode(root->right, tmp->key);
		}
		return root;
	}

	template<class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::inorder(node_ptr root)
	{
		if (root != NULL)
		{
			inorder(root->left);
			std::cout << root->key << ' ';
			inorder(root->right);
		}
	}
};

#endif