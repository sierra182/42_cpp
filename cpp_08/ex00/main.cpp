/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:26:24 by seblin            #+#    #+#             */
/*   Updated: 2024/08/11 18:35:58 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main( void )
{
	const int  e [4] = {2};
	// e[0] =1;
	(void) e;
	// easyfind(42, 42);
	int re[4] = {1, 2, 3, 4};
	std::vector<int> vect(re, re + 4);
	// std::vector<int> vect(2, 2);
	easyfind(vect, -1);
	// frin<int, int> fr2; (void) fr2;
	// find(2);
	// easyfind(42, f);
	// easyfind(42, 42.f);
	// easyfind(42, 42);
	// // easyfind(42, 42.0);
	// find(f);
	// find(42.f);
	// find(42);
	// find(42.0);
	return (0);
}