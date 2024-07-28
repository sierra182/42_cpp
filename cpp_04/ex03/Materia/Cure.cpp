/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:20:15 by svidot            #+#    #+#             */
/*   Updated: 2024/07/28 11:59:33 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

void Cure::use(ICharacter& target) const
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria * Cure::clone( void ) const
{   
	// std::cout << " Cure clone called" << std::endl;

    return (new Cure(*this));
}

Cure::Cure(std::string const & _type) : AMateria(_type)
{  
    // std::cout << CNS << " Cure param constructor called" << RST
        // << std::endl;
       
    return ;
}

Cure::Cure( void ) : AMateria("cure")
{
    // std::cout << CNS << " Cure constructor called" << RST << std::endl;
	
    return ;
}

Cure::~Cure( void )
{
    // std::cout << CNS << " Cure destructor called" << RST << std::endl;

    return ; 
}

Cure::Cure( const Cure & src ) : AMateria(src)
{
    // std::cout << CNS << " Cure copy constructor called" << RST << std::endl;
    
    *this = src;
    return ;
}

Cure & Cure::operator=( const Cure & rhs )
{
    // std::cout << CNS << " Cure operator= called" << RST << std::endl;
    
	return (*this);
	(void) rhs;
}