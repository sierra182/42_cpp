/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:32:23 by seblin            #+#    #+#             */
/*   Updated: 2024/07/19 16:56:59 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
	public:

		Point ( void );
		Point( const Point & src);
		Point( float const x, float const y );
		Point( Fixed x, Fixed y );	
		virtual ~Point( void );

		Point & operator=( const Point & rhs );
		Point operator-( const Point & rhs ) const;
		Fixed operator*( const Point & rhs ) const;
		
		const Fixed get_x( void ) const;
		const Fixed get_y( void ) const;
		
	private:
	
		const Fixed x;
		const Fixed y;		
};

std::ostream & operator<<(std::ostream & os, Point const & rhs);
