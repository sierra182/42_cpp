/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySty.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:36:42 by svidot            #+#    #+#             */
/*   Updated: 2024/08/31 11:05:55 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct MySty
{
    template <typename T>
	static void	addTest(T test, int endl = 1)
	{
		std::cout << std::endl << std::endl << std::endl << " ~~~~~~~~~~~~~~~";
		std::cout << "\e[1;3;90;103;9m ☣️  Test: " << test << " ☣️  \e[0m"
			<< std::endl << std::endl;
		if (endl)
			std::cout << std::endl << std::endl;
	}	

	template <typename T>
	static void addSubTest(T test)
	{
		std::cout << std::endl << std::endl;
		std::cout << "\t\t\t\t\t\e[1;3;90;46;9m 🥶  Subtest: " << test <<
			" 🥶  \e[0m";		
		std::cout << "~~~" << std::endl << std::endl;
	}
		
    template <typename T>
	static void addAction(T action)
	{
		std::cout << "\e[1;3m * " << action << "\e[0m" << std::endl;
	}

    template <typename T>
	static void addWhat(T what)
	{		
		std::cerr << std::endl << "\e[1;36m\t 🏴‍☠️   Exception: \e[1;95m" << what <<
			"   🤢 🤮\e[0m" << std::endl << std::endl;
	}

	template <typename T>
	static void error(T what)
	{
		std::cerr << std::endl << "\e[1;31m\t 🏴‍☠️   Error: \e[1;95m" << what <<
			"   🤢 🤮\e[0m" << std::endl << std::endl;
	}	
};