/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:54 by svidot            #+#    #+#             */
/*   Updated: 2024/07/23 12:59:42 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
    std::cout << CNS << " WrongCat constructor called" << RST << std::endl;

    this->type = "wrongcat";
    return ;
}

WrongCat::~WrongCat( void )
{
    std::cout << CNS << " WrongCat destructor called" << RST << std::endl;

    return ;
}

WrongCat::WrongCat( const WrongCat & src ) : WrongAnimal(src)
{
    std::cout << CNS << " WrongCat copy constructor called" << RST
        << std::endl;

    *this = src;
    return ;
}

WrongCat & WrongCat::operator=( const WrongCat & rhs )
{
    if (this->type != rhs.type)
        this->type = rhs.type;    
    return (*this);
}

void   WrongCat::makeSound( void ) const
{
	std::cout << " miaow" << std::endl;    
}