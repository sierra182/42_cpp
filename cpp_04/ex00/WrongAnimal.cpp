/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:04:27 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 14:27:19 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{    
    return ;
}

WrongAnimal::~WrongAnimal( void )
{
    return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
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
    std::cout << "i'm the wrong animal" << std::endl;    
 }