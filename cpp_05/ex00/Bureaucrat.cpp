/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:34:27 by seblin            #+#    #+#             */
/*   Updated: 2024/07/28 18:54:31 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{
	return ;
}
Bureaucrat::~Bureaucrat( void )
{
	return ;
}

Bureaucrat::Bureaucrat( std::string const name, int const grade ) :
	_name(name)
{
	if (isGradeAccept(grade))
		this->_grade = grade;
	
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name)
{
	*this = src;
	return ;
}
Bureaucrat & 		Bureaucrat::operator=( const Bureaucrat & rhs )
{
	if (this != &rhs)		
		if (this->_grade != rhs._grade)
			this->_grade = rhs._grade;
	return (*this);	
}

const std::string &	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int					Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}
	
void				Bureaucrat::incrementGrade( void )
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw;//!
}
void				Bureaucrat::decrementGrade( void )
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw;//!
}