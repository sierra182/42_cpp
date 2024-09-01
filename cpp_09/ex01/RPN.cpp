/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:38:43 by svidot            #+#    #+#             */
/*   Updated: 2024/09/01 11:34:01 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "Parser.hpp"

RPN::RPN(std::string & str)
{
    Parser psr;
    
    std::string::iterator it = str.begin();
    while (it != str.end())
    {
        it = std::find_if(str.begin(), str.end(), psr.isNotSpace);
        psr.try
        
        it++;
    }
    // std::string::iterator it = std::find_if(str.begin(), str.end(), psr.isNotSpace);
    return ;
}

RPN::RPN()
{
    
    return ;
}

RPN::~RPN()
{
    return ;
}  

RPN::RPN(const RPN & src)
{
    return ;
}

RPN & RPN::operator=(const RPN &)
{
    return (*this);
}

// void    calculate()