/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:42:01 by seblin            #+#    #+#             */
/*   Updated: 2024/08/14 08:37:32 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Span.hpp>

int main( void )
{
	Span sp(5);
	int arr[] = {2, 1};
	int arr2[] = {2, 1};
	sp.addNumber(24);
	sp.addNumber(arr, arr + 2);
	sp.addNumber(arr2, arr2 + 2);
	sp.addNumber(42);
	return (0);
}