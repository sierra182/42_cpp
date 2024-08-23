/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:33:50 by seblin            #+#    #+#             */
/*   Updated: 2024/08/23 14:16:33 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

const std::string Intern::mapping[FRM] = {"presidential pardon",
	"robotomy request",	"shrubbery creation"};

Intern::Intern( void )
{	
	this->forms[0] = &Intern::makeTForm<PresidentialPardonForm>;
	this->forms[1] = &Intern::makeTForm<RobotomyRequestForm>;
	this->forms[2] = &Intern::makeTForm<ShrubberyCreationForm>;
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
	int i;
	
	for (i = 0; i < FRM && this->mapping[i] != name; i++)
		;
	if (i >= FRM)
		throw Intern::FormNoExist();
	std::cout << "Intern creates " << name << std::endl << std::endl;
	return ((this->*forms[i])(target));
}

const char * Intern::FormNoExist::what( void ) const throw()
{	
	return "\e[1;31m -The Form do not exist!- \n\e[0m";
}
