/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:19:34 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 11:49:22 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap(name)
{
	return ;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Destructor called" << std::endl;
	
	return ;
}

FragTrap::FragTrap( const std::string & _name ) : ClapTrap(_name)
{	
	std::cout << "FragTrap constructor called" << std::endl;
	
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	this->highFivesGuy();
	return ;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src.name)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	
	*this = src;
	this->highFivesGuy();
	return ;
}

FragTrap & FragTrap::operator=( const FragTrap & rhs )
{
	if (this->attackDamage != rhs.attackDamage)
		this->attackDamage = rhs.attackDamage;
	if (this->energyPoint != rhs.energyPoint)
		this->energyPoint = rhs.energyPoint;
	if (this->hitPoint != rhs.hitPoint)
		this->hitPoint = rhs.hitPoint;
	return (*this);
}

void FragTrap::highFivesGuy( void ) const
{
	std::cout << "FragTrap says Hey guys" << std::endl;
}