/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:12:52 by seblin            #+#    #+#             */
/*   Updated: 2024/08/04 18:30:18 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Serializer
{
	Serializer( void );
	Serializer( const Serializer & src );
	
	public:
	
		virtual ~Serializer( void );
		Serializer & operator=( const Serializer & rhs );
		
		static uintptr_t serialize( Data* ptr );
		static Data* deserialize( uintptr_t raw );
};