/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:04:27 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 18:57:53 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{ 
    std::cout << std::endl << CNS << " WrongAnimal constructor called"
        << RST << std::endl; 
      
    return ;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << CNS << " WrongAnimal destructor called" << RST << std::endl
        << std::endl;
     
    return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
    std::cout << CNS << " WrongAnimal copy constructor called" << RST
        << std::endl;
    
    *this = src;
    return ;
}

WrongAnimal & WrongAnimal::operator=( const WrongAnimal & rhs )
{
    if (this->type != rhs.type)
        this->type = rhs.type;
    return (*this);
}

 std::string WrongAnimal::getType( void ) const
 {
    return (this->type);
 }

 void   WrongAnimal::makeSound( void ) const
 {
    std::cout << " I'm the wrong animal" << std::endl;    
 }