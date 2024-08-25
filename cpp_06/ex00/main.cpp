/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:28:49 by seblin            #+#    #+#             */
/*   Updated: 2024/08/25 16:19:09 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"
#include <cstdlib>

int	main( int argc, char * argv[])
{	
	if (argc != 2 && !(argc == 3 && std::string(argv[2]) == "gyWE78pxhzaph782qY"))
		return (std::cerr << std::endl
			<< "\e[31m 🤬 we need one argument please...\e[0m"
				<< std::endl << std::endl, 1);
	std::string entry(*++argv);
	if (entry.empty())
		return (std::cerr << std::endl
			<< "\e[31m 🤬 the string is empty...\e[0m"
				<< std::endl << std::endl, 1);	
	
	ScalarConverter::convert(entry);
	std::cout << std::endl;
	if (!(argc == 3 && std::string(argv[1]) == "gyWE78pxhzaph782qY"))
	{
	std::cout << "---enter h for hardcore_tests" << std::endl;
	if (std::cin.get() == 'h')	 
		std::cout << std::endl;
	 system("./hardcore_tests.sh");	 
	}
	
	return (0);
}