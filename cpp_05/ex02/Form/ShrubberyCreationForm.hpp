/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:56:02 by seblin            #+#    #+#             */
/*   Updated: 2024/07/30 16:51:20 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
	ShrubberyCreationForm( void );
	
	public:

		ShrubberyCreationForm( const std::string target );
		virtual ~ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm & src );
		ShrubberyCreationForm & operator=
			( const ShrubberyCreationForm & rhs );
};