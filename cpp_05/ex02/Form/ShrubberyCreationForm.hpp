/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:56:02 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 14:08:17 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	ShrubberyCreationForm( void );
	void action( void ) const;//?virtual
	
	const std::string _target;
	
	public:

		ShrubberyCreationForm( const std::string target );
		virtual ~ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm & src );
		ShrubberyCreationForm & operator=
			( const ShrubberyCreationForm & rhs );
};