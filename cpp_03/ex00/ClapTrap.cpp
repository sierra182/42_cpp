/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:34:49 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 18:50:28 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	return ;
}

ClapTrap::ClapTrap( const std::string & name ) : _name(name)
{
	std::cout << CNS << "ClapTrap constructor called" << RST << std::endl;
	
	this->_hitPoint = 10;
	this->_energyPoint = 10;
	this->_attackDamage = 0;
	this->displayStatus();
}

ClapTrap::~ClapTrap( void )
{
	std::cout << CNS << "ClapTrap destructor called" << RST << std::endl
		<< std::endl;
		
	return ;
}

ClapTrap::ClapTrap( const ClapTrap & src ) :_name(src._name)
{
	std::cout << CNS << "ClapTrap copy constructor called" << RST << std::endl;

	*this = src;
	this->displayStatus();
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

void ClapTrap::displayStatus( void ) const
{
	std::cout << "   ***** "
		<< this->_name << " > hit: " << this->_hitPoint 
		<< " | nrj: " << this->_energyPoint
		<< " | damage: " << this->_attackDamage
		<< " *****" << std::endl << std::endl;
}