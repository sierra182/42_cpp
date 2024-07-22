/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:16:51 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 13:44:01 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog ( void )
{
    this->type = "dog";
    return ;
}

Dog::~Dog( void )
{
    return ;
}

Dog::Dog ( const Dog & src )
{
    *this = src;
    return ;
}

Dog & Dog::operator=( const Dog & rhs )
{
    if (this->type != rhs.type)
        this->type = rhs.type;
    return (*this);   
}

void   Dog::makeSound( void ) const
 {
    std::cout << "woaf" << std::endl;    
 }