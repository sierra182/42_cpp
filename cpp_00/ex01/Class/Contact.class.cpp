/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:57:14 by svidot            #+#    #+#             */
/*   Updated: 2024/04/23 14:07:45 by seblin           ###   ########.fr       */
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
    this->_firstname = rhs._firstname;
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

void	Contact::displayEntry(const std::string &entry) const
{	
	std::string	col;
	int			padding;

	col = entry;	
	padding = 0;
	if (entry.length() < this->WIDTH_COL)
		padding = this->WIDTH_COL - entry.length();
	else
	{
		col.resize(this->WIDTH_COL - 1);
		col.push_back('.');
	}
	while (padding--)
		col.insert(col.begin(), ' ');
	col.push_back('|');
	std::cout << col;
}

void	Contact::search(int index)
{	

	(void) index;
	
	//line += (static_cast<char>(index + 48));
	this->displayEntry(this->_firstname);
	this->displayEntry(this->_lastname);
	this->displayEntry(this->_nickname);
	std::cout << std::endl;
}