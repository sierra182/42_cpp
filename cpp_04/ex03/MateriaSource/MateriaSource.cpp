/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:26:49 by svidot            #+#    #+#             */
/*   Updated: 2024/08/17 08:21:16 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource( void )
{
    // std::cout << CNS << " MateriaSource constructor called" << RST
        // << std::endl;
   
    for (int i = 0; i < INV; i++)
		this->inventory[i] = NULL;
    return ;
}

MateriaSource::~MateriaSource( void )
{
    // std::cout << CNS << " MateriaSource destructor called" << RST
        // << std::endl;
    
	for (int i = 0; i < INV; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
	}		
    return ;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
    // std::cout << CNS << " MateriaSource copy constructor called" << RST
        // << std::endl;       
    for (int i = 0; i < INV; i++)
		this->inventory[i] = NULL;  
    *this = src;
    return ;
}

MateriaSource & MateriaSource::operator=( const MateriaSource & rhs )
{
    // std::cout << CNS << " MateriaSource operator= called" << RST 
    //     << std::endl;
        
    for (int i = 0; i < INV; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
		if (rhs.inventory[i]) 	
			this->inventory[i] = rhs.inventory[i]->clone();			
	}  	  		
    return (*this);
}

void MateriaSource::learnMateria( AMateria* mat )
{
    for (int i = 0; i < INV; i++ )
   		if (!this->inventory[i])
		{
			this->inventory[i] = mat;
			return;
		}
	std::cout << " \e[5;31m" << "The inventory is full! \e[0m"
	<< std::endl << std::endl;  
}

AMateria*  MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < INV; i++ )
   		if (this->inventory[i] && this->inventory[i]->getType() == type)		
			return (this->inventory[i]->clone());
    std::cout << " \e[5;31m" << "The inventory don't contain \
this materia!\e[0m"	<< std::endl << std::endl;    			
    return (NULL);  
}

AMateria  * const * MateriaSource::getInventory( void ) const
{
    return this->inventory;
}