/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:30:55 by seblin            #+#    #+#             */
/*   Updated: 2024/08/07 13:36:21 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array
{
	public:

		Array( void );
		Array( const Array & src );
		Array & operator=( const Array & rhs );
		virtual ~Array( void );	
};

#include "Array.tpp"