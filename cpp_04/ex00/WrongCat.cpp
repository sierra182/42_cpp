/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:11:54 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 14:03:51 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
    this->type = "wrongcat";
    return ;
}

WrongCat::~WrongCat( void )
{
    return ;
}

WrongCat::WrongCat( const WrongCat & src )
{
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
    std::cout << "miaow" << std::endl;    
 }