#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>

namespace ft
{
template < class T, class Alloc = std::allocator<T> >
class	Vector
{
	private:
		value_type											*_tab;
		size_type											_size;
		size_type											_max_size;
		allocator_type										_alloc;
		size_type											_capacity;
		void												_clear_tab(void);
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename value_type::iterator				iterator;
		typedef typename value_type::const_iterator			const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		//typedef a signed integral type, identical to: iterator_traits<iterator>::difference_type	difference_type;
		typedef size_t										size_type;

		/*
		** 	DONE
		*/
		explicit Vector (const allocator_type& alloc = allocator_type()); // empty container
		explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); //fill constructor
		Vector (const vector& x); // copy constructor
		virtual ~Vector(void);
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		size_type size() const;
		size_type max_size() const;
		size_type capacity() const;
		bool empty() const;
		reference at (size_type n);
		const_reference at (size_type n) const;
		void resize (size_type n, value_type val = value_type());
		void reserve (size_type n);
		class	OutOfRangeException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return "Terminating with uncaught exception of type std::out_of_range: vector.";
				}
		}

		/*
		** 	TO COMPLETE
		*/
		Vector &operator= (const vector& x);
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		
		/*
		** 	TO DO
		*/
		template <class InputIterator>
        Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); //range constructor


		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);
		void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (vector& x);
		void clear();
		allocator_type get_allocator() const;

};
	/*
	** 	DONE
	*/
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

	/*
	**	TO DO
	*/
	template < class T, class Alloc = allocator<T> > class vector; // generic template
	template <class Alloc> class vector<bool,Alloc>;               // bool specialization
}

#endif
