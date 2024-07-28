/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:34:30 by seblin            #+#    #+#             */
/*   Updated: 2024/07/28 18:42:06 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include<ostream>

class Bureaucrat
{
	Bureaucrat( void );
	const std::string	_name;
	int 				_grade;
	
	public:
		
		virtual ~Bureaucrat( void );
		Bureaucrat( const Bureaucrat & src );
		Bureaucrat( std::string const name, int const grade );
		Bureaucrat & operator=( const Bureaucrat & rhs );

		const std::string &	getName( void ) const;
		int  				getGrade( void ) const;
		void				incrementGrade( void );
		void				decrementGrade( void );
};