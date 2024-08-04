/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:28:49 by seblin            #+#    #+#             */
/*   Updated: 2024/08/04 07:30:24 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"
int	main( int argc, char * argv[] )
{
	if (argc != 2)
		return (std::cerr << "\e[31mwe need one argument please...\e[0m"
			<< std::endl, 1);
	std::string entry(*++argv);
	if (entry.empty())
		return (std::cerr << "\e[31mthe string is empty...\e[0m"
			<< std::endl, 1);
	std::cout << std::endl;
	ScalarConverter::convert(entry);
	std::cout << std::endl;
	return (0);
}