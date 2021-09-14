#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

namespace ft
{
	template<class T>
	struct node
	{
		T		tab;
		node	*right;
		node	*left;
		node	*parent;
		node	*_ghost;
		node(T const &src = T()) : tab(src), right(NULL), left(NULL), parent(NULL), _ghost(NULL) { return ; };
	};

    template<typename T, typename node>
    class map_iterator
    {
        public:
			typedef	T					value_type;
			typedef	value_type&			reference;
			typedef	value_type const&	const_reference;
			typedef	value_type*			pointer;
			typedef ptrdiff_t			difference_type;
			typedef node*				node_ptr;

			map_iterator(void) : _node(NULL) { return ; };
			map_iterator(map_iterator const &src) { *this = src; return ; };
			map_iterator(node *src) { _node = src; return ;};
			~map_iterator(void) { return ; };
			map_iterator&	operator=(map_iterator const &rhs) { _node = rhs._node; return *this;};
			operator map_iterator<const T, node>(void) const { return map_iterator<const T, node>(this->_node); };

			bool			operator==(const map_iterator &x) const { return this->_node == x._node;};
			bool			operator!=(const map_iterator &x) const { return this->_node != x._node;};

			map_iterator<value_type, node>	&operator++(void);
			map_iterator<value_type, node>	operator++(int);
			map_iterator<value_type, node>	&operator--(void);
			map_iterator<value_type, node>	operator--(int);
			reference						operator*(void);
			pointer							operator->(void) const;
			node *minValueNode(node_ptr new_node) const;
			node *maxValueNode(node_ptr new_node) const;


			private:
				node	*_node;
    };

	template<typename T, typename node>
	typename map_iterator<T, node>::node_ptr	map_iterator<T, node>::minValueNode(node_ptr new_node) const
	{
		while (new_node && new_node->left != NULL)
			new_node = new_node->left;
		return new_node;
	}

	template<typename T, typename node>
	typename map_iterator<T, node>::node_ptr	map_iterator<T, node>::maxValueNode(node_ptr new_node) const
	{
		while (new_node && new_node->right && new_node->right != new_node->_ghost)
			new_node = new_node->right;
		return new_node;
	}
    
	template<typename T, typename node>
	map_iterator<T, node>	&map_iterator<T, node>::operator++(void)
	{
		if (_node->right)
			_node = minValueNode(_node->right);
		else if (_node->parent)
		{
			node	*tmp = _node;
			_node = _node->parent;
			while (_node && tmp == _node->right)
			{
				tmp = _node;
				_node = _node->parent;
			}
		}
		return *this;
	}
	
	template<typename T, typename node>
	map_iterator<T, node>	map_iterator<T, node>::operator++(int)
	{
		map_iterator tmp(*this);
		this->operator++();
		
		return tmp;
	}
	
	template<typename T, typename node>
	map_iterator<T, node>	&map_iterator<T, node>::operator--(void)
	{
		if (_node->left)
			_node = maxValueNode(_node->left);
		else if (_node->parent)
		{
			node	*tmp = _node;
			_node = _node->parent;
			while (_node && tmp == _node->left)
			{
				tmp = _node;
				_node = _node->parent;
			}
		}
		return *this;
	}
	
	template<typename T, typename node>
	map_iterator<T, node>	map_iterator<T, node>::operator--(int) 
	{
		map_iterator tmp(*this);
		this->operator--();
		
		return tmp;
	}
	
	template<typename T, typename node>
	typename map_iterator<T, node>::reference	map_iterator<T, node>::operator*(void) { return this->_node->tab; }
	
	template<typename T, typename node>
	typename map_iterator<T, node>::pointer		map_iterator<T, node>::operator->(void) const { return &this->_node->tab; }
}

#endif