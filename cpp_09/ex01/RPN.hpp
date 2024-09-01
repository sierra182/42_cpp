/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:36:22 by svidot            #+#    #+#             */
/*   Updated: 2024/09/01 16:45:37 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <list>

class RPN
{
    std::stack<int, std::list<int> > stack;
    
    RPN();
    RPN(const RPN & src);
    RPN & operator=(const RPN & rhs);    

    std::pair<int, int> getPair();
    void operatorHandle(const std::string & entry);
    
    public:
    
        RPN(std::string str);
        ~RPN();          
};