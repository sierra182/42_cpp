/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:54 by svidot            #+#    #+#             */
/*   Updated: 2024/07/23 23:12:42 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : brain(new Brain())
{
    std::cout << CNS << " Cat constructor called" << RST << std::endl;
    
    this->type = "cat";
	this->brain->ideas[0] = "i could do nothing";
	this->brain->ideas[1] = "i could make a nap";
	this->brain->ideas[2] = "i could kill a bird";
    return ;
}

Cat::~Cat( void )
{
    std::cout << CNS << " Cat destructor called" << RST << std::endl;
    
	delete (this->brain);
    return ;
}

Cat::Cat( const Cat & src ) : Animal(src), brain(new Brain())
{
    std::cout << CNS << " Cat copy constructor called" << RST << std::endl;
    
    *this = src;
    return ;
}

Cat & Cat::operator=( const Cat & rhs )
{
    Animal::operator=( rhs );  
	 
	if (this->brain != rhs.brain)
		this->brain = rhs.brain;
    return (*this);
}

void   Cat::makeSound( void ) const
{
	std::cout << " miaow" << std::endl;    
}

Brain & Cat::getBrain( void ) const
{
	return (*this->brain);
}