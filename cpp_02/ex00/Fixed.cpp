/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:44:43 by seblin            #+#    #+#             */
/*   Updated: 2024/07/17 17:16:54 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
	return ;
}

Fixed&	Fixed::operator=( Fixed const & rhs )
{
	this->_value = rhs._value;
	return (*this);
}

Fixed::~Fixed()
{
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

