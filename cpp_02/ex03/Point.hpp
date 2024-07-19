/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:32:23 by seblin            #+#    #+#             */
/*   Updated: 2024/07/19 09:39:11 by seblin           ###   ########.fr       */
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
		virtual ~Point( void );

		Point & operator=( const Point & rhs );
		
	private:
	
		const Fixed x;
		const Fixed y;
		
};