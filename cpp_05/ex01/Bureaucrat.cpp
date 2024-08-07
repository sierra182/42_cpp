/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:34:27 by seblin            #+#    #+#             */
/*   Updated: 2024/08/08 14:41:37 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

Bureaucrat::Bureaucrat( void )
{	
	return ;
}
Bureaucrat::~Bureaucrat( void )
{
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException
	( const Bureaucrat & bur ) : _bur(bur)
{
	return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException
	( const Bureaucrat & bur ) : _bur(bur)
{
	return ;
}

void Bureaucrat::isGradeAccept( int grade ) const
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(*this);
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException(*this);
}

const char * Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	std::cerr << this->_bur;
	return " \e[1mException: Grade is too low!\e[0m";
}

const char * Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	std::cerr << this->_bur;
	return " \e[1mException: Grade is too hight!\e[0m";
}

Bureaucrat::Bureaucrat( std::string const name, int const grade ) :
	_name(name)
{
	this->_grade = grade;
	this->isGradeAccept(this->_grade);
	std::cout << *this << " Created with succes." << std::endl;
	
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name)
{
	*this = src;

	std::cout << *this << " Created with succes." << std::endl;
	return ;
}
Bureaucrat & Bureaucrat::operator=( const Bureaucrat & rhs )
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

int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}
	
void Bureaucrat::incrementGrade( void )
{
	std::cout << *this << " Try increment grade..." << std::endl;
	this->isGradeAccept(this->_grade - 1);
	this->_grade--;
	std::cout << *this << " Incremented." << std::endl;
}
void Bureaucrat::decrementGrade( void )
{
	std::cout << *this << " Try decrement grade..." << std::endl;
	this->isGradeAccept(this->_grade + 1);	
	this->_grade++;
	std::cout << *this << " Decremented." << std::endl;
}

std::ostream & operator<<( std::ostream & lhs, const Bureaucrat & rhs )
{
	lhs << ' ' << rhs.getName() << ", bureaucrat grade " << rhs.getGrade()
		<< '.';
	return (lhs);
}

void Bureaucrat::signForm( Form & form ) const
{	
	try {
		form.beSigned(*this);		
		std::cout << ' ' << this->_name << " signed " << form.getName()
			<< '.' << std::endl;	
	}
	catch (const std::exception & e)
	{
		std::cerr << ' ' << this->_name << " couldn’t sign " << form.getName()
		<< " because:" << e.what() << std::endl;
		throw;	
	}		
}