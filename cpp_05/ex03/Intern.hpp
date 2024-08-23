/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:33:53 by seblin            #+#    #+#             */
/*   Updated: 2024/08/23 14:17:05 by svidot           ###   ########.fr       */
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

	template <class T>
	AForm * makeTForm( const std::string & target ) const
		{return (new T(target));}

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