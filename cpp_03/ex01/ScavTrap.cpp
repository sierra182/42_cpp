/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:19:34 by seblin            #+#    #+#             */
/*   Updated: 2024/07/20 15:15:41 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap("test")
{
	return ;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( const std::string & name ) : ClapTrap("test")
{
	(void) name;
	std::cout << "ScavTrap constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap("test")
{
	std::cout << "ScavTrap copy constructor called" << std::endl;

	*this = src;
	return ;
}

ScavTrap & ScavTrap::operator=( const ScavTrap & rhs )
{
	(void) rhs;
	//!to complete
	return (*this);
}

void	ScavTrap::attack( const std::string & target )
{
	(void) target;
	std::cout << "ScavTrap Attack!" << std::endl;
	// std::cout << "ScavTrap " << this->_name << " attacks " << target
	// 	<< " causing " << this->_attackDamage << " points of damage!"
	// 	<< std::endl;
	// --this->_energyPoint;
}