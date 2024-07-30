/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:49:25 by seblin            #+#    #+#             */
/*   Updated: 2024/07/30 15:31:22 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
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
	
	std::cout << *this << " Created with succes." << std::endl;
	return ;
}

Form::Form( const Form & src) : _name(src._name),
	_gradeForSign(Form::isGradeAccept(src._gradeForSign)),
	_gradeForExec(Form::isGradeAccept(src._gradeForExec))
{
	*this = src;

	std::cout << *this << " Created with succes." << std::endl;
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
	lhs << rhs.getName() << ", grade for sign: " << rhs.getGradeForSign()
		<< ", grade for exec: " << rhs.getGradeForExec()  << ", is signed: "
		<< rhs.getIsSigned() << std::endl;
		
	return (lhs);
}

Form::GradeTooHighException::GradeTooHighException
	( const Form & form, const int grade ) : _form(form), _grade(grade)
{	
	return ;
}

Form::GradeTooLowException::GradeTooLowException
	( const Form & form, const int grade ) : _form(form), _grade(grade)
{
	return ;
}

const char * Form::GradeTooHighException::what( void ) const throw()
{	
	std::cout << " trying: (" << this->_grade << "): ";
	
	return " \e[1mException: Grade is too high!\e[0m";
}

const char * Form::GradeTooLowException::what( void ) const throw()
{	
	std::cout << " trying: (" << this->_grade << "):";
	
	return " \e[1mException: Grade is too low!\e[0m";
}

int Form::isGradeAccept( const int grade ) const
{	
	if (grade < 1)
	{		
		std::cout << this->_name << std::endl;
		throw Form::GradeTooHighException(*this, grade);
	}
	else if (grade > 150)
	{
		std::cout << this->_name << std::endl;
		throw Form::GradeTooLowException(*this, grade);
	}
	return (grade);
}

void Form::beSigned( const Bureaucrat & bur )
{
	if (bur.getGrade() <= this->getGradeForSign())
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException(*this, bur.getGrade());	
}