/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:56:27 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 19:23:28 by seblin           ###   ########.fr       */
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
: AForm("Zaphod Beeblebrox", 25, 5), _target(target)
{	
	return ;
}

PresidentialPardonForm::PresidentialPardonForm
	( const PresidentialPardonForm & src ) : AForm(src), _target(src._target)
{
	*this = src;
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=
	( const PresidentialPardonForm & rhs )
{
	AForm::operator=(rhs);

	return (*this);
}

void PresidentialPardonForm::action( void ) const
{
	std::cout << "\e[1m " << this->_target <<
		" has been pardoned by Zaphod Beeblebrox.\e[0m" << std::endl
		<< std::endl;
	
	return ;
}