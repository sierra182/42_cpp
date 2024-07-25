/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:52:57 by svidot            #+#    #+#             */
/*   Updated: 2024/07/25 15:14:00 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character( void )
{
    std::cout << CNS << " Character constructor called" << RST << std::endl;
    
    return ;
}

Character::~Character( void )
{
    std::cout << CNS << " Character destructor called" << RST << std::endl;
    
    return ;
}

Character::Character( const Character & src )
{
    std::cout << CNS << " Character copy constructor called" << RST
        << std::endl;
        
    *this = src;
    return ;
}

Character & Character::operator=( const Character & rhs )
{
    std::cout << CNS << " Character operator= called" << RST << std::endl;
    (void) rhs;
    //! to complete
    return (*this);
}

std::string const & Character::getName( void ) const
{    
    return (this->name);
}
    
void Character::equip(AMateria* m)
{
    (void) m;
    //! to complete
}

void Character::unequip(int idx)
{
    (void) idx;
    //! to complete
}

void Character::use(int idx, ICharacter& target)
{
	this->inventory[idx]->use(target);
    
    //! to complete
}