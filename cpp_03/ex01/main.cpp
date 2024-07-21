/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:35:37 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 18:31:06 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	return (0);
}