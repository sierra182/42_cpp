/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 07:58:36 by seblin            #+#    #+#             */
/*   Updated: 2024/07/17 10:22:37 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define ACT 5

class Harl 
{
	public:
		
		Harl( void );
		
		void	complain( std::string level ) const;
		
	private:
	
		void	debug( void ) const;
		void	info( void ) const;
		void	warning( void ) const;
		void	error( void ) const;
		void	badLevel( void ) const;
		
		void			( Harl::*action[ACT] ) ( void ) const ;
		std::string		mapping[ACT];
};