/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:36:22 by svidot            #+#    #+#             */
/*   Updated: 2024/09/01 11:29:07 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN
{
    RPN();
    RPN(const RPN & src);
    RPN & operator=(const RPN & rhs);
    std::stack<int> stack;
    
    public:
    
        RPN(std::string & str)
        ~RPN();          
};