/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:35:37 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 18:17:52 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main (void )
{	
	std::cout << std::endl;
	
	ScavTrap scavTrap = ScavTrap("mia");	
	scavTrap.attack("clara");
	scavTrap.beRepaired(10);
	scavTrap.takeDamage(10);
	std::cout << std::endl;	
	scavTrap.guardGate();
	
	std::cout << std::endl;
	
	FragTrap fragTrap = FragTrap("clara");	
	fragTrap.attack("mia");
	fragTrap.beRepaired(10);
	fragTrap.takeDamage(10);
	std::cout << std::endl;	
	fragTrap.highFivesGuy();
		
	std::cout << std::endl;	
	return (0);
}