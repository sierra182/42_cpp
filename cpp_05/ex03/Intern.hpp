/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:33:53 by seblin            #+#    #+#             */
/*   Updated: 2024/08/01 11:06:16 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>
#include "AForm.hpp"

#define FRM 3

class Intern
{
	static const std::string mapping[FRM];
	AForm * (Intern::*forms[FRM]) ( const std::string & target ) const;

	AForm * makePresidentialForm( const std::string & target ) const;	
	AForm * makeRobotomyForm( const std::string & target ) const;	
	AForm * makeShubberyForm( const std::string & target ) const;
	
	public:

		Intern( void );
		virtual ~Intern( void );
		Intern( Intern const & src );
		Intern & operator=( const Intern & rhs);
		
		AForm * makeForm( const std::string name, const std::string target )
			const;
		
		class FormNoExist : public std::exception
		{			
			virtual const char * what( void ) const throw();
		};
};