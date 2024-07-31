/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:49:22 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 14:09:55 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>

class Bureaucrat;

class AForm
{	
	int isGradeAccept( int grade ) const;
	
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeForSign;
	const int			_gradeForExec;
	
	protected:
		AForm( void );
		
	public:
		
		AForm( const std::string name, const int gradeForSign,
			const int gradeForExec );
		virtual ~AForm( void );
		AForm( const AForm & src);
		AForm & operator=( const AForm & rhs );

		const std::string &	getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getGradeForSign( void ) const;
		int 	 			getGradeForExec( void ) const;
		
		void beSigned( const Bureaucrat & signator );
		void execute( Bureaucrat const & executor ) const;
		virtual void action( void ) const = 0;
		
		class GradeTooHighException	: public std::exception
		{
			const AForm &	_form;
			const int		_grade;
			
			public :
			
			GradeTooHighException( const AForm & form, const int grade );
			virtual const char * what( void ) const throw();
		};
		
		class GradeTooLowException	: public std::exception
		{
			const AForm & _form;
			const int	 _grade;
			
			public:
			
			GradeTooLowException( const AForm & form, const int grade );
			virtual const char * what( void ) const throw();
		};
};

std::ostream & operator<<( std::ostream & lhs, const AForm & rhs ); 