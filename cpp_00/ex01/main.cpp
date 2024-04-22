/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:22:27 by svidot            #+#    #+#             */
/*   Updated: 2024/04/22 15:21:52 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>

int main(void)
{
    PhoneBook phoneBook;
    std::cout << "cpy jacque: " << phoneBook._jacque << std::endl;
    
    // PhoneBook phoneBookCpy(phoneBook);
    // std::cout << "cpy jacque: " << phoneBookCpy._jacque << std::endl;
    
    PhoneBook phoneBookOP;
    phoneBookOP._jacque = 51;
    phoneBookOP = phoneBook;
    std::cout << "OP jacque: " << phoneBookOP._jacque << std::endl;
    std::cout << std::endl;
    
    PhoneBook *phoneBook2 = new PhoneBook();
    std::cout << "cpy jacque: " << phoneBook2->_jacque << std::endl;
    // PhoneBook *phoneBookCpy2 = new PhoneBook(*phoneBook2);
    // std::cout << "cpy jacque: " << phoneBookCpy2->_jacque << std::endl;
    PhoneBook *phoneBookOP2 = new PhoneBook();
    *phoneBookOP2 = *phoneBook2;
    std::cout << "OP jacque: " << phoneBookOP2->_jacque << std::endl;
    delete (phoneBook2);
    delete (phoneBookOP2);
    return (0);    
}
