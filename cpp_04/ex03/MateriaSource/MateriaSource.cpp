/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:26:49 by svidot            #+#    #+#             */
/*   Updated: 2024/08/16 16:16:30 by svidot           ###   ########.fr       */
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
    std::cout << CNS << " MateriaSource operator= called" << RST 
        << std::endl;
        
    for (int i = 0; i < INV; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
	} 
    for (int i = 0; i < INV; i++)  
		this->inventory[i] = rhs.inventory[i];   
    return (*this);
}

void MateriaSource::learnMateria( AMateria* mat )//?
{
    for (int i = 0; i < INV; i++ )
   		if (!this->inventory[i])
		{
			this->inventory[i] = mat;
			break;
		}   
}

AMateria*  MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < INV; i++ )
   		if (this->inventory[i] && this->inventory[i]->getType() == type)		
			return (this->inventory[i]->clone());
            			
    return (NULL);  
}