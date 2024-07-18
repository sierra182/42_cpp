/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:44:39 by seblin            #+#    #+#             */
/*   Updated: 2024/07/18 21:40:41 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public:
	
		Fixed( void );
		virtual ~Fixed( void );
		
		Fixed( Fixed const & src );
		Fixed& operator=( Fixed const & rhs );
				
		int		getRawBits ( void ) const;
		void	setRawBits ( int const raw );
		
	private:
	
		int					_value;
		static const int	_bit = 8;		
		
};