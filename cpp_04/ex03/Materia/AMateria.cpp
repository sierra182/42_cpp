/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:58:31 by svidot            #+#    #+#             */
/*   Updated: 2024/07/28 10:45:00 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & _type) : type(_type)
{
    // std::cout << CNS << " AMateria param constructor called" << RST
    //     << std::endl;

    return ; 
}

AMateria::AMateria( void )
{
    // std::cout << CNS << " AMateria constructor called" << RST << std::endl;

    return ;
}

AMateria::~AMateria( void )
{
    // std::cout << CNS << " AMateria destructor called" << RST << std::endl;
		
    return ; 
}

AMateria::AMateria( const AMateria & src ) : type(src.type)
{
    // std::cout << CNS << " AMateria copy constructor called" << RST
    //     << std::endl;
  
   	*this = src;
    return ;
}

AMateria & AMateria::operator=( const AMateria & rhs )
{
    // std::cout << CNS << " AMateria operator= called" << RST << std::endl;
	
    return (*this);
    (void) rhs; 
}

std::string const & AMateria::getType() const
{
    return (this->type);
}