/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:30:00 by seblin            #+#    #+#             */
/*   Updated: 2024/07/19 07:09:43 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

void	other_test( void )
{
	std::cout << std::endl << "other test" << std::endl << std::endl;
	Fixed a(42);
	Fixed b(40);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	if (a < b)
		std::cout << "a is < b" << std::endl;
	else
		std::cout << "a is > b" << std::endl;
	if (a > b)
		std::cout << "a is > b" << std::endl;
	else
		std::cout << "a is < b" << std::endl;
	Fixed c = b;
	std::cout << "c is " << c << std::endl;
	if (b <= c)
		std::cout << "b is <= c" << std::endl;
	if (b <= c)
		std::cout << "b is >= c" << std::endl;
	if (b == c)
		std::cout << "b is == c" << std::endl;
	if (!(b != c))
		std::cout << "b is not != c" << std::endl;
	std::cout << "b + c = " << b + c << std::endl;
	std::cout << "b - c = " << b - c << std::endl;
	std::cout << "b * c = " << b * c << std::endl;
	std::cout << "b / c = " << b / c << std::endl;
	std::cout << "b / 0 = " << b / 0 << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;	
	std::cout << a-- << std::endl;
	std::cout << a << std::endl << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( const_cast<const Fixed&> (a),
		const_cast<const Fixed&> (b) ) << std::endl;
	std::cout << Fixed::min( const_cast<const Fixed&> (a),
		const_cast<const Fixed&> (b) ) << std::endl;	
}

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	other_test();

	return 0;
}