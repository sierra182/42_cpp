/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:10:54 by seblin            #+#    #+#             */
/*   Updated: 2024/07/24 17:02:26 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main( void )
{
	Ice ice;
	
	std::cout<< std::endl;
	Ice* ice2 = new Ice();

	AMateria * ice3 = new Ice("truc");
	
	std::cout << "type: " << ice3->getType() << std::endl;

	AMateria * ice4 = new Cure("machin");
	
	std::cout << "type: " << ice4->getType() << std::endl;
	(void) ice3;
	(void) ice2;

	// Character chara;
	//   AMateria * am = new Ice();
	return (0);
}