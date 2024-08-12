/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:26:21 by seblin            #+#    #+#             */
/*   Updated: 2024/08/12 09:53:01 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <vector>
#include <algorithm>
template <typename T>
void easyfind(T t, int nbr)
{
	std::cout << "FLOAT haha: t: " << t << " nrb: " << nbr << std::endl;
}

template <>
void easyfind(std::vector<int> cont, int nbr)
{

	std::find(cont.begin(), cont.end(), nbr);
	for (it = t.begin(); it != t.end(); it++)
		if (nbr == *it)
			break;
	if (it == t.end()) 
		std::cout << "not find!" << std::endl;
	else
		std::cout << "find!" << *it << std::endl;
}
