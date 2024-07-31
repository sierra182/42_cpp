/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:33:53 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 21:11:00 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>
#include "AForm.hpp"

class Intern
{
	AForm * makeForm( const std::string name, const std::string target ) const;
	
	public:

		Intern( void );
		virtual ~Intern( void );
		Intern( Intern const & src );
		Intern & operator=( const Intern & rhs);
};