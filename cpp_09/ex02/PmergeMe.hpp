/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:02:09 by svidot            #+#    #+#             */
/*   Updated: 2024/09/04 10:57:44 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <ctime>

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
    
	double	calculateTime(std::clock_t start, std::clock_t end) const;
    void    fillA(int value);

void firstBinarySort(std::vector<std::pair<int, int> >::iterator startA, std::vector<std::pair<int, int> >::iterator endA
, std::vector<std::pair<int, int> >::iterator startB, std::vector<std::pair<int, int> >::iterator endB);

void binarySort(std::vector<std::pair<int, int> >::iterator startA, std::vector<std::pair<int, int> >::iterator endA
, std::vector<int>::iterator startB, std::vector<int>::iterator endB);

void mergeSort(std::vector<std::pair<int, int> >::iterator startA, std::vector<std::pair<int, int> >::iterator endA,
std::vector<int>::iterator startB, std::vector<int>::iterator endB);

    void    fillADeq(int value);

// void firstBinarySortDeq(std::deque<std::pair<int, int> >::iterator startA, std::deque<std::pair<int, int> >::iterator endA
// , std::deque<std::pair<int, int> >::iterator startB, std::deque<std::pair<int, int> >::iterator endB);


void firstBinarySortDeq(long unsigned int startA, long unsigned int endA
, long unsigned int startB, long unsigned int endB);

void binarySortDeq(std::deque<std::pair<int, int> >::iterator startA, std::deque<std::pair<int, int> >::iterator endA
, std::deque<int>::iterator startB, std::deque<int>::iterator endB);

void mergeSortDeq(std::deque<std::pair<int, int> >::iterator startA, std::deque<std::pair<int, int> >::iterator endA,
std::deque<int>::iterator startB, std::deque<int>::iterator endB);
	void PmergeMeDeq(char * argv[]);



    public :
		
		PmergeMe(char * argv[]);
        ~PmergeMe();
};