/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:30:55 by seblin            #+#    #+#             */
/*   Updated: 2024/08/08 14:03:45 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

template <typename T>
class Array
{
	T * _array;
	// T & _array_ref;
	 
	public:
	
		Array( void );
		~Array( void );
		Array( const Array & src );
		Array & operator=( const Array & rhs );

		Array( const unsigned int n );//? const param
		Array & operator[]( const size_t i ) const;
		size_t size( void ) const;
};

#include "Array.tpp"