/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 07:35:37 by seblin            #+#    #+#             */
/*   Updated: 2024/07/21 18:54:09 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main (void )
{
	std::cout << std::endl;
	
	ClapTrap clapTrap = ClapTrap("emma");	
	clapTrap.attack("clara");
	clapTrap.beRepaired(10);
	clapTrap.takeDamage(10);	
			
	std::cout << std::endl;
	return (0);
}