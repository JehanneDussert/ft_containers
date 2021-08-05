#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include "../Vector/Vector_functions.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class	stack
	{
		public:
			typedef T				value_type;
			typedef Container		container_type;
			typedef unsigned int	size_type;

			explicit				stack(const container_type& ctnr = container_type());
			virtual 				~stack(void) { return ; };
			bool					empty() const;
			size_type				size() const;
			value_type& 			top();
			const value_type&		top() const;
			void 					push(const value_type& val);
			void 					pop();
			stack					&operator=(const stack& x);
			friend bool 			operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs._ctnr == rhs._ctnr); };
			friend bool 			operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs._ctnr < rhs._ctnr); };

		private:
			container_type	_ctnr;
	};

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
}

#endif
