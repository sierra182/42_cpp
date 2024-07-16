/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:02:18 by seblin            #+#    #+#             */
/*   Updated: 2024/07/16 11:45:19 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB( std::string name )
	:  _name(name)
{	
	return ;	
}

void	HumanB::attack( void ) const
{
	std::cout << this->_name << " attacks with their "
		<< (*this->_weapon).getType() << std::endl;
}

void	HumanB::setWeapon( Weapon const & weapon )
{
	this->_weapon = &weapon;
}