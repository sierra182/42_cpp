/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:19:34 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 13:00:41 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap(name)
{
	return ;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	
	return ;
}

ScavTrap::ScavTrap( const std::string & _name ) : ClapTrap(_name)
{	
	std::cout << "ScavTrap constructor called" << std::endl;
	
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	this->guardGate();
	this->initEnergyPoint(this->energyPoint);
	return ;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src.name)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	
	*this = src;
	this->guardGate();
	this->initEnergyPoint(this->energyPoint);
	return ;
}

ScavTrap & ScavTrap::operator=( const ScavTrap & rhs )
{
	if (this->attackDamage != rhs.attackDamage)
		this->attackDamage = rhs.attackDamage;
	if (this->energyPoint != rhs.energyPoint)
		this->energyPoint = rhs.energyPoint;
	if (this->hitPoint != rhs.hitPoint)
		this->hitPoint = rhs.hitPoint;
	return (*this);
}

void	ScavTrap::attack( const std::string & target )
{	
	std::cout << "ScavTrap Attack! " << this->name << " attacks " << target
		<< " causing " << this->attackDamage << " points of damage!"
		<< std::endl;
	--this->energyPoint;
}

void ScavTrap::guardGate( void ) const
{
	std::cout << "ScavTrap is in Gate keeper mode" << std::endl;
}

void ScavTrap::initEnergyPoint( int nrj )
{
	static int nrj_sav = nrj;
	if (!nrj_sav)
		nrj_sav = nrj;
	this->energyPoint = nrj_sav;
}