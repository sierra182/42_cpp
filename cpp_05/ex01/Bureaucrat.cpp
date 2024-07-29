/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:34:27 by seblin            #+#    #+#             */
/*   Updated: 2024/07/29 20:18:19 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

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
	Bureaucrat::isGradeAccept(this->_grade);
	std::cout << *this << " Created with succes." << std::endl;
	
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
	std::cout << *this << " Try increment grade..." << std::endl;
	Bureaucrat::isGradeAccept(this->_grade - 1);
	this->_grade--;
	std::cout << *this << " Incremented." << std::endl;
}
void				Bureaucrat::decrementGrade( void )
{
	std::cout << *this << " Try decrement grade..." << std::endl;
	Bureaucrat::isGradeAccept(this->_grade + 1);	
	this->_grade++;
	std::cout << *this << " Decremented." << std::endl;
}

std::ostream & operator<<( std::ostream & lhs, const Bureaucrat & rhs )
{
	lhs << ' ' << rhs.getName() << ", bureaucrat grade " << rhs.getGrade()
		<< '.';
	return (lhs);
}

void Bureaucrat::signForm( const Form & form ) const
{
	if (form.getIsSigned())
		std::cout << ' ' << this->_name << " signed " << form.getName();
	else
		std::cout << ' ' << this->_name << " couldn’t sign " << form.getName()
		<< " because " << " ?reason? " << std::endl;
}