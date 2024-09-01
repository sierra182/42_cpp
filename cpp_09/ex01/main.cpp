/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:40:58 by svidot            #+#    #+#             */
/*   Updated: 2024/09/01 11:22:06 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "MySty.hpp"

int main(int argc, char * argv[])
{
    if (argc != 2)
		return (MySty::error("we need one argument"), 1);
    RPN rpn;    
    return (0);
}