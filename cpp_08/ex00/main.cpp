/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:26:24 by seblin            #+#    #+#             */
/*   Updated: 2024/08/13 09:16:55 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <stack>

void printCont(int item)
{
	std::cout << "\e[32m " << item << "\e[0m" << std::endl;
}

int main( void )
{
	std::cout << std::endl;
	{	
		int arr[] = {1, 2, 3, 4};
		std::vector<int> cont(arr, arr + 4);
		std::cout << "\e[32m" << "print\e[31m vector:" << "\e[0m" << std::endl;
		std::for_each(cont.begin(), cont.end(), printCont);
		std::cout << std::endl;
		{		
			int toFind = 4;
			std::cout << "\e[35m looking for: " << toFind << "\e[0m"
				<< std::endl;
			if (easyfind(cont, toFind))
				std::cout << "\e[32m we find your stuff!: " << toFind <<
					"\e[0m" << std::endl;
		else 	
				std::cout << "\e[1;31m we don't find your stuff! " << "(" <<
					toFind << ")\e[0m" << std::endl;
			std::cout << std::endl;
		}		
		{		
			int toFind = -4;
			std::cout << "\e[35m looking for: " << toFind << "\e[0m"
				<< std::endl;
			if (easyfind(cont, toFind))
				std::cout << "\e[32m we find your stuff!: " << toFind <<
					"\e[0m" << std::endl;
			else 	
				std::cout << "\e[1;31m we don't find your stuff! " << "(" <<
					toFind << ")\e[0m" << std::endl;
			std::cout << std::endl;
		}
	}	
	std::cout << " ***************" << std::endl << std::endl;
	{	
		int arr[] = {0, 22, 33, 44, 46};
		std::list<int> cont(arr, arr + 5);
		std::cout << "\e[32m" << "print\e[31m list:" << "\e[0m" << std::endl;
		std::for_each(cont.begin(), cont.end(), printCont);
		std::cout << std::endl;
		{		
			int toFind = 44;
			std::cout << "\e[35m looking for: " << toFind << "\e[0m"
				<< std::endl;
			if (easyfind(cont, toFind))
				std::cout << "\e[32m we find your stuff!: " << toFind <<
					"\e[0m" << std::endl;
			else 	
				std::cout << "\e[1;31m we don't find your stuff! " << "(" <<
					toFind << ")\e[0m" << std::endl;
			std::cout << std::endl;
		}		
		{		
			int toFind = 45;
			std::cout << "\e[35m looking for: " << toFind << "\e[0m"
				<< std::endl;
			if (easyfind(cont, toFind))
				std::cout << "\e[32m we find your stuff!: " << toFind <<
					"\e[0m" << std::endl;
			else 	
				std::cout << "\e[1;31m we don't find your stuff! " << "(" <<
					toFind << ")\e[0m" << std::endl;
			std::cout << std::endl;
		}
	}
	std::cout << " ***************" << std::endl << std::endl;
	{	
		int arr[] = {0, 22, 33, 44, 46, 54};
		std::deque<int> cont(arr, arr + 6);
		std::cout << "\e[32m" << "print\e[31m deque:" << "\e[0m" << std::endl;
		std::for_each(cont.begin(), cont.end(), printCont);
		std::cout << std::endl;
		{		
			int toFind = 0;
			std::cout << "\e[35m looking for: " << toFind << "\e[0m"
				<< std::endl;
			if (easyfind(cont, toFind))
				std::cout << "\e[32m we find your stuff!: " << toFind <<
					"\e[0m" << std::endl;
			else 	
				std::cout << "\e[1;31m we don't find your stuff! " << "(" <<
					toFind << ")\e[0m" << std::endl;
			std::cout << std::endl;
		}		
		{		
			int toFind = -1;
			std::cout << "\e[35m looking for: " << toFind << "\e[0m"
				<< std::endl;
			if (easyfind(cont, toFind))
				std::cout << "\e[32m we find your stuff!: " << toFind <<
					"\e[0m" << std::endl;
			else 	
				std::cout << "\e[1;31m we don't find your stuff! " << "(" <<
					toFind << ")\e[0m" << std::endl;
			std::cout << std::endl;
		}
	}
	return (0);
}