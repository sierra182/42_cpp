/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:12:52 by seblin            #+#    #+#             */
/*   Updated: 2024/08/25 14:22:17 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	Serializer( void );
	Serializer( const Serializer & src );
	Serializer & operator=( const Serializer & rhs );
	virtual ~Serializer( void );
	
	public:
			
		static uintptr_t serialize( Data* ptr );
		static Data* deserialize( uintptr_t raw );
};