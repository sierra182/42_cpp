/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:33:53 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 20:39:34 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Intern
{
	Aform * makeForm( std::string , std::string );
	public:

		Intern( void );
		virtual ~Intern( void );
		Intern( Intern const & src );
		Intern & operator=( const Intern & rhs);
};