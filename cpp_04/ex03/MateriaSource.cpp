/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:26:49 by svidot            #+#    #+#             */
/*   Updated: 2024/07/25 18:05:57 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource( void )
{
    std::cout << CNS << " MateriaSource constructor called" << RST << std::endl;
   
    for (int i = 0; i < INV; i++)
		this->inventory[i] = NULL;
    return ;
}

MateriaSource::~MateriaSource( void )
{
    std::cout << CNS << " MateriaSource destructor called" << RST << std::endl;
    
    return ;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
    std::cout << CNS << " MateriaSource copy constructor called" << RST
        << std::endl;
        
    *this = src;
    return ;
}

MateriaSource & MateriaSource::operator=( const MateriaSource & rhs )
{
    std::cout << CNS << " MateriaSource operator= called" << RST << std::endl;
    (void) rhs;
    //! to complete
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
    //! to complete
}

AMateria*  MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < INV; i++ )
   		if (this->inventory[i]->getType() == type)		
			return (this->inventory[i]->clone());
			
    return (NULL);   
	//! to complete
}