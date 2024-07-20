/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:35:37 by seblin            #+#    #+#             */
/*   Updated: 2024/07/20 18:53:22 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main (void )
{
	ClapTrap trap("seb");
	trap.attack("scavtrap");
	trap.beRepaired(10);
	trap.takeDamage(10);
		
	ScavTrap scavtrap = ScavTrap("crapaud");
	scavtrap.attack("trap");
	scavtrap.beRepaired(10);
	scavtrap.takeDamage(10);
	
	return (0);
}