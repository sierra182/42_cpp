/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:30:55 by seblin            #+#    #+#             */
/*   Updated: 2024/08/09 17:17:00 by seblin           ###   ########.fr       */
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
		T & operator[]( const int i ) const;
		size_t size( void ) const;		
};

#include "Array.tpp"