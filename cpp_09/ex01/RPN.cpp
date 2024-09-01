/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:38:43 by svidot            #+#    #+#             */
/*   Updated: 2024/09/01 16:53:25 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "Parser.hpp"
#include <sstream>
#include <utility>

std::pair<int, int> RPN::getPair()
{
    int a;
    int b;
    
    if (!this->stack.empty())     
    {
        b = this->stack.top(); 
        this->stack.pop();
        if (!this->stack.empty())     
        {
            a = this->stack.top(); 
            this->stack.pop();
            return std::make_pair(a, b);            
        }
    }       
    throw std::runtime_error("houston we have a problem");
}

void RPN::operatorHandle(const std::string & entry)
{
    std::pair<int, int> nbrs;
    
    switch (*entry.begin())
    {        
        case '+':
            nbrs = this->getPair();
            this->stack.push(nbrs.first + nbrs.second);
            break;                
        case '-':
            nbrs = this->getPair();
            this->stack.push(nbrs.first - nbrs.second);
            break; 
        case '*':
            nbrs = this->getPair();
            this->stack.push(nbrs.first * nbrs.second); 
            break;
        case '/':
            nbrs = this->getPair();
            this->stack.push(nbrs.first / nbrs.second);
            break;
        default:
            throw std::runtime_error
                (std::string("this shit is unauthorized: ") + entry);             
    }
}

RPN::RPN(std::string str)
{
    Parser psr;

    if (str.empty() || std::find_if(str.begin(), str.end(),
        psr.isNotSpace) == str.end())
        throw std::runtime_error("the string is empty");
        
    std::istringstream iss(str);
    std::string entry;

    while (std::getline(iss >> std::ws, entry, ' '))
    {
        if (entry.length() == 1 && !std::isdigit(*entry.begin()))           
            operatorHandle(entry);          
        else
            this->stack.push(psr.parseToInt(entry.begin(), entry.end()));
    }
    if (this->stack.size() == 1)
        std::cout << "the result is : " << this->stack.top() << std::endl;
    else
        throw std::runtime_error("houston we have a problem");
}

RPN::RPN()
{    
    return ;
}

RPN::~RPN()
{
    return ;
}  

RPN::RPN(const RPN &)
{
    return ;
}

RPN & RPN::operator=(const RPN &)
{
    return (*this);
}
