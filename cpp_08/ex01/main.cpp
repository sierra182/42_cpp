/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:42:01 by seblin            #+#    #+#             */
/*   Updated: 2024/08/16 09:34:39 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Span.hpp>
#include <algorithm>
#include <list>
#include <vector>
#include <ctime>
// template <class T>
// void	print(const T & item)
// {
// 	std::cout << item << std::endl;	
// }

int getRandom()
{
	return rand() - RAND_MAX / 2;
}

int main( void )
{
	std::cout << std::endl;
	{
	std::cout << "\e[1;3;90;103;9m\t ☣️  Test: exception N max ☣️  \e[0m" << std::endl
		<< std::endl;
	
	try	{
		std::cout << "\e[3m create span with N = 0 \e[0m" << std::endl;
		Span sp(0);
		sp.addNumber(1);	
	}
	catch(const std::exception & e)
		{ std::cerr << "\e[1;31m\t Exception: \e[31m" << e.what() << "\e[0m" << std::endl; }
	
	try	{
		Span sp(4);
		int arr[] = {2, 1, 99, -100, -200};
		sp.addNumber(arr, arr + 5);	
	}
	catch(const std::exception & e)
		{ std::cerr << e.what() << std::endl; }
	}
	return (0);
}

// int main( void )
// {	
// 	std::srand(static_cast<unsigned int>(std::time(NULL)));
// 	Span sp(16000);
// 	// int arr[] = {2, 1};
// 	// int arr2[] = {4, 4};
// 	// sp.addNumber(24);
// 	// sp.addNumber(29);
// 	// std::cout << " set: " << sp << std::endl;
// 	// sp.addNumber(arr, arr + 2);
// 	// std::cout << " set: " << sp << std::endl;
// 	// sp.addNumber(arr2, arr2 + 2);
// 	// std::cout << " set: " << sp << std::endl;
// 	// std::list<int> list(4,5);
// 	// sp.addNumber(list.begin(), list.end()); //verif distance work with list
// 	// std::cout << " set: " << sp << std::endl;
// 	// std::cout << " yolo" << std::endl;
// 	// std::cout << sp.longestSpan() << std::endl;
// 	// std::cout << " yolo2" << std::endl;
// 	// std::cout << sp.shortestSpan() << std::endl;

// 	std::vector<int> big(15000);
// 	std::generate(big.begin(), big.end(), getRandom);
// 	sp.addNumber(big.begin(), big.end());
// 	std::cout << sp.longestSpan() << std::endl;
// 	std::cout << " yolo2" << std::endl;
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << " set: " << sp << std::endl;
	
// 	// sp.addNumber(42);
// 	// std::cout << " set: " << sp << std::endl;
// 	// sp.addNumber(43);
// 	// std::cout << " set: " << sp << std::endl;
// 	// sp.addNumber(46);
// 	// std::cout << " set: " << sp << std::endl;
// 	// std::for_each(arr, arr+2, print<int>);	
// 	// operator<< <int>(std::cout, sp );
	
// 	return (0);
// }
// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }
// int main()
// {
// Span sp = Span(5);
// sp.addNumber(-24);
// sp.addNumber(-22);
// sp.addNumber(0);
// sp.addNumber(10);
// sp.addNumber(16);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }