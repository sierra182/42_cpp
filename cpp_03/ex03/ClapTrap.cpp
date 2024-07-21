/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:34:49 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 17:03:25 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	return ;
}

ClapTrap::ClapTrap( const std::string & _name ) : name(_name)
{
	std::cout << CNS << "ClapTrap constructor called" << RST << std::endl;
	
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << CNS << "ClapTrap destructor called" << RST << std::endl
		<< std::endl;
		
	return ;
}

ClapTrap::ClapTrap( const ClapTrap & src ) :name(src.name)
{
	std::cout << CNS << "ClapTrap copy constructor called" << RST << std::endl;

	*this = src;
	return ;
}
ClapTrap & ClapTrap::operator=( const ClapTrap & rhs )
{	
	if (this->attackDamage != rhs.attackDamage)
		this->attackDamage = rhs.attackDamage;
	if (this->energyPoint != rhs.energyPoint)
		this->energyPoint = rhs.energyPoint;
	if (this->hitPoint != rhs.hitPoint)
		this->hitPoint = rhs.hitPoint;
	return (*this);
}

void ClapTrap::attack( const std::string & target )
{
	std::cout << "ClapTrap " << this->name << " attacks " << target
		<< " causing " << this->attackDamage << " points of damage!"
		<< std::endl;
	--this->energyPoint;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap " << this->name << " takes damage"
		<< " causing " << amount << " points of damage!" << std::endl;
	this->hitPoint -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap " << this->name << " be repaired"
		<< " causing " << amount << " points of reparation!"
		<< std::endl;
	this->hitPoint += amount;
	--this->energyPoint;
}

void ClapTrap::displayStatus( void ) const
{
	std::cout << "\033[38m"
	<< this->name << " hit: " << this->hitPoint
	<< this->name << " nrj: " << this->energyPoint
	<< this->name << " damage: " << this->attackDamage
	<< RST << std::endl;
}