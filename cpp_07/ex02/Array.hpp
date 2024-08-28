/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:30:55 by seblin            #+#    #+#             */
/*   Updated: 2024/08/28 14:47:04 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

template <typename T>
class Array
{
	unsigned int	_len;
	T *				_array;
	
	public:
	
		Array( void );
		~Array( void );
		Array( const Array & src );
		Array & operator=( const Array & rhs );

		Array( const unsigned int n );
		
		const T & operator[]( const int i ) const;
		T & operator[]( const int i );
		size_t size( void ) const;		
};

#include "Array.tpp"