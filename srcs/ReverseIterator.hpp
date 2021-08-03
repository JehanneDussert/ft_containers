#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

# include "Vector_functions.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator {
	private:
		Iterator _base;
	public:
		typedef Iterator								iterator_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::pointer				pointer;

		reverse_iterator(void);
		explicit reverse_iterator(iterator_type x);
		template <class Iter> reverse_iterator(const reverse_iterator<Iter> &u);
		template <class Iter> reverse_iterator &operator=(const reverse_iterator<Iter> &u);
		Iterator base(void) const { return this->_base; };

		reference			operator*(void) const { return (--Iterator(this->_base)).operator*(); };
		pointer				operator->(void) const { return &this->operator*(); };

		reverse_iterator	&operator++(void) { this->_base.operator--(); return *this; };
		reverse_iterator	operator++(int) { return reverse_iterator(this->_base.operator--(0)); };
		reverse_iterator	&operator--(void) { this->_base.operator++(); return *this; };
		reverse_iterator	operator--(int) { return reverse_iterator(this->_base.operator++(0)); };

		template <class Iter>
		difference_type		operator-(const reverse_iterator<Iter> &u) { return u.base().operator-(this->_base); };
		reverse_iterator	operator+(difference_type n) const { return reverse_iterator(this->_base.getValue() - n); };
		reverse_iterator	&operator+=(difference_type n) { this->_base._value -= n; return *this; };
		reverse_iterator	operator-(difference_type n) const { return reverse_iterator(this->_base.getValue() + n); };
		reverse_iterator	&operator-=(difference_type n) { this->_base._value += n; return *this; }; //operator+=(n); return *this; };
		reference			operator[](difference_type n) const { return *this->operator+(n); };

		friend reverse_iterator	operator+(difference_type n, const reverse_iterator &rhs)
			{ return rhs.operator+(n); };

		template <class Iter> bool	operator==(const reverse_iterator<Iter> &rhs) const { return this->_base.operator==(rhs.base()); };
		template <class Iter> bool	operator!=(const reverse_iterator<Iter> &rhs) const { return this->_base.operator!=(rhs.base()); };
		template <class Iter> bool	operator< (const reverse_iterator<Iter> &rhs) const { return this->_base.operator> (rhs.base()); };
		template <class Iter> bool	operator<=(const reverse_iterator<Iter> &rhs) const { return this->_base.operator>=(rhs.base()); };
		template <class Iter> bool	operator> (const reverse_iterator<Iter> &rhs) const { return this->_base.operator< (rhs.base()); };
		template <class Iter> bool	operator>=(const reverse_iterator<Iter> &rhs) const { return this->_base.operator<=(rhs.base()); };

}; // ************************************************** class ReverseIte end //

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(void) : _base() { };

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(Iterator x) : _base(x) { };

template <class Iterator> template <class Iter>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter> &u) : _base(u.base()) { };

template <class Iterator> template <class Iter>
reverse_iterator<Iterator>	&reverse_iterator<Iterator>::operator=(const reverse_iterator<Iter> &u) {
	if (reinterpret_cast<const void *>(this) == reinterpret_cast<const void *>(&u))
		return (*this);
	this->_base = u.base();
	return (*this);
};

}

#endif