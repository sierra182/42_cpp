/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:00:29 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 10:38:29 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	return ;
}

DiamondTrap::DiamondTrap( const std::string & _name )
	: ClapTrap(_name + "_clap_name"), FragTrap(_name), ScavTrap(_name),
	name(_name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	
	this->whoAmI();
	return ;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src )
	: ClapTrap(src.name + "_clap_name"), FragTrap(src.name), ScavTrap(src.name)
{
	*this = src;
	return;
}

DiamondTrap & DiamondTrap::operator=( const DiamondTrap & rhs )
{
	if (rhs.attackDamage != this->attackDamage)
		this->attackDamage = rhs.attackDamage;
	if (rhs.hitPoint != this->hitPoint)
		this->hitPoint = rhs.hitPoint;
	if (rhs.energyPoint != this->energyPoint)
		this->energyPoint = rhs.energyPoint;
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return ;
}

void	DiamondTrap::whoAmI( void ) const
{
	std::cout << "whoAmi? DiamondTrap name: " << this->name
		<< " ClapTrap name: " << ClapTrap::name << std::endl;
}