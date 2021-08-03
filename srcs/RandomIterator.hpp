#ifndef RANDOMITERATOR_HPP
# define RANDOMITERATOR_HPP

namespace ft {
	template <typename type>
    class Random
    {
		protected:
			type				*_value;
		public:
			typedef	type		value_type;
			typedef	value_type&	reference;
			typedef	value_type&	const_reference;
			typedef	value_type*	pointer;
			typedef ptrdiff_t	difference_type;

			Random(void) : _value(NULL) { return ; };
			Random(type *x) : _value(x) { return ; };
			Random(const Random& x) { *this = x; return ;};
			virtual ~Random(void) { return ; };
			Random&	operator=(Random const &x)
			{
				if (this == &x)
					return *this;
				this->_value = x._value;
				return *this;
			}
			
			value_type		*getValue(void) const { return _value; };
			bool			operator==(const Random &x) const { return (this->_value == x._value ? true : false);};
			bool			operator!=(const Random &x) const { return (this->_value != x._value ? true : false);};
			bool			operator<(const Random &x) const { return (this->_value < x._value ? true : false);};
			bool			operator<=(const Random &x) const { return (this->_value <= x._value ? true : false);};
			bool			operator>(const Random &x) const { return (this->_value > x._value ? true : false);};
			bool			operator>=(const Random &x) const { return (this->_value >= x._value ? true : false);};

			Random<type>	&operator++(void) { this->_value++; return *this;};
			Random<type>	operator++(int) { Random tmp(*this); this->operator++(); return tmp;};
			Random<type>	&operator--(void) { this->_value--; return *this;};
			Random<type>	operator--(int) { Random tmp(*this); this->operator--(); return tmp;};

			difference_type	operator-(const Random &x) const { return (this->_value - x.getValue()); };
			Random<type>	operator+(difference_type n) const { return Random(this->_value + n); };
			Random<type>	operator-(difference_type n) const { return Random(this->_value - n); };
			friend Random<type>	operator+(difference_type n, const Random &x)
				{ return x.operator+(n); };
    };
}

#endif