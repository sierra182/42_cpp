/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:56:13 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 20:18:57 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <unistd.h>

bool RobotomyRequestForm::_robotog = false;

RobotomyRequestForm::RobotomyRequestForm( void )
{
	return ;
}
	
RobotomyRequestForm::~RobotomyRequestForm( void )
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target )
: AForm("Robotomy", 72, 45), _target(target)
{			
	return ;
}

RobotomyRequestForm::RobotomyRequestForm
	( const RobotomyRequestForm & src ) : AForm(src), _target(src._target)
{
	*this = src;
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=
	( const RobotomyRequestForm & rhs )
{
	AForm::operator=(rhs);
	
	return (*this);
}

void RobotomyRequestForm::action( void ) const
{
	usleep(500000);
	
	std::cout << "\a\e[1m" << "***drillingggg!***" << std::endl;	
	if (!this->_robotog)	
		std::cout << ' ' << this->_target <<
			" has been robotomized successfully!\e[0m" << std::endl
			<< std::endl;	
	else	
		std::cout << ' ' << this->_target <<
			" the robotomy failed!\e[0m" << std::endl << std::endl;
	this->_robotog = !this->_robotog;	
	usleep(500000);
	return ;
}

