/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:38:43 by svidot            #+#    #+#             */
/*   Updated: 2024/09/01 15:20:09 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "Parser.hpp"
#include <sstream>
#include <utility>

std::pair<int, int> RPN::calculate()
{
    int a;
    int b;
    
    if (!this->stack.empty())     
    {
        a = this->stack.top(); 
        this->stack.pop();
        if (!this->stack.empty())     
        {
            b = this->stack.top(); 
            this->stack.pop();
            return std::make_pair(a, b);            
        }
    }       
    throw std::runtime_error("the stack is empty");
}

RPN::RPN(std::string str)
{
    Parser psr;
    
    // std::string::iterator it = str.begin();
    std::istringstream iss(str);
    std::string line;
    std::pair<int, int> nbrs;
    while (std::getline(iss >> std::ws, line, ' '))
    {
        if (line.length() == 1 && !std::isdigit(*line.begin()))
            switch (*line.begin())
            {
                
                case '+':
                    std::cout << "plus connard" << std::endl;
                    nbrs = this->calculate();
                    this->stack.push(nbrs.first + nbrs.second);
                    break;                
                case '-':
                    std::cout << "moins connard" << std::endl;
                    nbrs = this->calculate();
                    this->stack.push(nbrs.first - nbrs.second);
                    break; 
                case '*':
                    std::cout << "fois connard" << std::endl;
                    nbrs = this->calculate();
                    this->stack.push(nbrs.first * nbrs.second); 
                    break;
                case '/':
                    std::cout << "div connard" << std::endl;
                    nbrs = this->calculate();
                    this->stack.push(nbrs.first / nbrs.second);
                    break;
                default:
                    std::cout << "nique toi" << std::endl;             
            }
        else
            this->stack.push(psr.parseToInt(line.begin(), line.end()));
    }
    if (this->stack.size() == 1)
        std::cout << "the result is : " << this->stack.top() << std::endl;
    else
        throw std::runtime_error("houston we have a problem");
    
    // while (it != str.end())
    // {
    //     it = std::find_if(str.begin(), str.end(), psr.isNotSpace);
    //     // psr.try
    //     switch (expression)
    //     {
    //     case /* constant-expression */:
    //         /* code */
    //         break;
        
    //     default:
    //         break;
    //     }
    //     it++;
    // }
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

RPN::RPN(const RPN &)
{
    return ;
}

RPN & RPN::operator=(const RPN &)
{
    return (*this);
}

// void    calculate()