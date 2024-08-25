/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:12:55 by seblin            #+#    #+#             */
/*   Updated: 2024/08/25 14:21:22 by svidot           ###   ########.fr       */
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

Serializer::Serializer( const Serializer & )
{	
	return ;
}

Serializer & Serializer::operator=( const Serializer & )
{	
	return (*this);
}

uintptr_t Serializer::serialize( Data* ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data *>(raw));
}