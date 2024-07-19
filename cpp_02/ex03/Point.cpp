/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:32:18 by seblin            #+#    #+#             */
/*   Updated: 2024/07/19 09:42:46 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point ( void ) : x(0), y(0)
{
	return ;
}

Point::~Point( void )
{
	return ;
}

Point::Point ( const Point & src ) : x(0), y(0)
{
	*this = src;
}

Point::Point ( const float x, const float y ) : x(x), y(y) 
{
	return ;
}

Point & Point::operator=( const Point & rhs )
{
	(void) rhs;
	return (*this);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	
}