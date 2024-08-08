/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:30:58 by seblin            #+#    #+#             */
/*   Updated: 2024/08/08 14:03:52 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) 
{
	//create an empty array
	return ;
}	

template <typename T>	
Array<T>::Array( const Array & src )
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
	//!
	return *this;
}

template <typename T>
Array<T>::~Array( void )
{
	return ;
}

template <typename T>
Array<T>::Array( const unsigned int n )//? const 
{
	/*Creates an array of n elements
	initialized by default.
	Tip: Try to compile int * a = new int(); then display *a*/
	
}

template <typename T>
size_t Array<T>::size( void ) const
{
	/*A member function size() that returns the number of elements in the array. This
	member function takes no parameter and musn’t modify the current instance.*/
	return 2;
}

template <typename T>
Array<T> & Array<T>::operator[]( const size_t i ) const
{
	/*You MUST use the operator new[] to allocate memory. Preventive allocation (al-
	locating memory in advance) is forbidden. Your program must never access non-
	allocated memory.
	•Elements can be accessed through the subscript operator: [ ].
	•When accessing an element with the [ ] operator, if its index is out of bounds, an
	std::exception is thrown*/
}
 