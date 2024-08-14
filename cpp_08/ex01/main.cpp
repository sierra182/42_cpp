/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:42:01 by seblin            #+#    #+#             */
/*   Updated: 2024/08/14 16:44:18 by svidot           ###   ########.fr       */
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
	int arr2[] = {2, 1};
	sp.addNumber(24);
	sp.addNumber(arr, arr + 2);
	sp.addNumber(arr2, arr2 + 2);
	sp.addNumber(42);

	// std::for_each(arr, arr+2, print<int>);
	
	std::cout << sp;
	return (0);
}