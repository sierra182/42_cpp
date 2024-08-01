/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:33:50 by seblin            #+#    #+#             */
/*   Updated: 2024/08/01 11:17:12 by seblin           ###   ########.fr       */
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
	this->forms[0] = &Intern::makePresidentialForm;
	this->forms[1] = &Intern::makeRobotomyForm;
	this->forms[2] = &Intern::makeShubberyForm;
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

AForm * Intern::makePresidentialForm( const std::string & target ) const
{
	return (new PresidentialPardonForm(target));
}

AForm * Intern::makeRobotomyForm( const std::string & target ) const
{
	return (new RobotomyRequestForm(target));
}

AForm * Intern::makeShubberyForm( const std::string & target ) const
{
	return (new ShrubberyCreationForm(target));
}

const char * Intern::FormNoExist::what( void ) const throw()
{	
	return "\e[1;31m -The Form do not exist!- \n\e[0m";
}