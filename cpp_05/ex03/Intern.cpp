/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:33:50 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 21:22:08 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern( void )
{
	return ;
}

Intern::~Intern( void )
{
	return ;
}

Intern::Intern( Intern const & src )
{
	*this = src;
	return ;
}

Intern & Intern::operator=( const Intern & rhs)
{
	(void) rhs;
	return (*this);
}

AForm * Intern::makeForm( const std::string name, const std::string target )
	const
{
	(void) target;
	if (true) //exist?		
	{
		std::cout << "Intern creates " << name << std::endl;
		return NULL;
	}	
	return NULL;//explicit error message
}
