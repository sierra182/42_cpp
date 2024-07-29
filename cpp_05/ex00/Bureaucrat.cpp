/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:34:27 by seblin            #+#    #+#             */
/*   Updated: 2024/07/29 11:53:12 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{
	throw Bureaucrat::GradeTooHighException();
	return ;
}
Bureaucrat::~Bureaucrat( void )
{
	return ;
}

void Bureaucrat::isGradeAccept( int grade ) const
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char * Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return "too low";
}

const char * Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return "too hight";
}

Bureaucrat::Bureaucrat( std::string const name, int const grade ) :
	_name(name)
{
	Bureaucrat::isGradeAccept(grade);
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
	Bureaucrat::isGradeAccept(this->_grade - 1);	
	this->_grade--;
}
void				Bureaucrat::decrementGrade( void )
{
	Bureaucrat::isGradeAccept(this->_grade + 1);	
	this->_grade++;
}