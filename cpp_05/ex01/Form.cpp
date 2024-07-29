/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:49:25 by seblin            #+#    #+#             */
/*   Updated: 2024/07/29 20:06:28 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form( void ) : _name("_name"),  _gradeForSign(0), _gradeForExec(0)
{
	this->_isSigned = false;
	
	return ;
}

Form::~Form( void )
{
	return ;
}
Form::Form( const std::string name, const int gradeForSign, const int gradeForExec )
	: _name(name), _gradeForSign(Form::isGradeAccept(gradeForSign)),
	_gradeForExec(Form::isGradeAccept(gradeForExec))
{
	this->_isSigned = false;
	
	return ;
}

Form::Form( const Form & src) : _name(src._name),
	_gradeForSign(Form::isGradeAccept(src._gradeForSign)),
	_gradeForExec(Form::isGradeAccept(src._gradeForExec))
{
	*this = src;
	return ;
}

Form & Form::operator=( const Form & rhs )
{
	if (this != &rhs)
		if (this->_isSigned != rhs._isSigned)
			this->_isSigned = rhs._isSigned;
	return (*this);
}

const std::string &	Form::getName( void ) const
{
	return (this->_name);
}

bool				Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int					Form::getGradeForSign( void ) const
{
	return (this->_gradeForSign);
}

int 	 			Form::getGradeForExec( void ) const
{
	return (this->_gradeForExec);
}

std::ostream & operator<<( std::ostream & lhs, const Form & rhs )
{
	lhs << rhs.getName() << rhs.getGradeForSign() << rhs.getGradeForExec() << rhs.getIsSigned() << std::endl;
	return (lhs);
}

Form::GradeTooHighException::GradeTooHighException( const Form & form )
	: _form(form)
{	
	return ;
}

Form::GradeTooLowException::GradeTooLowException( const Form & form )
	: _form(form)
{
	return ;
}

const char * Form::GradeTooHighException::what( void ) const throw()
{
	std::cout << this->_form;
	
	return " \e[1mException: Grade is too high!\e[0m";
}

const char * Form::GradeTooLowException::what( void ) const throw()
{
	std::cout << this->_form;
	
	return " \e[1mException: Grade is too low!\e[0m";
}

int Form::isGradeAccept( int grade ) const
{
	if (grade < 1)
		throw Form::GradeTooHighException(*this);
	else if (grade > 150)
		throw Form::GradeTooLowException(*this);
	return (grade);
}

void Form::beSigned( const Bureaucrat & bur )
{
	if (bur.getGrade() <= this->getGradeForSign())
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException(*this);	
}