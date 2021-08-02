#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "Utils.hpp"

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
		// typedef vector::iterator				iterator;
		//typedef typename value_type::const_iterator			const_iterator;
		// typedef ft::reverse_iterator<iterator>				reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

		// class out_of_range : public std::logic_error
		// {
		// 	public:
		// 		explicit out_of_range (const std::string& what_arg);
		// };
		
		/*****************/
		/*** ITERATORS ***/
		/*****************/

		// class	random_iterator
		// {
		// 	protected:
		// 		value_type	*_value;
		// 	public:
		// 		typedef	value_type&	reference;
		// 		typedef	value_type&	const_reference;
		// 		typedef	value_type*	pointer;
		// 		typedef ptrdiff_t	difference_type;
		// 		random_iterator(void) { return ; };
		// 		random_iterator(value_type *value) : _value(x) { return ; };
		// 		random_iterator(const random_iterator& x) { *this = x ; return ; }
		// 		random_iterator				&operator=(const iterator& x) { _value = x._value ; return *this; };
		// 		// bool						operator==(const iterator& x) const;
		// 		// bool						operator!=(const iterator& x) const;
		// 		// random_iterator<value_type>	&operator++(void);
		// 		// random_iterator<value_type>	operator++(int);
		// 		// random_iterator<value_type>	&operator--(void);
		// 		// random_iterator<value_type>	operator--(int);
		// 		// random_iterator<value_type>	operator+(const iterator& x);
		// 		// random_iterator<value_type>	operator+(difference_type);
		// 		// random_iterator<value_type>	operator-(difference_type);
		// 		// bool						operator<(const iterator& x) const;
		// 		// bool						operator>(const iterator& x) const;
		// 		// bool						operator<=(const iterator& x) const;
		// 		// bool						operator>=(const iterator& x) const;
		// 		// difference_type				operator-(const iterator& x) const;
		// }
		class iterator
		{
			public:
				typedef	value_type&	reference;
				typedef	value_type&	const_reference;
				typedef	value_type*	pointer;
				typedef ptrdiff_t	difference_type;
				iterator(void) { return; };
				iterator(value_type *x) : _value(x) { return ; };
				iterator(const iterator& x) { *this = x; return ;};
				// iterator(const const_iterator& x) { _value = x.getValue() ; return ;};
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
				iterator	operator+(difference_type n);
				iterator	operator-(difference_type);
				bool		operator<(const iterator& x) const;
				bool		operator>(const iterator& x) const;
				bool		operator<=(const iterator& x) const;
				bool		operator>=(const iterator& x) const;
				difference_type	operator-(const iterator& x) const;
				iterator	&operator+=(difference_type);
				iterator	&operator-=(difference_type);
				reference	operator[](size_type n);
				const_reference operator[](size_type n) const;
				difference_type	operator[](const iterator&) const;
				value_type	*getValue(void) const { return _value; };
			private:
				value_type	*_value;
				// friend class const_iterator;
		};
		class const_iterator
		{
			public:
				typedef	value_type&	reference;
				typedef	value_type&	const_reference;
				typedef	value_type*	pointer;
				typedef ptrdiff_t	difference_type;
				const_iterator(void) { return; };
				const_iterator(value_type *x) : _value(x) { return ; };
				const_iterator(const const_iterator& x) { *this = x; return ;};
				const_iterator(const iterator& x) { _value = x.getValue() ; return ;};
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
				const_iterator	operator+(difference_type n);
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
				value_type		*getValue(void) const { return _value; };
			private:
				value_type*	_value;
				// friend class vector;
		};
		// template <class Iterator> class iterator_traits
		// {
		// 	public:
		// 		difference_type	difference_type;
		// 		value_type		value_type;
		// 		value_type*		pointer;
		// 		value_type&		reference;
		// 		// iterator_category	random_access_iterator_tag;
		// 		template <class T> class iterator_traits<T*>
		// 		{
		// 			public:
		// 				difference_type	difference_type;
		// 				value_type		value_type;
		// 				value_type*		pointer;
		// 				value_type&		reference;
		// 				// iterator_category	random_access_iterator_tag;
		// 		};
		// 		template <class T> class iterator_traits<const T*>
		// 		{
		// 			public:
		// 				difference_type	difference_type;
		// 				value_type		value_type;
		// 				value_type*		pointer;
		// 				value_type&		reference;
		// 				// iterator_category	random_access_iterator_tag;
		// 		};
		// };

		template <class Iterator>
		class reverse_iterator
		{
			typedef Iterator											iterator_type;
			// Need to do iterator_traits<>
			// typedef typename iterator_traits<Iterator>::difference_type	difference_type;
			// typedef typename iterator_traits<Iterator>::reference		reference;
			// typedef typename iterator_traits<Iterator>::pointer			pointer;

			reverse_iterator(void);
			explicit reverse_iterator (iterator_type it);
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it);
		
			iterator_type base() const; // Returns a copy of the base iterator.
			reference operator*() const;
			reverse_iterator operator+ (difference_type n) const;
			reverse_iterator& operator++();
			reverse_iterator  operator++(int);
			reverse_iterator& operator+= (difference_type n);
			reverse_iterator operator- (difference_type n) const;
			reverse_iterator& operator--();
			reverse_iterator  operator--(int);
			reverse_iterator& operator-= (difference_type n);
			pointer operator->() const;
			reference operator[] (difference_type n) const;
		};
		// template <class Iterator>
  		// bool operator== (const reverse_iterator<Iterator>& lhs,
        //            const reverse_iterator<Iterator>& rhs);
		// template <class Iterator>
  		// bool operator!= (const reverse_iterator<Iterator>& lhs,
        //            const reverse_iterator<Iterator>& rhs);
		// template <class Iterator>
  		// bool operator<  (const reverse_iterator<Iterator>& lhs,
        //            const reverse_iterator<Iterator>& rhs);
		// template <class Iterator>
  		// bool operator<= (const reverse_iterator<Iterator>& lhs,
        //            const reverse_iterator<Iterator>& rhs);
		// template <class Iterator>
 		// bool operator>  (const reverse_iterator<Iterator>& lhs,
        //            const reverse_iterator<Iterator>& rhs);
		// template <class Iterator>
  		// bool operator>= (const reverse_iterator<Iterator>& lhs,
        //            const reverse_iterator<Iterator>& rhs);
		// template <class Iterator>
  		// reverse_iterator<Iterator> operator+ (
        //      typename reverse_iterator<Iterator>::difference_type n,
        //      const reverse_iterator<Iterator>& rev_it);
		// template <class Iterator>
		// typename reverse_iterator<Iterator>::difference_type operator- (
		// 	const reverse_iterator<Iterator>& lhs,
		// 	const reverse_iterator<Iterator>& rhs);

		/**********************/
		/**	MEMBER FUNCTIONS **/
		/**********************/

		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		vector (const vector& x);
		template <class InputIterator>
		vector(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first,
		InputIterator last, const allocator_type& alloc = allocator_type());
		virtual ~vector(void);

		/*
		**	Iterators
		*/
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		/*
		**	Capacity
		*/
		size_type size() const;
		size_type max_size() const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);

		/*
		**	Element access
		*/
		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
		reference at(size_type n);
		const_reference at(size_type n) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		/*
		**	Modifiers
		*/
		template <class InputIterator>
  			void assign(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last);
		void assign(size_type n, const value_type& val);
		void push_back(const value_type& val);
		void pop_back();
		iterator	insert(iterator position, const value_type& val);
		void		insert(iterator position, size_type n, const value_type &val);
		template <class InputIterator>
			void insert(iterator position, InputIterator first, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (vector& x);
		void clear();

		/*
		**	Allocator
		*/
		allocator_type get_allocator() const;

		/*
		** 	TO COMPLETE
		*/
		vector &operator=(const vector& x);

		//?
		class	OutOfRangeException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return "Terminating with uncaught exception of type std::out_of_range: vector.";
				}
		};
	private:
		value_type											*_tab;
		size_type											_size;
		size_type											_max_size;
		allocator_type										_alloc;
		size_type											_capacity;
		void												_clear_tab(void);	
};

	/**************************************/
	/*** NON MEMBER FUNCTIONS OVERLOADS ***/
	/**************************************/

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
	template <class Iterator>
	Iterator	operator+(int n, const Iterator& it) { return Iterator(n + it.getValue()); }

	/*
	**	TO COMPLETE
	*/
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

	/*
	**	TO DO
	*/
	// template < class T, class Alloc = allocator<T> > class vector; // generic template
	// template <class Alloc> class vector<bool,Alloc>;               // bool specialization
}

#endif
