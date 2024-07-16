/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:02:24 by seblin            #+#    #+#             */
/*   Updated: 2024/07/16 10:40:26 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA( std::string name, Weapon & weapon );		
		void	attack( void ) const;
		
	private:
		const std::string _name;
		Weapon& 	_weapon;	
};