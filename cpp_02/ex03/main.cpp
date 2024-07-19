/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:30:00 by seblin            #+#    #+#             */
/*   Updated: 2024/07/19 22:47:29 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include <ostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point );

void	fire( Point const a, Point const b, Point const c, Point const point )
{	
	std::cout << "point= " << point << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "\033[32m 👌 You are in the triangle mg !\033[0m"
			<< std::endl << std::endl;
	else
		std::cout << "\033[33m ✍️ try again !\033[0m"
			<< std::endl << std::endl;
}

int main( void )
{
	Point a(2, 1);
	Point b(6, 4);
	Point c(8, 1);
	
	std::cout << "a= " << a << std::endl;
	std::cout << "b= " << b << std::endl;
	std::cout << "c= " << c << std::endl
		<< std::endl;
		
	{		
		Point point(5, 2.5);
		fire(a, b, c, point);
	}
	{
		Point point(7, 2);
		fire(a, b, c, point);
	}
	{
		Point point(7, 0);
		fire(a, b, c, point);
	}
	{
		Point point(7, 1);
		fire(a, b, c, point);
	}
	{
		Point point(7, 1.01);
		fire(a, b, c, point);
	}
	{
		Point point(3, 3);
		fire(a, b, c, point);
	}
	{
		Point point(-3, -3);
		fire(a, b, c, point);
	}
	{
		Point point(2, 1);
		fire(a, b, c, point);
	}
	{
		Point point(2.1, 1.01);
		fire(a, b, c, point);
	}
	return 0;
}