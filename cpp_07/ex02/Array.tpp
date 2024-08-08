/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:30:58 by seblin            #+#    #+#             */
/*   Updated: 2024/08/08 23:56:06 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : _len(0), _array(new T[0])
{
	//TODO OK

	//create an empty array
	return ;
}	

template <typename T>	
Array<T>::Array( const Array & src ) :
	_len(src._len), _array(new T[src._len]())
{
	/*In both cases, modifying either the
	original array or its copy after copying musn’t affect the other array.*/
	//!
	*this = src;
	return ;
}

template <typename T>
Array<T> & Array<T>::operator=( const Array & rhs )
{
	/*In both cases, modifying either the
	original array or its copy after copying musn’t affect the other array.*/
	//! ?policicy if the size is different ? need implement operator[]
	if (this != &rhs)
	{
		for (size_t i = 0; i < this->_len && i < rhs.size(); i++)			
			if (this->_array[i] != rhs[i])
				this->_array[i] = rhs[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array( void )
{
	//TODO OK
	delete[] _array;
	return ;
}

template <typename T>
Array<T>::Array( const unsigned int n ) : _len(n), _array(new T[n]())//? const 
{
	// std::cout <<"NOOOOOOOOOOOOOOOOOOOOOOOOO"<< std::endl;
	// int *test = new int[n];
	// for (size_t i = 0; i < this->_len; i++)
	// 	std::cout << test[i];
		
	// std::cout << "STOP" << std::endl;
	// std::cout << std::endl;
	// for (size_t i = 0; i < this->_len; i++)
	// 	std::cout << _array[i];
	
	//TODO OK
	/*Creates an array of n elements
	initialized by default.
	Tip: Try to compile int * a = new int(); then display *a*/
	
}

template <typename T>
size_t Array<T>::size( void ) const
{
	//TODO OK
	
	/*A member function size() that returns the number of elements in the array. This
	member function takes no parameter and musn’t modify the current instance.*/
	return (this->_len);
}
#include <stdexcept>
template <typename T>
T & Array<T>::operator[]( const int i ) const
{
	if (i < 0 || static_cast<size_t>(i) >= this->_len)
		throw std::out_of_range("bad index");
	return (_array[i]);


	
	/*You MUST use the operator new[] to allocate memory. Preventive allocation (al-
	locating memory in advance) is forbidden. Your program must never access non-
	allocated memory.
	•Elements can be accessed through the subscript operator: [ ].
	•When accessing an element with the [ ] operator, if its index is out of bounds, an
	std::exception is thrown*/
}
 