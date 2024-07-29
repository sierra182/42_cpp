/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:49:25 by seblin            #+#    #+#             */
/*   Updated: 2024/07/29 17:18:14 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("_name"),  _gradeForSign(0), _gradeForExec(0)
{
	return ;
}

Form::~Form( void )
{
	return ;
}

Form::Form( const Form & src) : _name(src._name),
	_gradeForSign(src._gradeForSign), _gradeForExec(src._gradeForExec)
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