/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:44:43 by seblin            #+#    #+#             */
/*   Updated: 2024/07/17 15:31:20 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
	return ;
}

int Fixed::getRawBits( void ) const
{
	return (this->_value);	
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;	
}

Fixed	Fixed::operator=( Fixed const & rhs)
{
	*this = rhs;
	return (*this);
}
