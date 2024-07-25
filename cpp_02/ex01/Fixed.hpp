/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:44:39 by seblin            #+#    #+#             */
/*   Updated: 2024/07/25 18:26:18 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>

class Fixed
{
	public:
	
		Fixed( void );
		virtual ~Fixed( void );
		
		Fixed( Fixed const & src );
		Fixed( int const nbr );
		Fixed( float const nbr );
		Fixed& operator=( Fixed const & rhs );
				
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
				
	private:
	
		int					_value;
		static const int	_bit = 8;		
};

std::ostream & operator<<( std::ostream & os, Fixed const & rhs );