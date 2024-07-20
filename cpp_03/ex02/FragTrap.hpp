/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:19:42 by seblin            #+#    #+#             */
/*   Updated: 2024/07/20 19:02:55 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#pragma once

class FragTrap : public ClapTrap
{
	public:
		
		FragTrap( const std::string & name );
		virtual ~FragTrap( void );
		FragTrap( const FragTrap & src );
		FragTrap & operator=( const FragTrap & rhs);
				
	private:
		
		FragTrap( void );
		void highFivesGuy( void ) const;	
};