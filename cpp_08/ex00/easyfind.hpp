/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:26:21 by seblin            #+#    #+#             */
/*   Updated: 2024/08/10 17:50:18 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

template <typename T>
void easyfind(T t, float nbr)
{
	std::cout << "FLOAT haha: t: " << t << " nrb: " << nbr << std::endl;
}

template <typename T>
void easyfind(T t, int nbr)
{
	std::cout << "INT haha: t: " << t << " nrb: " << nbr << std::endl;
}

template <typename T, typename U>
class frin
{
	
};

// template <typename T>
// class frin
// {
	
// };


template <typename T>
class frin <T, float>
{
	// frin(int){}
};
template <typename T>
class frin <T, double>
{
	// frin(int){}
};


void find(int nbr)
{
	std::cout << "UNI "  << " nrb: " << nbr << std::endl;
}

void find(int nbr, int gt = 0)
{(void) gt;
	std::cout << "BI: t: "  << " nrb: " << nbr << std::endl;
}

// void find(float nbr)
// {
// 	std::cout << "haha: t: "  << " nrb: " << nbr << std::endl;
// }