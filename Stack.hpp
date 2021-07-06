#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
namespace ft
{
template <class T, class Container = deque<T> >
class	Stack
{
	private:
	public:
		typedef T			value_type;
		typedef Container	container_type;
		unsigned int		size_type;

		explicit stack (const container_type& ctnr = container_type());
		bool empty() const;
		size_type size() const;
		value_type& top();
		const value_type& top() const;
		void push (const value_type& val);
		void pop();
};
template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
template <class T, class Container>
  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
template <class T, class Container>
  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
template <class T, class Container>
  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
template <class T, class Container>
  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
template <class T, class Container>
  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
}

template <class T, class Container>
  void swap (stack<T,Container>& x, stack<T,Container>& y) noexcept(noexcept(x.swap(y)));

#endif
