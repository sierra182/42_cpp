/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:52:57 by svidot            #+#    #+#             */
/*   Updated: 2024/07/28 10:56:39 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character( const std::string & _name ) : name(_name)
{
	// std::cout << CNS << " Character param constructor called" << RST
		// << std::endl;

	for (int i = 0; i < INV; i++)
		this->inventory[i] = NULL;
	return ;
}

Character::Character( void ) 
{
    // std::cout << CNS << " Character constructor called" << RST << std::endl;
	
    for (int i = 0; i < INV; i++)
		this->inventory[i] = NULL;
    return ;
}

Character::~Character( void )
{
    // std::cout << CNS << " Character destructor called" << RST << std::endl;
    
	for (int i = 0; i < INV; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
	}		
    return ;
}

Character::Character( const Character & src )
{
    // std::cout << CNS << " Character copy constructor called" << RST
        // << std::endl;
		
    for (int i = 0; i < INV; i++)
		this->inventory[i] = NULL;   
    *this = src;
    return ;
}

Character & Character::operator=( const Character & rhs )
{
    // std::cout << CNS << " Character operator= called" << RST << std::endl;
  
	if (this != &rhs)
	{		
		if (this->name != rhs.name)
			this->name = rhs.name;		
		for (int i = 0; i < INV; i++)				
		{				 
			delete this->inventory[i];
			this->inventory[i] = rhs.inventory[i]->clone();
		}
	}
    return (*this);
}

std::string const & Character::getName( void ) const
{    
    return (this->name);
}
    
void Character::equip( AMateria * m )
{
	for (int i = 0; i < INV; i++ )
   		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break;
		}
}

void Character::unequip( int idx )
{
   	if (idx < INV && this->inventory[idx])
		this->inventory[idx] = NULL;
}

void Character::use( int idx, ICharacter& target )
{
	if (idx < INV && this->inventory[idx])
		this->inventory[idx]->use(target);
}