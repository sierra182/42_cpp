/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:35:37 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 16:56:43 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main (void )
{
	std::cout << std::endl;
	DiamondTrap diamondTrap = DiamondTrap("clara");
	
	std::cout << std::endl;
	diamondTrap.attack("katsuni");
	diamondTrap.beRepaired(10);
	diamondTrap.takeDamage(10);
	std::cout << std::endl;
	
	return (0);
}