/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:08:32 by seblin            #+#    #+#             */
/*   Updated: 2024/07/23 23:45:37 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain( void )
{
	std::cout << std::endl << CNS << " Brain constructor called"
        << RST << std::endl;

	return ;
}

Brain::~Brain( void )
{
	std::cout << CNS << " Brain destructor called" << RST << std::endl 
        << std::endl;
		
    return ;
}

Brain::Brain( const Brain & src )
{
	std::cout << CNS << " Brain copy contructor called" << RST << std::endl 
        << std::endl;
			
	*this = src;		
	return ;
}

Brain & Brain::operator=( const Brain & rhs )
{
	std::cout << CNS << " VOILA****************" << RST << std::endl ;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}