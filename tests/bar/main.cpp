/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:26:06 by svidot            #+#    #+#             */
/*   Updated: 2024/08/15 10:41:30 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
    int n_test = 3;
    char buff;
    
    // std::cout << "D" << std::endl;
    // std::cout << "D" << std::endl;
    
    std::cout << "truc " << std::endl;
    std::cout << "truc " << std::endl;
    std::cout << "truc " << std::endl;
    std::cout << "truc " << std::endl;
    std::cout << "truc " << std::endl;
    std::cout << "truc " << std::endl;
    std::cout << "truc " << std::endl;
    std::cout << "truc " << std::endl;  
    std::cin >> buff;
    std::cout << "\033[5A" << "D" <<  std::endl;
    std::cout << "\033[15B" << "D" <<  std::endl;
     
    
}