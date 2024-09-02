/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:02:09 by svidot            #+#    #+#             */
/*   Updated: 2024/09/02 08:02:55 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class PmergeMe
{
    PmergeMe();
    PmergeMe(const PmergeMe & src);
    PmergeMe & operator=(const PmergeMe & rhs);
    
	void PmergeMe::calculateTime();
    public :
		
		PmergeMe(const std::string & str);
        ~PmergeMe();
};