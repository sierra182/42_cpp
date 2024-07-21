/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:34:55 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 09:25:10 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

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

	protected:
	
		const std::string	name;
		int					hitPoint;
		int					energyPoint;
		int					attackDamage;
		
	private:
	
		ClapTrap( void );
		
};