/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:04:38 by svidot            #+#    #+#             */
/*   Updated: 2024/09/05 11:50:25 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Parser.hpp"
#include <sstream>

PmergeMe::PmergeMe()
{
    return ;
}

PmergeMe::PmergeMe(const PmergeMe &)
{
    return ;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & )
{
    return (*this);
}

PmergeMe::~PmergeMe()
{
    return ;
}

double	PmergeMe::calculateTime(std::clock_t start, std::clock_t end) const
{
	return (static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC);
}

void	printArgs(char *argv[])
{
	std::cout << std::endl;
	while (*++argv)
		std::cout << std::string(*argv) << " ";
	std::cout << std::endl << std::endl;
}

PmergeMe::PmergeMe(char *argv[])
{
	printArgs(argv);
	std::pair<double, long unsigned int> rVect = this->Vector(argv);
	std::pair<double, long unsigned int> rDeq = this->Deque(argv);
	
	std::cout << "time vector : " << rVect.first << ", n values :"
		<<  rVect.second << std::endl;
	std::cout << "time deque : " << rDeq.first << ", n values :"
		<<  rDeq.second << std::endl;
	std::cout << std::endl;
}

