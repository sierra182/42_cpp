/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:40:58 by svidot            #+#    #+#             */
/*   Updated: 2024/09/01 14:40:49 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "MySty.hpp"

int main(int argc, char * argv[])
{
    if (argc != 2) //!changer le cont par default!!1
        return (MySty::error("we need one argument"), 1);
    try {
        RPN rpn(std::string(*++argv));         
        }
    catch (const std::exception & e)
        { MySty::addWhat(e.what()); }
    return (0);
}