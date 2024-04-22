/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:57:14 by svidot            #+#    #+#             */
/*   Updated: 2024/04/22 22:08:40 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <limits>

Contact::Contact(void)
{
    return ;
}

Contact::Contact(Contact const &src)
{
    *this = src;
    return ;
}

Contact &Contact::operator=(Contact const &rhs)
{
    (void) rhs;
    return (*this);
}

Contact::~Contact(void)
{
    return ;
}

void	Contact::getEntry(const std::string &str, std::string &entry)
{
	std::cout << str << std::endl;
    std::getline(std::cin, entry);
	if (entry.empty())
		this->getEntry(str, entry);
}

void	Contact::add(void)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->getEntry("enter firstname:", this->_firstname);
	this->getEntry("enter lastname:", this->_lastname);
	this->getEntry("enter nickname:", this->_nickname);  
	std::cout << "enter phone number:" << std::endl;
	while (!(std::cin >> this->_phoneNumber)) 
	{
        std::cin.clear();  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid number: " << std::endl;
    }
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->getEntry("enter darkest secret:", this->_darkestSecret);		
}
