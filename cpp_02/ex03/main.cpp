/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:30:00 by seblin            #+#    #+#             */
/*   Updated: 2024/07/19 16:56:45 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include <ostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int main( void )
{
	Point A(9, 1);
	Point B(2, 3);
	Point C(4, 6);
	Point point(7, 2);	
	
	if (bsp(A, B, C, point))
		std::cout << "You are in the triangle mg !" << std::endl;
	else
		std::cout << "try again !" << std::endl;
	return 0;
}