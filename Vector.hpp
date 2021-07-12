#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>

namespace ft
{
template< typename T, typename Alloc = std::allocator<T> >
class	vector
{
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		//typedef typename value_type::iterator				iterator;
		//typedef typename value_type::const_iterator			const_iterator;
		// typedef ft::reverse_iterator<iterator>				reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

		/*
		** 	DONE
		*/
		explicit vector (const allocator_type& alloc = allocator_type()); // empty container
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); //fill constructor
		vector (const vector& x); // copy constructor
		virtual ~vector(void);
		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
		size_type size() const;
		size_type max_size() const;
		size_type capacity() const;
		bool empty() const;
		reference at (size_type n);
		const_reference at (size_type n) const;
		void resize (size_type n, value_type val = value_type());
		void reserve (size_type n);
		void clear();
		void push_back (const value_type& val);
		void pop_back();
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		//?
		class	OutOfRangeException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return "Terminating with uncaught exception of type std::out_of_range: vector.";
				}
		};
		class iterator
		{
			public:
				/*
				**	DONE
				*/
				typedef	value_type&	reference;
				typedef	value_type*	pointer;
				typedef ptrdiff_t	difference_type;
				iterator(void) { return; };
				iterator(const iterator& x) { this->_value = x._value; return ;};
				~iterator(void) { return; };
				reference	operator*(void) const;
				pointer		operator->(void)const;
				iterator	&operator=(const iterator& x);
				bool		operator==(const iterator& x) const;
				bool		operator!=(const iterator& x) const;
				iterator	&operator++(void);
				iterator	operator++(int);
				iterator	&operator--(void);
				iterator	operator--(int);
				iterator	operator+(const iterator& x);
				iterator	operator-(const iterator& x);
				iterator	operator+(difference_type);
				iterator	operator-(difference_type);
				bool		operator<(const iterator& x) const;
				bool		operator>(const iterator& x) const;
				bool		operator<=(const iterator& x) const;
				bool		operator>=(const iterator& x) const;
				iterator	&operator+=(difference_type);
				iterator	&operator-=(difference_type);
				reference	operator[](size_type n);
				const_reference operator[](size_type n) const;
				difference_type	operator[](const iterator&) const;
				difference_type	operator-(const iterator& x) const;
				//*a = t; ?
			private:
				typedef value_type*	_value;
				typedef	iterator	first;
				typedef	iterator	last;
				
				//friend class vector;
		};
		class const_iterator
		{
			public:
				/*
				**	DONE
				*/
				typedef	value_type&	reference;
				typedef	value_type*	pointer;
				typedef ptrdiff_t	difference_type;
				const_iterator(void) { return; };
				const_iterator(const const_iterator& x) { this->_value = x._value; return ;};//*a = t; ?
				~const_iterator(void) { return; };
				reference	operator*(void) const;
				pointer		operator->(void)const;
				const_iterator	&operator=(const const_iterator& x);
				bool		operator==(const const_iterator& x) const;
				bool		operator!=(const const_iterator& x) const;
				const_iterator	&operator++(void);
				const_iterator	operator++(int);
				const_iterator	&operator--(void);
				const_iterator	operator--(int);
				const_iterator	operator+(const const_iterator& x);
				const_iterator	operator-(const const_iterator& x);
				const_iterator	operator+(difference_type);
				const_iterator	operator-(difference_type);
				bool			operator<(const const_iterator& x) const;
				bool			operator>(const const_iterator& x) const;
				bool			operator<=(const const_iterator& x) const;
				bool			operator>=(const const_iterator& x) const;
				const_iterator	&operator+=(difference_type);
				const_iterator	&operator-=(difference_type);
				reference		operator[](size_type n);
				const_reference operator[](size_type n) const;
				difference_type	operator[](const const_iterator&) const;
				difference_type	operator-(const const_iterator& x) const;
			private:
				typedef value_type*	_value;
				//friend class vector;
		};

		/*
		** 	TO COMPLETE
		*/
		vector &operator=(const vector& x);
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;
		
		/*
		** 	TO DO
		*/
		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); //range constructor

		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (vector& x);
		allocator_type get_allocator() const;
	private:
		value_type											*_tab;
		size_type											_size;
		size_type											_max_size;
		allocator_type										_alloc;
		size_type											_capacity;
		void												_clear_tab(void);	
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
	// template < class T, class Alloc = allocator<T> > class vector; // generic template
	// template <class Alloc> class vector<bool,Alloc>;               // bool specialization
}

#endif
