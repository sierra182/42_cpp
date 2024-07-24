/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:58:31 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 14:00:37 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria( void )
{
    std::cout << CNS << " AMateria constructor called" << RST << std::endl;

    return ;
}

AMateria::~AMateria( void )
{
    std::cout << CNS << " AMateria destructor called" << RST << std::endl;

    return ; 
}

AMateria::AMateria( const AMateria & src )
{
    std::cout << CNS << " AMateria copy constructor called" << RST << std::endl;
    
    *this = src;
    return ;
}

AMateria & AMateria::operator=( const AMateria & rhs )
{
    std::cout << CNS << " AMateria operator= called" << RST << std::endl;
    return (*this); //! to complete
    (void) rhs; 
}