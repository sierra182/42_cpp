/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:00:15 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 10:36:10 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
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