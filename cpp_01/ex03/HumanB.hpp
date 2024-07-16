/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:02:15 by seblin            #+#    #+#             */
/*   Updated: 2024/07/16 11:45:37 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB( std::string name );
		
		void	attack( void ) const;
		void	setWeapon( Weapon const & weapon);
		
	private:
		const std::string	_name;
		const Weapon*		_weapon;	
};