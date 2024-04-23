/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:22:27 by svidot            #+#    #+#             */
/*   Updated: 2024/04/23 17:03:38 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int main(void)
{
    std::string buffer;  
    PhoneBook   book;

    while (true)
    {        
        std::cin >> buffer;
        if (!buffer.compare("ADD"))
            book.add();
        else if (!buffer.compare("SEARCH"))
            book.search();           
        else if (!buffer.compare("EXIT"))
            break ;
    }
    return (0);    
}
