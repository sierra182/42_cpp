/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:32:07 by seblin            #+#    #+#             */
/*   Updated: 2024/07/19 17:10:47 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool are_same_sign(Fixed a, Fixed b, Fixed c)
{
	return ((a < Fixed(0) && b < Fixed(0) && c < Fixed(0))
		|| (a > Fixed(0) && b > Fixed(0) && c > Fixed(0)) ?
		true : false);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{	
	Point AB_vect = b - a;
	Point AP_vect = point - a;
	Fixed A_cross_p = AB_vect * AP_vect;

	Point BC_vect = c - b;
	Point BP_vect = point - b;
	Fixed B_cross_p = BC_vect * BP_vect;
	
	Point CA_vect = a - c;
	Point CP_vect = point - c;
	Fixed C_cross_p = CA_vect * CP_vect;
	
	return (are_same_sign(A_cross_p, B_cross_p, C_cross_p));	
}
