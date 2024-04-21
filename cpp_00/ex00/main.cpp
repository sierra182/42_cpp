/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:13:15 by svidot            #+#    #+#             */
/*   Updated: 2024/04/21 15:17:34 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	while (*++argv)
	{
		std::string str = *argv; 
		for (std::string::iterator it = str.begin(); it != str.end(); it++)
			std::cout << static_cast<char>(std::toupper(*it));
		if (*(argv + 1))
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
