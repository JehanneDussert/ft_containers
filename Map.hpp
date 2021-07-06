#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>

namespace ft
{
template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
           >
class	Map
{
	private:
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef pair<const key_type,mapped_type>	value_type;
		typedef Compare								key_compare;
		// typedef	Nested function class to compare elements	value_compare;
		typedef	Alloc	allocator_type;
		typedef	allocator_type::reference			reference;
		typedef allocator_type::const_reference		const_reference;
		typedef allocator_type::pointer				pointer;
		typedef allocator_type::const_pointer		const_pointer;
		// typedef a bidirectional iterator to value_type	iterator;
		// typedef a bidirectional iterator to const value_type	const_iterator;
		// typedef reverse_iterator<iterator>	reverse_iterator;
		// typedef reverse_iterator<const_iterator>	const_reverse_iterator;
		// typedef a signed integral type, identical to: iterator_traits<iterator>::difference_type	difference_type;
		// typedef an unsigned integral type that can represent any non-negative value of difference_type	size_type;

		explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type());
		template <class InputIterator>
  			map (InputIterator first, InputIterator last,
       		const key_compare& comp = key_compare(),
       		const allocator_type& alloc = allocator_type());
		map (const map& x);
		~map();

		map& operator= (const map& x);

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		size_type size() const;
		size_type max_size() const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);

		mapped_type& operator[] (const key_type& k);
		pair<iterator,bool> insert (const value_type& val);
		iterator insert (iterator position, const value_type& val);
		template <class InputIterator>
  			void insert (InputIterator first, InputIterator last);
		void erase (iterator position);
		size_type erase (const key_type& k);
	    void erase (iterator first, iterator last);
		void swap (map& x);
		void clear();
		key_compare key_comp() const;
		value_compare value_comp() const;
		iterator find (const key_type& k);
		const_iterator find (const key_type& k) const;
		size_type count (const key_type& k) const;
		iterator lower_bound (const key_type& k);
		const_iterator lower_bound (const key_type& k) const;
		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
		pair<iterator,iterator>             equal_range (const key_type& k);
		allocator_type get_allocator() const;
};
}

#endif
