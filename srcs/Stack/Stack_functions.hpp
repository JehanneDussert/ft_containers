#ifndef STACK_FUNCTIONS_HPP
# define STACK_FUNCTIONS_HPP

#include "Stack.hpp"

namespace ft
{

/**********************/
/**	MEMBER FUNCTIONS **/
/**********************/

template <typename T, class Container>
stack<T, Container>::stack(const container_type& ctnr) : _size(0), _tab(NULL) { (void)ctnr; return ; };

template <typename T, class Container>
bool 		stack<T, Container>::empty() const { return _ctnr.empty(); };

template <typename T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const { return _ctnr.size(); };

template <typename T, class Container>
T&	stack<T, Container>::top() { return _ctnr.back(); };

template <typename T, class Container>
const T&	stack<T, Container>::top() const { return _ctnr.top(); };

template <typename T, class Container>
void	stack<T, Container>::push(const T& val) { _ctnr.push_back(val); };

template <typename T, class Container>
void	stack<T, Container>::pop() { _ctnr.pop_back(); };

template <typename T, class Container>
bool	stack<T, Container>::operator==(const stack<T,Container>& rhs) { return _ctnr == rhs._ctnr; };

template <typename T, class Container>
bool	stack<T, Container>::operator<(const stack<T,Container>& rhs) { return _ctnr < rhs._ctnr; };

/**************************************/
/*** NON MEMBER FUNCTIONS OVERLOADS ***/
/**************************************/

template <class T, class Container>
bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return lhs == rhs;
}

template <class T, class Container>
bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return lhs != rhs;
}

template <class T, class Container>
bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return lhs < rhs;
}

template <class T, class Container>
bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return lhs <= rhs;
}

template <class T, class Container>
bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return lhs.operator>(rhs);
}

template <class T, class Container>
bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return lhs.operator>=(rhs);
}

// template <class T, class Container>
// void swap(stack<T,Container>& x, stack<T,Container>& y) noexcept(noexcept(x.swap(y)))
// {
// 	ft::vector<T::swap(x, y);
// }

}

#endif
