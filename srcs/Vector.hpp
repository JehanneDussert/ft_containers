#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "Utils.hpp"
# include "ReverseIterator.hpp"
# include "RandomIterator.hpp"

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
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;
		
		/*****************/
		/*** ITERATORS ***/
		/*****************/

		class iterator : public Random<value_type>
		{
			public:
				typedef	value_type&	reference;
				typedef	value_type&	const_reference;
				typedef	value_type*	pointer;
				typedef ptrdiff_t	difference_type;

				iterator(void) : Random<value_type>() { return; };
				iterator(value_type *x) : Random<value_type>(x) { return ; };
				iterator(const Random<value_type>& x) : Random<value_type>(x) { return ; };

				reference	operator*(void) const;
				pointer		operator->(void)const;
				iterator	&operator+=(difference_type);
				iterator	&operator-=(difference_type);
				reference	operator[](size_type n);
				const_reference operator[](size_type n) const;
				difference_type	operator[](const Random<value_type>&) const;
				// iterator	&operator=(const iterator& x);
				iterator	operator-(difference_type n) const;
				difference_type	operator-(const Random<value_type>& x) const;
				iterator	operator+(difference_type n) const;
				// friend iterator	operator+(difference_type n, const Random<value_type> &x);
				iterator	&operator++(void);
				iterator	operator++(int);
				iterator	&operator--(void);
				iterator	operator--(int);
		};
		class const_iterator : public Random<value_type>
		{
			public:
				typedef	value_type const&	reference;
				typedef	value_type const&	const_reference;
				typedef	value_type const*	pointer;
				typedef ptrdiff_t	difference_type;

				const_iterator(void) : Random<value_type>() { return; };
				const_iterator(value_type *x) : Random<value_type>(x) { return ; };
				const_iterator(const Random<value_type>& x) : Random<value_type>(x) { return ; };

				reference	operator*(void) const;
				pointer		operator->(void)const;
				const_iterator	&operator+=(difference_type);
				const_iterator	&operator-=(difference_type);
				reference	operator[](size_type n);
				const_reference operator[](size_type n) const;
				difference_type	operator[](const Random<value_type>&) const;
				// iterator	&operator=(const iterator& x);
				const_iterator	operator-(difference_type) const;
				difference_type	operator-(const Random<value_type>& x) const;
				const_iterator	operator+(difference_type n) const;
				// friend iterator	operator+(difference_type n, const Random<value_type> &x) { return x.operator+(n); };
				const_iterator	&operator++(void);
				const_iterator	operator++(int);
				const_iterator	&operator--(void);
				const_iterator	operator--(int);
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

		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;

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
		vector &operator=(const vector& x);

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
  		void 		assign(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last);
		void 		assign(size_type n, const value_type& val);
		void 		push_back(const value_type& val);
		void 		pop_back();
		iterator	insert(iterator position, const value_type& val);
		void		insert(iterator position, size_type n, const value_type &val);
		template <class InputIterator>
		void 		insert(iterator position, InputIterator first, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last);
		iterator 	erase (iterator position);
		iterator	erase (iterator first, iterator last);
		void 		swap (vector& x);
		void 		clear();

		/*
		**	Allocator
		*/
		allocator_type get_allocator() const;

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
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& x);
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& x);
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& x);
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& x);
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& x);
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& x);
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

	/*
	**	TO DO
	*/
	// template < class T, class Alloc = allocator<T> > class vector; // generic template
	// template <class Alloc> class vector<bool,Alloc>;               // bool specialization
}

#endif
