/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:51:53 by seblin            #+#    #+#             */
/*   Updated: 2024/08/07 12:26:04 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main (void )
{
	{	
		std::cout << std::endl;
		int arr[] = {42, 24, 21};
		iter(arr, 3, myfunct);
	}
	{	
		std::cout << std::endl;
		char arr[] = {'z', 's', 'h'};
		iter(arr, 3, myfunct);
	}	
	{	
		std::cout << std::endl;
		float arr[] = {42.2f, 0.1f, 974.974f};
		iter(arr, 3, myfunct);
	}
	{	
		std::cout << std::endl;
		double arr[] = {42.2, 0.1, 974.974};
		iter(arr, 3, myfunct);
	}
	{	
		std::cout << std::endl;	
		std::string arr[] = {"je", "souffre", "d'un", "manque", "cruel",
			"d'imagination"};
		iter(arr, 6, myfunct);
	}	
	std::cout << std::endl;
	return (0);
}