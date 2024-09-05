/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:02:09 by svidot            #+#    #+#             */
/*   Updated: 2024/09/05 10:43:39 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <ctime>
#include <sstream>
#include "Parser.hpp"
#include <unistd.h>

class PmergeMe
{
    std::vector<std::pair<int, int> >   vectA;
    std::vector<int>                    vectB;
    std::vector<int>                    vectC;
	
    std::deque<std::pair<int, int> >    deqA;
    std::deque<int>    					deqB;
	std::deque<int>   					deqC;
	
    PmergeMe();
    PmergeMe(const PmergeMe & src);
    PmergeMe & operator=(const PmergeMe & rhs);
	
    void	Vector(char *argv[]);
	void	Deque(char *argv[]);
		
    void    fillAVect(int value);
	
	void 	firstBinarySortVect(
		std::vector<std::pair<int, int> >::iterator startA,
		std::vector<std::pair<int, int> >::iterator endA,
		std::vector<std::pair<int, int> >::iterator startB,
		std::vector<std::pair<int, int> >::iterator endB);

	void	binarySortVect(
		std::vector<std::pair<int, int> >::iterator startA,
		std::vector<std::pair<int, int> >::iterator endA,
		std::vector<int>::iterator startB,
		std::vector<int>::iterator endB);

	void	mergeSortVect(
		std::vector<std::pair<int, int> >::iterator startA,
		std::vector<std::pair<int, int> >::iterator endA,
		std::vector<int>::iterator startB,
		std::vector<int>::iterator endB);

    void    fillADeq(int value);

	void	firstBinarySortDeq(
		long unsigned int startA,
		long unsigned int endA,
		long unsigned int startB,
		long unsigned int endB);

	void	binarySortDeq(
		std::deque<std::pair<int, int> >::iterator startA,
		std::deque<std::pair<int, int> >::iterator endA,
		std::deque<int>::iterator startB,
		std::deque<int>::iterator endB);

	void	mergeSortDeq(
		std::deque<std::pair<int, int> >::iterator startA,
		std::deque<std::pair<int, int> >::iterator endA,
		std::deque<int>::iterator startB,
		std::deque<int>::iterator endB);

	double	calculateTime(std::clock_t start, std::clock_t end) const;
	
	template < template <typename, typename> class T>
	void	printCont(T<int, std::allocator<int> > const & vect) const;

	template < template < typename, typename > class T>
	void	printPair(
		const T<std::pair<int, int>, std::allocator<std::pair<int, int> > >
		&vect,
 		typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >
		::const_iterator startA, 
		typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >
		::const_iterator endA,
		typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >
		::iterator startB, 
		typename T<std::pair<int, int>, std::allocator<std::pair<int, int> > >
		::iterator endB)
		const;

	template < template < typename, typename > class T > 
	void	checkFinal(T<int, std::allocator<int> > vect,
		long unsigned int len) const;
		
    public :
		
		PmergeMe(char * argv[]);
        ~PmergeMe();
};

#include "PmergeMe.tpp"