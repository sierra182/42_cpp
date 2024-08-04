/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:26:15 by seblin            #+#    #+#             */
/*   Updated: 2024/08/04 18:32:57 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data( void )
{
	return ;
}

Data::~Data( void )
{
	return ;
}

Data::Data( const Data & src )
{
	*this = src;
	return ;
}

Data & Data::operator=( const Data & rhs )
{
	//!
	// if (this != &rhs)
	// 	if (this->   != rhs.   )
}