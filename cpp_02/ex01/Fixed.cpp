/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:44:43 by seblin            #+#    #+#             */
/*   Updated: 2024/07/18 15:24:07 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(0);
	*this = src;
	return ;
}

Fixed::Fixed( int const nbr )
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits( nbr << 8 );
}

Fixed::Fixed( float const nbr )
{
	std::cout << "Float constructor called" << std::endl;

	int n_int = static_cast<int> (nbr);
	int dec = n_int << 8;	
	int frac = (256 * (nbr - n_int)); //!roundf ????
	std::cout << "FRAC" << frac << std::endl;	
	std::cout << "FRAC" << frac << std::endl;
	int masq = frac & 0xFF;
	int res = masq + dec;
	this->setRawBits(res);
}
Fixed&	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;	
	if (this->getRawBits() != rhs._value)	
		this->setRawBits(rhs._value);	
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	
	return (0.0);
}

int		Fixed::toInt( void ) const
{
	return (this->getRawBits() >> 8);
}

std::ostream & operator<<( std::ostream & os, Fixed const & rhs )
{
	os << rhs.getRawBits();
	return (os);
}