/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:44:36 by seblin            #+#    #+#             */
/*   Updated: 2024/07/17 17:07:44 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main ( void )
{
	Fixed fixed;
	fixed.setRawBits(9);
	std::cout << "1: " << fixed.getRawBits() << std::endl;
	Fixed fixed_cpy(fixed);
	std::cout << "2: " << fixed_cpy.getRawBits() << std::endl;
	Fixed fixed_ass;
	fixed_ass = fixed_cpy;	
	std::cout << fixed_ass.getRawBits() << std::endl;
	Fixed fixed_ass_ch;
	fixed_ass_ch = fixed_cpy = fixed;
	std::cout << fixed_ass_ch.getRawBits() << std::endl;
	return (0);
}