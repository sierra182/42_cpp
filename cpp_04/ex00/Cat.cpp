/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:54 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 15:27:26 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
    std::cout << CNS << "Cat constructor called" << RST << std::endl;
    
    this->type = "cat";
    return ;
}

Cat::~Cat( void )
{
    std::cout << CNS << "Cat desconstructor called" << RST << std::endl;
    
    return ;
}

Cat::Cat( const Cat & src )
{
    std::cout << CNS << "Cat copy constructor called" << RST << std::endl;
    
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