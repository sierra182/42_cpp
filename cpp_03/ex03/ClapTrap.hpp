/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:34:55 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 17:00:31 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define CNS "\033[32m"
#define RST "\033[0m"

class ClapTrap
{
	public:

		ClapTrap( const std::string & name );
		virtual ~ClapTrap( void );
		
		ClapTrap ( const ClapTrap & src );
		ClapTrap & operator=( ClapTrap const & rhs );
		
		void	attack( const std::string & target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

		void	displayStatus( void ) const;
		
	protected:
	
		const std::string	name;
		int					hitPoint;
		int					energyPoint;
		int					attackDamage;
		
	private:
	
		ClapTrap( void );
		
};