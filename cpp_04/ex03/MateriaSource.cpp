/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:26:49 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 17:50:29 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource( void )
{
    std::cout << CNS << " MateriaSource constructor called" << RST << std::endl;
    
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

void MateriaSource::learnMateria( AMateria* what )//?
{
    (void) what;
    //! to complete
}

AMateria* createMateria( std::string const & type )
{
    (void) type;
    return new Cure();   
}