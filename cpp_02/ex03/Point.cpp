/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:32:18 by seblin            #+#    #+#             */
/*   Updated: 2024/07/19 16:57:37 by seblin           ###   ########.fr       */
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

Point::Point ( const Point & src ) : x(src.get_x()), y(src.get_y())
{
	*this = src;
}

Point::Point ( const float x, const float y ) : x(x), y(y) 
{
	return ;
}

Point::Point ( Fixed x, Fixed y ) : x(x), y(y) 
{
	return ;
}

Point & Point::operator=( const Point & rhs )
{
	(void) rhs;
	return (*this);
}

Point Point::operator-( const Point & rhs ) const
{	
	return (Point(this->x - rhs.x, this->y - rhs.y));
}

Fixed Point::operator*( const Point & rhs ) const
{	
	return (this->x * rhs.y - this->y * rhs.x);
}

const Fixed Point::get_x( void ) const
{
	return (this->x);
}

const Fixed Point::get_y( void ) const
{
	return (this->y);
}

std::ostream & operator<<(std::ostream & os, Point const & rhs)
{
	os << "x: " << rhs.get_x() << " y: " << rhs.get_y();
	return (os);
}
