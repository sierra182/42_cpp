/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:02:05 by seblin            #+#    #+#             */
/*   Updated: 2024/07/16 11:27:50 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon
{
	public:

		Weapon( void );	
		Weapon( const std::string type);
	
		std::string const & getType( void ) const;
		void 				setType( const std::string type);
		
	private:

		std::string type;
};