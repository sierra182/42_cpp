/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:02:09 by svidot            #+#    #+#             */
/*   Updated: 2024/09/02 14:28:54 by svidot           ###   ########.fr       */
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

    public :
		
		PmergeMe(char * argv[]);
        ~PmergeMe();
};