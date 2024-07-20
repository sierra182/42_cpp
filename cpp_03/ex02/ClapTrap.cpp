/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:34:49 by seblin            #+#    #+#             */
/*   Updated: 2024/07/20 18:07:05 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	return ;
}

ClapTrap::ClapTrap( const std::string & name ) : name(name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src ) :name(src.name)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;

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
	//! find the other and take him damage of attack damage...
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
