/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:27:52 by seblin            #+#    #+#             */
/*   Updated: 2024/09/05 15:21:19 by svidot           ###   ########.fr       */
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
	for (typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >
		::const_iterator it = vect.begin(); it != vect.end(); it++)
	{		
		if (it == startA)
			std::cout << "\e[32m";	
		if (it == startB)
			std::cout << "\e[34m";
		if (it == endA)
			std::cout << "\e[31m";
		if (it == endB)
			std::cout << "\e[35m";	
		std::cout << it->first << ", " << it->second << " \e[0m" << std::endl;				
	}	
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