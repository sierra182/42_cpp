/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:00:15 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 16:26:16 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#undef CNS
#define CNS "\033[35m"

class DiamondTrap :  public ScavTrap, public FragTrap
{
	public:	

		DiamondTrap( const std::string & name );
		DiamondTrap( const DiamondTrap & src );
		DiamondTrap & operator=( const DiamondTrap & rhs );
		virtual ~DiamondTrap( void );
		
		using ScavTrap::attack;
		
	private:
	
		const std::string name;
		
		DiamondTrap( void );
		void whoAmI( void ) const;
};