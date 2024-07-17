/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:44:36 by seblin            #+#    #+#             */
/*   Updated: 2024/07/17 15:28:55 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main ( void )
{
	Fixed fixed;
	fixed.setRawBits(9);
	std::cout << fixed.getRawBits() << std::endl;
	Fixed fixed_cpy(fixed);
	std::cout << fixed_cpy.getRawBits() << std::endl;
	Fixed fixed_ass;
	fixed_ass = fixed_cpy;
	std::cout << fixed_ass.getRawBits() << std::endl;

	return (0);
}