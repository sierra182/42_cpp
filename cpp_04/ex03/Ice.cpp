/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:23:11 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 14:03:35 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>
// #include "AMateria.hpp"

// AMateria * Ice::clone( void ) const
// {
//     return new AMateria(); 
// }

Ice::Ice( void )
{
    std::cout << CNS << " Ice constructor called" << RST << std::endl;

    return ;
}

Ice::~Ice( void )
{
    std::cout << CNS << " Ice destructor called" << RST << std::endl;

    return ; 
}

Ice::Ice( const Ice & src ) : AMateria(src)
{
    std::cout << CNS << " Ice copy constructor called" << RST << std::endl;
    
    *this = src;
    return ;
}

Ice & Ice::operator=( const Ice & rhs )
{
    std::cout << CNS << " Ice operator= called" << RST << std::endl;
    return (*this);
    (void) rhs;     
    //! to complete
}