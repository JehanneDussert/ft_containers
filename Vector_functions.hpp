#ifndef VECTOR_FUNCTIONS_HPP
# define VECTOR_FUNCTIONS_HPP

# include "Vector.hpp"

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector (const allocator_type& alloc = allocator_type()) : allocator_type(alloc) { return ;};

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector (size_type n, const value_type& val = value_type(),
const allocator_type& alloc = allocator_type()) : size_type(size_type), value_type(value_type),
allocator_type(allocator_type) { return ; };

// template <class InputIterator>
//     Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); //range constructor

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector (const vector& x)
{
    // copy constructor
    *this = x;
}; 

template <typename T, typename Alloc>		
Vector<T, Alloc>::~Vector(void) { return ;};

/*
** OPERATORS
*/

template <typename T, typename Alloc>
reference Vector<T, Alloc>::operator[] (size_type n)
{
    if (n >= _size)
        throw std::exception();
    return _tab[n];
}

template <typename T, typename Alloc>
const_reference Vector<T, Alloc>::operator[] (size_type n) const
{
    if (n >= _size)
        throw std::exception();
    return _tab[n];
}

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    if (lhs.size() == rhs.size()) // check if lsh.tab == rhs.tab etc
        return true;
    return false;
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    lhs == rhs ? false : true;
}

template <class T, class Alloc>
bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

#endif