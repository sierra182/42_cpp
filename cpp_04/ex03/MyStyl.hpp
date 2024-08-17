/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyStyl.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:36:42 by svidot            #+#    #+#             */
/*   Updated: 2024/08/17 09:32:46 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct MyStyl
{
    template <typename T>
	static void addActionTest(T action)
	{
		std::cout << "\e[1;3m * " << action << "\e[0m" << std::endl;
	}

    template <typename T>
	static void addWhatTest(T what)
	{
		std::cerr << std::endl << "\e[1;31m\t   Exception: " << what << "\e[0m"
				<< std::endl << std::endl;
	}

    template <typename T>
	static void addTest(T test)
	{
		std::cout << " ~~~~~~~~~~~~~~~";
		std::cout << "\e[1;3;90;103;9m ☣️  Test: " << test << " ☣️  \e[0m"
			<< std::endl << std::endl << std::endl;
	}	
};