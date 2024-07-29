/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:49:22 by seblin            #+#    #+#             */
/*   Updated: 2024/07/29 20:21:31 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>
// #include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{	
	Form( void );
	int isGradeAccept( int grade ) const;
	void beSigned( const Bureaucrat & bur );
	
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeForSign;
	const int			_gradeForExec;

	public:
		
		Form( const std::string name, const int gradeForSign,
			const int gradeForExec );
		virtual ~Form( void );
		Form( const Form & src);
		Form & operator=( const Form & rhs );

		const std::string &	getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getGradeForSign( void ) const;
		int 	 			getGradeForExec( void ) const;
		
		class GradeTooHighException	: public std::exception
		{
			const Form & _form;
			public :
			
			GradeTooHighException( const Form & form );
			virtual const char * what( void ) const throw();
		};
		
		class GradeTooLowException	: public std::exception
		{
			const Form & _form;
			public:
			
			GradeTooLowException( const Form & form );
			virtual const char * what( void ) const throw();
		};
};

std::ostream & operator<<( std::ostream & lhs, const Form & rhs ); 