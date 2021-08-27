#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

// # include "../Utils/Utils.hpp"

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

    template<typename T, typename node>
    class map_iterator
    {
        public:
			typedef	T					value_type;
			typedef	value_type&			reference;
			typedef	value_type const&	const_reference;
			typedef	value_type*			pointer;
			typedef ptrdiff_t			difference_type;

			map_iterator(void) : _node(NULL) { return ; };
			map_iterator(map_iterator const &src)
			{
				if (*this == &src)
					return *this;
				*this->_node = src._node;
				return *this;
			};
			~map_iterator(void) { return ; };
			map_iterator&	operator=(map_iterator const &rhs) { _node = rhs._node; return ;};

			bool			operator==(const map_iterator &x) const { return this->_node == x._node;};
			bool			operator!=(const map_iterator &x) const { return this->_node != x._node;};

			map_iterator<value_type, node>	&operator++(void);
			map_iterator<value_type, node>	operator++(int);
			map_iterator<value_type, node>	&operator--(void);
			map_iterator<value_type, node>	operator--(int);
			reference						operator*(void);
			pointer							operator->(void);

			private:
				node	*_node;
    };
    
	template<typename T, typename node>
	map_iterator<T, node>	&map_iterator<T, node>::operator++(void)
	{
		if (_node->right)
			_node = _node->right;
		else if (_node->parent)
			_node = _node->parent;

		return *this;
	}
	
	template<typename T, typename node>
	map_iterator<T, node>	map_iterator<T, node>::operator++(int)
	{
		map_iterator tmp(*this); this->operator++(); return tmp;
	}
	
	template<typename T, typename node>
	map_iterator<T, node>	&map_iterator<T, node>::operator--(void)
	{
		if (_node->left)
			_node = _node->left;

		return *this;
	}
	
	template<typename T, typename node>
	map_iterator<T, node>	map_iterator<T, node>::operator--(int) 
	{
		map_iterator tmp(*this); this->operator--(); return tmp;
	}
	
	template<typename T, typename node>
	typename map_iterator<T, node>::reference	map_iterator<T, node>::operator*(void) { return this->_node->key; }
	
	template<typename T, typename node>
	typename map_iterator<T, node>::pointer		map_iterator<T, node>::operator->(void) { return &this->_node->key; }
}

#endif