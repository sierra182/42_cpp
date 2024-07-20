/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:35:37 by seblin            #+#    #+#             */
/*   Updated: 2024/07/20 15:50:57 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main (void )
{
	ClapTrap trap("seb");
	trap.attack("test");
	trap.beRepaired(10);
	trap.takeDamage(10);
	

	
	
	ScavTrap scavtrap = ScavTrap("te");
	// delete scavtrap;
	// (void) scavtrap;
	return (0);
}