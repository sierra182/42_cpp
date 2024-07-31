/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:33:53 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 22:02:05 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>
#include "AForm.hpp"

#define FRM 3

class Intern
{
	void (Intern::*forms[FRM]) ( const std::string ) const;
	
	public:

		Intern( void );
		virtual ~Intern( void );
		Intern( Intern const & src );
		Intern & operator=( const Intern & rhs);
		
		AForm * makeForm( const std::string name, const std::string target )
			const;
};