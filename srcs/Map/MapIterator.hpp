#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include "../Utils/Utils.hpp"

namespace ft
{
    template<typename T, typename node>
    class map_iterator
    {
		protected:
			node	*_node;
			map_iterator(node *src) { _node = src; return ;};

        public:
			typedef	T					value_type;
			typedef	value_type&			reference;
			typedef	value_type const&	const_reference;
			typedef	value_type*			pointer;
			typedef ptrdiff_t			difference_type;
			typedef node*				node_ptr;

			map_iterator(void) : _node(NULL) { return ; };
			map_iterator(map_iterator const &src) { *this = src; return ; };
			virtual ~map_iterator(void) { return ; };
			map_iterator&	operator=(map_iterator const &rhs) { _node = rhs._node; return *this;};
			operator map_iterator<const T, node>(void) const { return map_iterator<const T, node>(this->_node); };

			template <class U> bool	operator==(const map_iterator<U, node> &x) const { return this->_node == x._node;};
			template <class U> bool	operator!=(const map_iterator<U, node> &x) const { return this->_node != x._node;};

			map_iterator	&operator++(void);
			map_iterator	operator++(int);
			map_iterator	&operator--(void);
			map_iterator	operator--(int);
			reference		operator*(void) const;
			pointer			operator->(void) const;

			template <class, class, class, class>
			friend class map;

			template <class, class>
			friend class map_iterator;
    };
    
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
	typename map_iterator<T, node>::reference	map_iterator<T, node>::operator*(void) const { return this->_node->tab; }
	
	template<typename T, typename node>
	typename map_iterator<T, node>::pointer		map_iterator<T, node>::operator->(void) const { return &this->_node->tab; }
}

#endif