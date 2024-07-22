/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:54 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 13:43:34 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
    this->type = "cat";
    return ;
}

Cat::~Cat( void )
{
    return ;
}

Cat::Cat( const Cat & src )
{
    *this = src;
    return ;
}

Cat & Cat::operator=( const Cat & rhs )
{
    if (this->type != rhs.type)
        this->type = rhs.type;    
    return (*this);
}

void   Cat::makeSound( void ) const
 {
    std::cout << "miaow" << std::endl;    
 }