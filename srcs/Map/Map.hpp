#ifndef MAP_HPP
# define MAP_HPP

# include "../Utils/Utils.hpp"
# include "MapIterator.hpp"

# include <iostream>
# include <map>
# include <iterator>
# include <iostream>
# include <algorithm>

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
class	map
{
	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef pair<const key_type, mapped_type>			value_type;
		typedef Compare										key_compare;
		typedef	Alloc										allocator_type;
		typedef	typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;
		typedef ft::node<value_type>						node_type;
		typedef node_type*									node_ptr;
	
		typedef ft::map_iterator<value_type, node_type >		iterator;
		typedef ft::map_iterator<const value_type, node_type >	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		class value_compare
		{
			friend class map;
			public:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			public:
				typedef bool	result_type;
				typedef			value_type first_argument_type;
				typedef			value_type second_argument_type;
				bool			operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); };
		};

		/**********************/
		/**	MEMBER FUNCTIONS **/
		/**********************/

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		map(const map& x);
		~map();
		map& operator=(const map& x);

		/*
		**	Iterators
		*/
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		/*
		**	Capacity
		*/		
		size_type size() const;
		size_type max_size() const;
		bool empty() const;

		/*
		**	Element access
		*/
		mapped_type& operator[](const key_type& k);

		/*
		**	Modifiers
		*/
		pair<iterator,bool> insert(const value_type& val);
		iterator insert(iterator position, const value_type& val);
		template <class InputIterator>
  		void insert(InputIterator first, InputIterator last);
		void erase(iterator position);
		size_type erase(const key_type& k);
		void erase(iterator first, iterator last);
		void swap(map& x);
		void clear();

		/*
		**	Observers
		*/
		key_compare		key_comp() const;
		value_compare	value_comp() const;

		/*
		**	Operations
		*/
		iterator		find(const key_type& k);
		const_iterator	find(const key_type& k) const;
		size_type		count(const key_type& k) const;
		iterator		lower_bound(const key_type& k);
		const_iterator	lower_bound(const key_type& k) const;
		iterator		upper_bound(const key_type& k);
		const_iterator	upper_bound(const key_type& k) const;
		pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
		pair<iterator,iterator>             equal_range(const key_type& k);

		/*
		**	Allocator
		*/
		allocator_type get_allocator() const;

	private:
		allocator_type							_pairAlloc;
		std::allocator<ft::node<value_type> >	_nodeAlloc;
		key_compare								_comp;
		size_type								_size;
		node_ptr								_root;
		node_ptr								_ghost;
		node_ptr								_lastElem;
		node_ptr								_insert(node_ptr node, value_type val);
		node_ptr								_newNode(value_type& val);
		node_ptr								_deleteNode(node_ptr root, value_type val);
		void									_setGhost(bool add);
};
}

#endif
