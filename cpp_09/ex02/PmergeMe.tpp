/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:27:52 by seblin            #+#    #+#             */
/*   Updated: 2024/09/06 17:42:46 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template < template < typename, typename > class T >
void PmergeMe::printPair(
	const T<std::pair<int, int>, std::allocator<std::pair<int, int> > > &vect,
 	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >
	::const_iterator startA, 
	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >
	::const_iterator endA,
	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >
	::iterator startB, 
	typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >
	::iterator endB) 
	const
{
	std::cout << "\e[H";
	
	for (typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >
		::const_iterator it = vect.begin(); it != vect.end(); it++)
	{		
		if (it == startB)
			std::cout << "\e[44m";
		else if (it == startA)
			std::cout << "\e[42m";	
		std::cout << "\e[2K" << it->first << ", " << it->second << std::endl;// " \e[0m" << std::endl;			
		// if (it == endA)
		// 	std::cout << "\e[31m";
		// if (it == endB)
		// 	std::cout << "\e[35m";
	}
	std::cout << std::endl;
	// std::cin.get();
	usleep(20000);	
	std::cout << "\e[0m" << std::endl;
}

template < template < typename, typename > class T >
void PmergeMe::printCont(T<int, std::allocator<int> > const & vect) const
{
	std::cout << std::endl << "\e[32m After: " << std::endl;
	
	for (typename T<int, std::allocator<int> >::const_iterator
		it = vect.begin(); it != vect.end(); it++)	
			std::cout << *it << " " << std::flush;
		
	std::cout << "\e[0m" << std::endl << std::endl;
}

template < template < typename, typename > class T >
void PmergeMe::printContStyl(T<int, std::allocator<int> > const & vect) const
{
	std::cout << "\r\e[2K";
	for (typename T<int, std::allocator<int> >::const_iterator
		it = vect.begin(); it != vect.end(); it++)	
		std::cout << *it << " " << std::flush;
		
	// std::cout << "\e[4A";	
	
	std::cout << "\e[0m";// << std::endl;
	usleep(100000);
}

template < template < typename, typename > class T > 
void PmergeMe::checkFinal(T<int, std::allocator<int> > vect,
	long unsigned int len) const
{
	if (len != vect.size())
		std::cout << "\e[31m Error: final size : " << vect.size()
		<< ", needed: " << len << std::endl;
		
	typename T<int, std::allocator<int> >::iterator it = vect.begin();
	typename T<int, std::allocator<int> >::iterator it_tmp = vect.begin();
	for (; it != vect.end(); it++)
	{
		if (*it >= *it_tmp)		
			it_tmp = it;		
		else
		{
			std::cout << "\e[31m Error: " << *it << ", " << *it_tmp
				<< "\e[0m" << std::endl;
			return;
		}
	}
	std::cout << "\e[32m no problemo\e[0m" << std::endl;
}