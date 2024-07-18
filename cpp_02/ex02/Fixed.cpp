/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:44:43 by seblin            #+#    #+#             */
/*   Updated: 2024/07/18 19:58:14 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->setRawBits(0);
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	this->setRawBits(0);
	*this = src;
	return ;
}

Fixed::Fixed( int const nbr )
{
	this->setRawBits( nbr << 8 );
}

Fixed::Fixed( float const nbr )
{
	int n_int = static_cast<int> (nbr);
	int dec = n_int << 8;	
	float frac = 256 * (nbr - n_int);
	frac = roundf(frac);
	this->setRawBits(static_cast<int>(frac) + dec);	
}
Fixed&	Fixed::operator=( Fixed const & rhs )
{	
	if (this->getRawBits() != rhs._value)	
		this->setRawBits(rhs._value);	
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

float	Fixed::toFloat( void ) const
{
	return ((static_cast<float>((this->getRawBits() & 0xFF) / 256.0f))
		+ this->toInt());	
}

int		Fixed::toInt( void ) const
{
	return (this->getRawBits() >> 8);
}

std::ostream & operator<<( std::ostream & os, Fixed const & rhs )
{
	os << rhs.toFloat();
	return (os);
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed &	Fixed::operator++( void )
{
	this->_value++;
	return (*this);
}

Fixed 	Fixed::operator++( int )
{
	Fixed fixed(*this);
	this->_value++;
	return (fixed);
}

Fixed &	Fixed::operator--( void )
{
	this->_value--;
	return (*this);
}

Fixed 	Fixed::operator--( int )
{
	Fixed fixed(*this);
	this->_value--;
	return (fixed);
}

Fixed const & Fixed::max( Fixed const & a, Fixed const & b)
{
	return ( a._value > b._value ? a : b );
}