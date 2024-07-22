/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:34:49 by seblin            #+#    #+#             */
/*   Updated: 2024/07/22 11:02:08 by svidot           ###   ########.fr       */
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
	this->displayStatus();
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
	this->displayStatus();
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
	if (this->energyPoint <= 0 || this->hitPoint <= 0)
	{		
		std::cout << "\033[32m" << "no more possible..." << RST
			<< std::endl; 
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target
		<< " causing " << this->attackDamage << " points of damage!"
		<< std::endl;
	--this->energyPoint;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->hitPoint <= 0)
	{		
		std::cout << "\033[32m" << "i'm already dead..." << RST
			<< std::endl; 
		return;
	}
	std::cout << "ClapTrap " << this->name << " takes damage"
		<< " causing " << amount << " points of damage!" << std::endl;
	this->hitPoint -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->energyPoint <= 0 || this->hitPoint <= 0)
	{		
		std::cout << "\033[32m" << "no more possible..." << RST
			<< std::endl; 
		return;
	}
	std::cout << "ClapTrap " << this->name << " be repaired"
		<< " causing " << amount << " points of reparation!"
		<< std::endl;
	this->hitPoint += amount;
	--this->energyPoint;
}

void ClapTrap::displayStatus( void ) const
{
	std::cout << "   ***** "
		<< this->name << " > hit: " << this->hitPoint 
		<< " | nrj: " << this->energyPoint
		<< " | damage: " << this->attackDamage
		<< " *****" << std::endl << std::endl;
}