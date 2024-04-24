/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:57:14 by svidot            #+#    #+#             */
/*   Updated: 2024/04/24 13:41:27 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <limits>
#include <sstream>

PhoneBook::Contact::Contact(void) : _phoneNumber(0)
{
    return ;
}

PhoneBook::Contact::Contact(PhoneBook::Contact const &src)
{
    *this = src;
    return ;
}

PhoneBook::Contact &PhoneBook::Contact::operator=(PhoneBook::Contact const &rhs)
{
    this->_firstname = rhs._firstname;
    return (*this);
}

PhoneBook::Contact::~Contact(void)
{
    return ;
}

void	PhoneBook::Contact::getEntry(const std::string &str, std::string &entry)
{
	std::cout << str << std::endl;
    std::getline(std::cin, entry);
	if (std::cin.eof())
		throw std::exception();
	if (entry.empty())		
		this->getEntry(str, entry);	
}

void	PhoneBook::Contact::add(void)
{
	std::cout << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->getEntry(" Enter firstname:", this->_firstname);
	this->getEntry(" Enter lastname:", this->_lastname);
	this->getEntry(" Enter nickname:", this->_nickname);  
	std::cout << " Enter phone number:" << std::endl;
	while (!(std::cin >> this->_phoneNumber) || std::cin.peek() != '\n' || this->_phoneNumber < 0) 
	{
		if (std::cin.eof())
			throw std::exception();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " ❌ Invalid input. Please enter a valid number: " << std::endl;
    }	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->getEntry(" Enter darkest secret:", this->_darkestSecret);
	 std::cout  << std::endl << " ✅ New friend Added with Succes!" << std::endl;		
}

void	PhoneBook::Contact::displayEntry(const std::string &entry) const
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

std::string itos(int value)
{
    std::ostringstream oss;
    oss << value;
    return (oss.str());
}

void	PhoneBook::Contact::search(int index) const
{
	this->displayEntry(itos(index));
	this->displayEntry(this->_firstname);
	this->displayEntry(this->_lastname);
	this->displayEntry(this->_nickname);
	std::cout << std::endl;
}

void	PhoneBook::Contact::displayItem(void) const
{
	std::cout << std::endl;
	std::cout << this->_firstname << std::endl;
	std::cout << this->_lastname << std::endl;
	std::cout << this->_nickname << std::endl;
	std::cout << this->_phoneNumber << std::endl;
	std::cout << this->_darkestSecret << std::endl;	
}
