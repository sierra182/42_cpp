/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:12:55 by seblin            #+#    #+#             */
/*   Updated: 2024/08/04 18:30:24 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void )
{
	return ;
}

Serializer::~Serializer( void )
{
	return ;
}

Serializer::Serializer( const Serializer & src )
{
	*this = src;
	return ;
}

Serializer & Serializer::operator=( const Serializer & rhs )
{
	(void) rhs;
	return ;
}

uintptr_t Serializer::serialize( Data* ptr )
{
	
}

Data* Serializer::deserialize( uintptr_t raw )
{
	
}