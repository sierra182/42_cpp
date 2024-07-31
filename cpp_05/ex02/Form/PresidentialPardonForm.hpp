/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:56:22 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 14:08:06 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	PresidentialPardonForm( void );
	void action( void ) const;//?virtual
		
	const std::string _target;

	public:
	
		PresidentialPardonForm( const std::string target );
		virtual ~PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm & src );
		PresidentialPardonForm & operator=
			( const PresidentialPardonForm & rhs );		
};