/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:19:42 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 18:30:00 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#pragma once

#undef CNS
#define CNS "\033[36m"

class ScavTrap : public ClapTrap
{
	public:
		
		ScavTrap( const std::string & name );
		virtual ~ScavTrap( void );
		ScavTrap( const ScavTrap & src );
		ScavTrap & operator=( const ScavTrap & rhs);
		
		void	attack( const std::string & target );
		void	guardGate( void ) const;	
		
	private:
		
		ScavTrap( void );
};