/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:34:30 by seblin            #+#    #+#             */
/*   Updated: 2024/07/30 10:48:37 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include<ostream>

class Form;
class Bureaucrat
{
	Bureaucrat( void );
	const std::string	_name;
	int 				_grade;
	
	void isGradeAccept( int grade ) const;
	
	public:
		
		virtual ~Bureaucrat( void );
		Bureaucrat( const Bureaucrat & src );
		Bureaucrat( std::string const name, int const grade );
		Bureaucrat & operator=( const Bureaucrat & rhs );

		const std::string &	getName( void ) const;
		int  				getGrade( void ) const;
		void				incrementGrade( void );
		void				decrementGrade( void );
		void 				signForm( Form & form ) const;

		class GradeTooHighException : public std::exception
		{
			const Bureaucrat & _bur;
			public:
		
				GradeTooHighException( const Bureaucrat & bur );
				virtual const char * what( void ) const throw();		
		};
				
		class GradeTooLowException : public std::exception
		{
			const Bureaucrat & _bur;
			public:
			
				GradeTooLowException( const Bureaucrat & bur );
				virtual const char * what( void ) const throw();		
		};		
};

std::ostream & operator<<( std::ostream & lhs, const Bureaucrat & rhs );
