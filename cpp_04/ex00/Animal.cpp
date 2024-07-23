/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:04:27 by svidot            #+#    #+#             */
/*   Updated: 2024/07/23 12:57:58 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{ 
    std::cout << std::endl << CNS << " Animal constructor called"
        << RST << std::endl;   
   
    return ;
}

Animal::~Animal( void )
{
    std::cout << CNS << " Animal destructor called" << RST << std::endl 
        << std::endl;
    return ;
}

Animal::Animal( const Animal & src )
{
    std::cout << CNS << " Animal copy constructor called" << RST << std::endl; 
     
    *this = src;
    return ;
}

Animal & Animal::operator=( const Animal & rhs )
{
    if (this->type != rhs.type)
        this->type = rhs.type;
    return (*this);
}

std::string Animal::getType( void ) const
{
	return (this->type);
}

void   Animal::makeSound( void ) const
{
	std::cout << " I'm an animal" << std::endl;    
}