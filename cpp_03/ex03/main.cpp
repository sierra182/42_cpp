/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:35:37 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 10:27:50 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main (void )
{
	// ClapTrap trap("seb");
	// trap.attack("scavtrap");
	// trap.beRepaired(10);
	// trap.takeDamage(10);
	
	// std::cout << std::endl;
	
	// ScavTrap scavtrap = ScavTrap("crapaud");
	// scavtrap.attack("trap");
	// scavtrap.beRepaired(10);
	// scavtrap.takeDamage(10);

	// std::cout << std::endl;

	// FragTrap fragtrap = FragTrap("froggy");
	// fragtrap.attack("crapaud");
	// fragtrap.beRepaired(10);
	// fragtrap.takeDamage(10);

	std::cout << std::endl;

	DiamondTrap diamondTrap = DiamondTrap("froggy");
	diamondTrap.attack("seb");
	diamondTrap.beRepaired(10);
	diamondTrap.takeDamage(10);
	
	return (0);
}