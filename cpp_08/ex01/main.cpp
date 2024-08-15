/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:42:01 by seblin            #+#    #+#             */
/*   Updated: 2024/08/15 14:30:18 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Span.hpp>
#include <algorithm>
#include <list>

template <class T>
void	print(const T & item)
{
	std::cout << item << std::endl;	
}

int main( void )
{
	Span sp(51);
	int arr[] = {2, 1};
	int arr2[] = {3, 4};
	sp.addNumber(24);
	sp.addNumber(29);
	std::cout << " set: " << sp << std::endl;
	sp.addNumber(arr, arr + 2);
	std::cout << " set: " << sp << std::endl;
	sp.addNumber(arr2, arr2 + 2);
	std::cout << " set: " << sp << std::endl;
	std::list<int> list(4,5);
	sp.addNumber(list.begin(), list.end()); //verif distance work with list
	std::cout << " set: " << sp << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	// sp.addNumber(42);
	// std::cout << " set: " << sp << std::endl;
	// sp.addNumber(43);
	// std::cout << " set: " << sp << std::endl;
	// sp.addNumber(46);
	// std::cout << " set: " << sp << std::endl;
	// std::for_each(arr, arr+2, print<int>);	
	// operator<< <int>(std::cout, sp );
	
	return (0);
}