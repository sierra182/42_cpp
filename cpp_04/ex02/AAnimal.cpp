/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:04:27 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 09:37:25 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void )
{ 
    std::cout << std::endl << CNS << " AAnimal constructor called"
        << RST << std::endl;   
   
    return ;
}

AAnimal::~AAnimal( void )
{
    std::cout << CNS << " AAnimal destructor called" << RST << std::endl 
        << std::endl;
    return ;
}

AAnimal::AAnimal( const AAnimal & src )
{
    std::cout << CNS << " AAnimal copy constructor called" << RST << std::endl; 
     
    *this = src;
    return ;
}

AAnimal & AAnimal::operator=( const AAnimal & rhs )
{
    if (this->type != rhs.type)
        this->type = rhs.type;
    return (*this);
}

std::string AAnimal::getType( void ) const
{
	return (this->type);
}

void AAnimal::setType( std::string _type ) 
{
	this->type = _type;
}

void   AAnimal::makeSound( void ) const
{
	std::cout << " I'm an animal" << std::endl;    
}