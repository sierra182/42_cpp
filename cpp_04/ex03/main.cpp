/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:10:54 by seblin            #+#    #+#             */
/*   Updated: 2024/07/24 14:38:16 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

int	main( void )
{
	Ice ice;
	std::cout << ice.i << std::endl;
	std::cout<< std::endl;
	Ice* ice2 = new Ice();
	std::cout << ice2->i << std::endl;
	
	//   AMateria * am = new Ice();
	// std::cout << am->test << std::endl;
	return (0);
}