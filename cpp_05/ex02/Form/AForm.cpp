/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:49:25 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 14:10:07 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm( void ) : _gradeForSign(0), _gradeForExec(0)
{
	this->_isSigned = false;
	
	return ;
}

AForm::~AForm( void )
{
	return ;
}

AForm::AForm( const std::string name, const int gradeForSign,
	const int gradeForExec ) :
	_name(name),
	_gradeForSign(AForm::isGradeAccept(gradeForSign)),
	_gradeForExec(AForm::isGradeAccept(gradeForExec))
{
	this->_isSigned = false;
	
	std::cout << *this << " Created with succes." << std::endl;
	return ;
}

AForm::AForm( const AForm & src) : _name(src._name),
	_gradeForSign(AForm::isGradeAccept(src._gradeForSign)),
	_gradeForExec(AForm::isGradeAccept(src._gradeForExec))
{
	*this = src;

	std::cout << *this << " Created with succes." << std::endl;
	return ;
}

AForm & AForm::operator=( const AForm & rhs )
{
	if (this != &rhs)
		if (this->_isSigned != rhs._isSigned)
			this->_isSigned = rhs._isSigned;
	return (*this);
}

const std::string &	AForm::getName( void ) const
{
	return (this->_name);
}

bool AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int	AForm::getGradeForSign( void ) const
{
	return (this->_gradeForSign);
}

int AForm::getGradeForExec( void ) const
{
	return (this->_gradeForExec);
}

std::ostream & operator<<( std::ostream & lhs, const AForm & rhs )
{
	lhs << rhs.getName() << ", grade for sign: " << rhs.getGradeForSign()
		<< ", grade for exec: " << rhs.getGradeForExec()  << ", is signed: "
		<< rhs.getIsSigned() << std::endl;
		
	return (lhs);
}

AForm::GradeTooHighException::GradeTooHighException
	( const AForm & form, const int grade ) : _form(form), _grade(grade)
{	
	return ;
}

AForm::GradeTooLowException::GradeTooLowException
	( const AForm & form, const int grade ) : _form(form), _grade(grade)
{
	return ;
}

const char * AForm::GradeTooHighException::what( void ) const throw()
{	
	std::cout << " trying: (" << this->_grade << "): ";
	
	return " \e[1mException: Grade is too high!\e[0m";
}

const char * AForm::GradeTooLowException::what( void ) const throw()
{	
	std::cout << " trying: (" << this->_grade << "):";
	
	return " \e[1mException: Grade is too low!\e[0m";
}

int AForm::isGradeAccept( const int grade ) const
{	
	if (grade < 1)
	{		
		std::cout << this->_name << std::endl;
		throw AForm::GradeTooHighException(*this, grade);
	}
	else if (grade > 150)
	{
		std::cout << this->_name << std::endl;
		throw AForm::GradeTooLowException(*this, grade);
	}
	return (grade);
}

void AForm::beSigned( const Bureaucrat & bur )
{
	if (bur.getGrade() <= this->getGradeForSign())
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException(*this, bur.getGrade());	
}

void AForm::execute( Bureaucrat const & executor ) const
{
	if (!this->_isSigned)
		;//throw
	else if (executor.getGrade() > this->getGradeForExec())
		;//throw
	action();	
}
