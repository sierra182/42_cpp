/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:16:51 by svidot            #+#    #+#             */
/*   Updated: 2024/07/23 23:48:10 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog ( void ) : brain(new Brain())
{
    std::cout << CNS << " Dog constructor called" << RST << std::endl;
    
    this->type = "dog";
	this->brain->ideas[0] = "i could detroy the canapy";
	this->brain->ideas[1] = "i could detroy the guarden";
	this->brain->ideas[2] = "i could detroy the shoes";
    return ;
}

Dog::~Dog( void )
{
    std::cout << CNS << " Dog destructor called" << RST << std::endl;
	
    delete (this->brain);
    return ;
}

Dog::Dog ( const Dog & src ) : Animal(src), brain(new Brain())
{
    std::cout << CNS << " Dog copy constructor called" << RST << std::endl;
    
    *this = src;
    return ;
}

Dog & Dog::operator=( const Dog & rhs )
{
	Animal::operator=( rhs );  
	 	std::cout << CNS << " DOG VOILU" << RST << std::endl ;
	if (this->brain != rhs.brain)
		*this->brain = *rhs.brain;
    return (*this);   
}

void   Dog::makeSound( void ) const
{
    std::cout << " woaf" << std::endl;    
}

Brain & Dog::getBrain( void ) const
{
	return (*this->brain);
}