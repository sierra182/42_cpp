/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:16:51 by svidot            #+#    #+#             */
/*   Updated: 2024/07/23 17:15:22 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog ( void )
{
    std::cout << CNS << " Dog constructor called" << RST << std::endl;
    
    this->type = "dog";
    return ;
}

Dog::~Dog( void )
{
    std::cout << CNS << " Dog destructor called" << RST << std::endl;
    
    return ;
}

Dog::Dog ( const Dog & src ) : Animal(src)
{
    std::cout << CNS << " Dog copy constructor called" << RST << std::endl;
    
    *this = src;
    return ;
}

Dog & Dog::operator=( const Dog & rhs )
{
	 std::cout << CNS << " Dog operator= called" << RST << std::endl;
    if (this->type != rhs.type)
        this->type = rhs.type;
    return (*this);   
}

void   Dog::makeSound( void ) const
{
    std::cout << " woaf" << std::endl;    
}