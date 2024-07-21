/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:00:29 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 16:47:34 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ): ClapTrap(name),  ScavTrap(name), FragTrap(name)	
{
	return ;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << CNS << "DiamondTrap destructor called" << RST << std::endl;
	return ;
}
DiamondTrap::DiamondTrap( const std::string & _name )
	: ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name), 
	name(_name)
{
	std::cout << CNS << "DiamondTrap constructor called" << RST << std::endl;
	
	this->initEnergyPoint();
	this->whoAmI();
	this->highFivesGuy();
	this->guardGate();
	return ;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src )
	: ClapTrap(src.name + "_clap_name"), ScavTrap(src.name), FragTrap(src.name),
	name(src.name)
{
	std::cout << CNS << "DiamondTrap copy constructor called" << RST << std::endl;
	
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

void	DiamondTrap::whoAmI( void ) const
{
	std::cout << "Special Diamond - whoAmi? - DiamondTrap name: " << this->name
		<< " | ClapTrap name: " << ClapTrap::name << ' ' << std::endl;
}