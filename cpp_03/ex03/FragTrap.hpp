/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:19:42 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 14:51:29 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#pragma once

class FragTrap : virtual public ClapTrap
{
	public:
		
		FragTrap( const std::string & name );
		virtual ~FragTrap( void );
		FragTrap( const FragTrap & src );
		FragTrap & operator=( const FragTrap & rhs);

	protected:
	
		void highFivesGuy( void ) const;	
			
	private:
		
		FragTrap( void );
};