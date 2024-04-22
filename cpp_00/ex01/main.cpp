/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:22:27 by svidot            #+#    #+#             */
/*   Updated: 2024/04/22 16:57:59 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>


int main(void)
{
    std::string buffer;  
    PhoneBook   book;
    
    while (true)
    {        
        std::cin >> buffer;
        if (!buffer.compare("ADD"))
            add();
        else if (!buffer.compare("SEARCH"))
            search();           
        else if (!buffer.compare("EXIT"))
            break ;
    }
    return (0);    
}
