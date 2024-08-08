/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:22:27 by svidot            #+#    #+#             */
/*   Updated: 2024/08/08 14:46:18 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int main(void)
{
    std::string buffer;  
    PhoneBook   book;
		
	std::cout << std::endl << " 🦄 Welcome! ";
    try
    {
        while (true)
        {   
            std::cout << "Enter ADD, SEARCH or EXIT:" << std::endl << std::endl;    
            std::cin >> buffer;
			if (std::cin.eof())
				throw std::exception();
            if (!buffer.compare("ADD"))
                book.add();
            else if (!buffer.compare("SEARCH"))
                book.search();           
            else if (!buffer.compare("EXIT"))
                break ;
            std::cout << std::endl << " 💎 ";
        }
        
    }
    catch (const std::exception& e) {return (1);}
    return (0);    
}
