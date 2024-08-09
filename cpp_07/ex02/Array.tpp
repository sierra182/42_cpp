/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:30:58 by seblin            #+#    #+#             */
/*   Updated: 2024/08/09 16:19:05 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array( void ) : _len(0), _array(new T[0])
{
	return ;
}	

template <typename T>	
Array<T>::Array( const Array & src ) : _array(NULL)
{
	*this = src;
	return ;
}

template <typename T>
Array<T> & Array<T>::operator=( const Array & rhs )
{	
	if (this != &rhs)
	{
		delete [] this->_array;
		this->_array = new T[rhs._len]();	
		this->_len = rhs._len;		
		for (unsigned int i = 0; i < this->_len; i++)	
			this->_array[i] = rhs[i];					
	}
	return *this;
}

template <typename T>
Array<T>::~Array( void )
{
	delete[] _array;
	return ;
}

template <typename T>
Array<T>::Array( const unsigned int n ) : _len(n), _array(new T[n]()) 
{
	return ;	
}

template <typename T>
size_t Array<T>::size( void ) const
{	
	return (this->_len);
}

template <typename T>
T & Array<T>::operator[]( const int i ) const
{
	if (i < 0 || i >= static_cast<int> (this->_len))
		throw std::out_of_range(" Exception: \e[1;31mindex is out \
of bounds!\e[0m");
	return (_array[i]);
}
 