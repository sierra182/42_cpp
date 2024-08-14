/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:42:01 by seblin            #+#    #+#             */
/*   Updated: 2024/08/14 21:33:52 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Span.hpp>
#include <algorithm>

template <class T>
void	print(const T & item)
{
	std::cout << item << std::endl;	
}

int main( void )
{
	Span sp(5);
	int arr[] = {2, 1};
	int arr2[] = {3, 4};
	sp.addNumber(24);
	sp.addNumber(29);
	std::cout << " set: " << sp << std::endl;
	sp.addNumber(arr, arr + 2);
	std::cout << " set: " << sp << std::endl;
	sp.addNumber(arr2, arr2 + 2);
	std::cout << " set: " << sp << std::endl;
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