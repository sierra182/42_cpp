/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:19:42 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 12:58:59 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#pragma once

class ScavTrap : virtual public ClapTrap
{
	public:
		
		ScavTrap( const std::string & name );
		virtual ~ScavTrap( void );
		ScavTrap( const ScavTrap & src );
		ScavTrap & operator=( const ScavTrap & rhs);
		
		void	attack( const std::string & target );
	
	protected:

		void initEnergyPoint( int nrj = -1 );
		
	private:
		
		ScavTrap( void );
		void guardGate( void ) const;	
};