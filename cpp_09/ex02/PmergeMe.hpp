/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:02:09 by svidot            #+#    #+#             */
/*   Updated: 2024/09/03 15:30:24 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <utility>

class PmergeMe
{
    std::vector<std::pair<int, int> >   vectA;
    std::vector<int>                    vectB;
    std::vector<int>                    vectC;
    // std::deque<std::pair<int, int> >    deq;
           
    PmergeMe();
    PmergeMe(const PmergeMe & src);
    PmergeMe & operator=(const PmergeMe & rhs);
    
	void    calculateTime();
    void    fillA(int value);
// void binarySort(std::vector<int>::iterator startA, std::vector<int>::iterator endA
// , std::vector<int>::iterator startB, std::vector<int>::iterator endB);

void binarySort(std::vector<std::pair<int, int> >::iterator startA, std::vector<std::pair<int, int> >::iterator endA
, std::vector<int>::iterator startB, std::vector<int>::iterator endB);

void mergeSort(std::vector<std::pair<int, int> >::iterator startA, std::vector<std::pair<int, int> >::iterator endA,
std::vector<int>::iterator startB, std::vector<int>::iterator endB);
    public :
		
		PmergeMe(char * argv[]);
        ~PmergeMe();
};