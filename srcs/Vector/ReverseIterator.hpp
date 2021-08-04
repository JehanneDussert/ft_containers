#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

# include "RandomIterator.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator {
	protected:
		Iterator _base;
	public:
		typedef Iterator								iterator_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::pointer				pointer;

		reverse_iterator(void);
		explicit reverse_iterator(iterator_type x);
		template <class Iter> reverse_iterator(const reverse_iterator<Iter> &x);
		template <class Iter> reverse_iterator &operator=(const reverse_iterator<Iter> &x);
		Iterator base(void) const { return _base; };

		reference			operator*(void) const { return (--Iterator(_base)).operator*(); };
		pointer				operator->(void) const { return &operator*(); };

		reverse_iterator	&operator++(void) { _base.operator--(); return *this; };
		reverse_iterator	operator++(int) { return reverse_iterator(_base.operator--(0)); };
		reverse_iterator	&operator--(void) { _base.operator++(); return *this; };
		reverse_iterator	operator--(int) { return reverse_iterator(_base.operator++(0)); };

		template <class Iter>
		difference_type		operator-(const reverse_iterator<Iter> &x) { return x.base().operator-(_base); };
		reverse_iterator	operator+(difference_type n) const { return reverse_iterator(_base.getValue() - n); };
		reverse_iterator	&operator+=(difference_type n) { _base.operator-=(n); return *this; };
		reverse_iterator	operator-(difference_type n) const { return reverse_iterator(_base.getValue() + n); };
		reverse_iterator	&operator-=(difference_type n) { _base.operator+=(n); return *this; };
		reference			operator[](difference_type n) const { return *operator+(n); };

		friend reverse_iterator	operator+(difference_type n, const reverse_iterator &x) { return x.operator+(n); };

		template <class Iter>
		bool				operator==(const reverse_iterator<Iter> &x) const { return _base.operator==(x.base()); };
		template <class Iter>
		bool				operator!=(const reverse_iterator<Iter> &x) const { return _base.operator!=(x.base()); };
		template <class Iter>
		bool				operator< (const reverse_iterator<Iter> &x) const { return _base.operator> (x.base()); };
		template <class Iter>
		bool				operator<=(const reverse_iterator<Iter> &x) const { return _base.operator>=(x.base()); };
		template <class Iter>
		bool				operator> (const reverse_iterator<Iter> &x) const { return _base.operator< (x.base()); };
		template <class Iter>
		bool				operator>=(const reverse_iterator<Iter> &x) const { return _base.operator<=(x.base()); };

};

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(void) : _base() { };
template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(Iterator x) : _base(x) { };
template <class Iterator> template <class Iter>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter> &x) : _base(x.base()) { return ; };
template <class Iterator> template <class Iter>
reverse_iterator<Iterator>	&reverse_iterator<Iterator>::operator=(const reverse_iterator<Iter> &x)
{
	if (reinterpret_cast<const void *>(this) == reinterpret_cast<const void *>(&x))
		return (*this);
	_base = x.base();
	return (*this);
};

}

#endif