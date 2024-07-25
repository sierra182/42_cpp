/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:44:39 by seblin            #+#    #+#             */
/*   Updated: 2024/07/25 18:26:00 by seblin           ###   ########.fr       */
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
		
		Fixed &	operator++( void );
		Fixed 	operator++( int );
		Fixed &	operator--( void );
		Fixed 	operator--( int );
	
		bool	operator>( Fixed const & rhs ) const;
		bool	operator<( Fixed const & rhs ) const;
		bool	operator>=( Fixed const & rhs ) const;
		bool	operator<=( Fixed const & rhs ) const;		
		bool	operator==( Fixed const & rhs ) const;
		bool	operator!=( Fixed const & rhs ) const;
		
		Fixed 	operator+( Fixed const & rhs ) const;
		Fixed 	operator-( Fixed const & rhs ) const;
		Fixed	operator*( Fixed const & rhs ) const;
		Fixed 	operator/( Fixed const & rhs ) const;
		
		static Fixed const & max( const Fixed & a, const Fixed & b );
		static Fixed & max( Fixed & a, Fixed & b );
		static Fixed const & min( const Fixed & a, const Fixed & b );
		static Fixed & min( Fixed & a, Fixed & b );
	
	private:
	
		int					_value;
		static const int	_bit = 8;	
};

std::ostream & operator<<( std::ostream & os, Fixed const & rhs );