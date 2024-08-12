/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:02:18 by seblin            #+#    #+#             */
/*   Updated: 2024/08/12 15:52:15 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB( std::string name )
	:  _name(name), _weapon(NULL)
{	
	return ;	
}

void	HumanB::attack( void ) const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their "
		<< (*this->_weapon).getType() << std::endl;
}

void	HumanB::setWeapon( Weapon const & weapon )
{
	this->_weapon = &weapon;
}