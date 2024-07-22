/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:04:27 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 13:09:51 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
    return ;
}

Animal::~Animal( void )
{
    return ;
}

Animal::Animal( const Animal & src )
{
    *this = src;
    return ;
}

Animal & Animal::operator=( const Animal & rhs )
{
    if (this->type != rhs.type)
        this->type = rhs.type;
    return (*this);
}