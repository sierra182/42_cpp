/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:54 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 18:55:56 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
    std::cout << CNS << " Cat constructor called" << RST << std::endl;
    
    this->type = "cat";
    return ;
}

Cat::~Cat( void )
{
    std::cout << CNS << " Cat destructor called" << RST << std::endl;
    
    return ;
}

Cat::Cat( const Cat & src ) : Animal()
{
    std::cout << CNS << " Cat copy constructor called" << RST << std::endl;
    
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
    std::cout << " miaow" << std::endl;    
 }