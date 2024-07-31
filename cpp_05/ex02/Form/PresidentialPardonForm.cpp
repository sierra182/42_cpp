/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:56:27 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 12:42:36 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm( void )
{
	return ;
}
	
PresidentialPardonForm::~PresidentialPardonForm( void )
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target )
: AForm("Zaphod Beeblebrox", 25, 5)
{
	std::cout << "\e[1m " << target <<
		" has been pardoned by Zaphod Beeblebrox.\e[0m" << std::endl;
	
	return ;
}

PresidentialPardonForm::PresidentialPardonForm
	( const PresidentialPardonForm & src ) : Form(src)
{
	*this = src;
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=
	( const PresidentialPardonForm & rhs )
{
	Form::operator=(rhs);
	
	return (*this);
}