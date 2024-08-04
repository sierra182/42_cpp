/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:28:49 by seblin            #+#    #+#             */
/*   Updated: 2024/08/04 18:09:56 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int	main( int argc, char * argv[] )
{
	if (argc != 2)
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
	return (0);
}