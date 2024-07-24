/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:20:15 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 16:04:01 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>
#include "AMateria.hpp"

AMateria * Cure::clone( void ) const
{
    
    return new Cure(); //?
}

Cure::Cure(std::string const & _type) : AMateria(_type)
{  
    std::cout << CNS << " Cure param constructor called" << RST
        << std::endl;
        
    return ;
}

Cure::Cure( void )
{
    std::cout << CNS << " Cure constructor called" << RST << std::endl;

    return ;
}

Cure::~Cure( void )
{
    std::cout << CNS << " Cure destructor called" << RST << std::endl;

    return ; 
}

Cure::Cure( const Cure & src ) : AMateria(src)
{
    std::cout << CNS << " Cure copy constructor called" << RST << std::endl;
    
    *this = src;
    return ;
}

Cure & Cure::operator=( const Cure & rhs )
{
    std::cout << CNS << " Cure operator= called" << RST << std::endl;
    return (*this);
    (void) rhs;     
    //! to complete
}