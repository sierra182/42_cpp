/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:19:34 by seblin            #+#    #+#             */
/*   Updated: 2024/07/22 11:15:25 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("name")
{
	return ;
}

FragTrap::~FragTrap( void )
{
	std::cout << CNS << "FragTrap destructor called" << RST << std::endl;
	
	return ;
}

FragTrap::FragTrap( const std::string & _name ) : ClapTrap(_name)
{	
	std::cout << CNS << "FragTrap constructor called" << RST << std::endl;
	
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	this->displayStatus();
	return ;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src.name)
{
	std::cout << CNS << "FragTrap copy constructor called" << RST << std::endl;
	
	*this = src;
	this->displayStatus();
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
	std::cout << "Special FragTrap - hi5 - " << this->name << " says Hey guys" << std::endl;
}