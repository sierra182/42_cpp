/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:34:55 by seblin            #+#    #+#             */
/*   Updated: 2024/07/20 08:29:03 by seblin           ###   ########.fr       */
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

	private:
	
		ClapTrap( void );
	
		const std::string	_name;
		int					_hitPoint;
		int					_energyPoint;
		int					_attackDamage;
};