#ifndef BINARYSEARCHTREE_HPP
# define BINARYSEARCHTREE_HPP

# include "Map.hpp"

// need to include alloc

namespace ft
{
	template<class T>
	struct node
	{
		T		key;
		node	*right;
		node	*left;
		node	*parent;
		node(void) : key(NULL), right(NULL), left(NULL), parent(NULL){ return ; };
	};

	// template<class Key, class T, class Compare, class Alloc>
	// node<T>*	newNode(T value)
	// {
	// 	struct node<T>	*tmp = (struct node<T>*)malloc(sizeof(struct node<T>));
	// 	tmp->key = value;

	// 	// tmp.key = _alloc.allocate(1);
	// 	// tmp = _alloc.construct(tmp, value);
	// 	tmp->left = NULL; tmp->right = NULL;
	// 	return tmp;
	// }

	template<class Key, class T, class Compare, class Alloc>
	node<T>*    insert(node<T>* node, T key)
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
	node<T>*	minValueNode(node<T>* node)
	{
		ft::node<T>* tmp = node;
	
		while (tmp && tmp->left != NULL)
			tmp = tmp->left;
	
		return tmp;
	}

	template<class Key, class T, class Compare, class Alloc>
	node<T>*	deleteNode(node<T>* root, T key)
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
				node<T>* tmp = root->right; free(root);// _alloc.destroy(root); 
				return tmp;
			}
			else if (root->right == NULL)
			{
				node<T>* tmp = root->left; free(root); //_alloc.destroy(root);
				return tmp;
			}
			node<T>* tmp = minValueNode(root->right);
			root->key = tmp->key;
			root->right = deleteNode(root->right, tmp->key);
		}
		return root;
	}

	template<class Key, class T, class Compare, class Alloc>
	void inorder(node<T>* root)
	{
		if (root != NULL) {
			inorder(root->left);
			std::cout << root->key << ' ';
			inorder(root->right);
		}
	}	
}


#endif