/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:56:10 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 20:18:14 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	RobotomyRequestForm( void );
	virtual void action( void ) const;

	const std::string _target;
	static bool _robotog;
	
	public:

		RobotomyRequestForm( const std::string target );
		virtual ~RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm & src );
		RobotomyRequestForm & operator=
			( const RobotomyRequestForm & rhs );
};