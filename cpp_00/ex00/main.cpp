/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:13:15 by svidot            #+#    #+#             */
/*   Updated: 2024/04/20 19:03:50 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc <= 1)
        return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" 
                << std::endl, 0);        
    while (*++argv)
        std::cout << *argv; 
    std::cout << std::endl;
    return (0);
}