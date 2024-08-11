/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:26:21 by seblin            #+#    #+#             */
/*   Updated: 2024/08/11 18:35:23 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <vector>
template <typename T>
void easyfind(T t, int nbr)
{
	std::cout << "FLOAT haha: t: " << t << " nrb: " << nbr << std::endl;
}

template <>
void easyfind(std::vector<int> t, int nbr)
{
	std::vector<int>::iterator it;

	for (it = t.begin(); it != t.end(); it++)
		if (nbr == *it)
			break;
	if (it == t.end()) 
		std::cout << "not find!" << std::endl;
	else
		std::cout << "find!" << *it << std::endl;
}
