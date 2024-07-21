/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:34:49 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 08:23:15 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	return ;
}

ClapTrap::ClapTrap( const std::string & name ) : _name(name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	
	this->_hitPoint = 10;
	this->_energyPoint = 10;
	this->_attackDamage = 0;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( const ClapTrap & src ) :_name(src._name)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;

	*this = src;
	return ;
}
ClapTrap & ClapTrap::operator=( const ClapTrap & rhs )
{	
	if (this->_attackDamage != rhs._attackDamage)
		this->_attackDamage = rhs._attackDamage;
	if (this->_energyPoint != rhs._energyPoint)
		this->_energyPoint = rhs._energyPoint;
	if (this->_hitPoint != rhs._hitPoint)
		this->_hitPoint = rhs._hitPoint;
	return (*this);
}

void ClapTrap::attack( const std::string & target )
{
	std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< " causing " << this->_attackDamage << " points of damage!"
		<< std::endl;
	--this->_energyPoint;
	//! find the other and take him damage of attack damage...
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap " << this->_name << " takes damage"
		<< " causing " << amount << " points of damage!" << std::endl;
	this->_hitPoint -= amount;
}
void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap " << this->_name << " be repaired"
		<< " causing " << amount << " points of reparation!"
		<< std::endl;
	this->_hitPoint += amount;
	--this->_energyPoint;
}
