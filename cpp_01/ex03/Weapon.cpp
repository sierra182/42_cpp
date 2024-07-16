/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:02:09 by seblin            #+#    #+#             */
/*   Updated: 2024/07/16 11:28:13 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon( void )
{
	return ;	
}

Weapon::Weapon(const std::string type )
{	
	this->setType(type);
}

void	Weapon::setType(const std::string type)
{
	this->type = type;
}

std::string const &	Weapon::getType( void ) const
{
	return (this->type);
}