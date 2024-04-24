/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:03:38 by svidot            #+#    #+#             */
/*   Updated: 2024/04/24 14:24:51 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _nContact(0), _isFull(false)
{
    return ;
}

PhoneBook::PhoneBook(PhoneBook const &src)
{
    *this = src;
    return ;
}

PhoneBook &PhoneBook::operator=(PhoneBook const &rhs)
{
    this->_isFull = rhs._isFull;
    return (*this);
}

PhoneBook::~PhoneBook(void)
{
    return ;
}

void	PhoneBook::add()
{  
	this->_contact[_nContact].add();
	this->_nContact = (this->_nContact + 1) % (this->N_MAX);
	if (!this->_nContact)
		this->_isFull = true;
}

void    PhoneBook::search() const
{
	unsigned int	index;	
	int				max_contact;
	
	if (!this->_nContact && !this->_isFull)
	{
		std::cout << std::endl << " No friends! 😭, choose ADD..."
            << std::endl;
		return ;
	}
	max_contact = this->_isFull ? this->N_MAX : this->_nContact;
	for (int i = 0; i < max_contact; i++)
    	this->_contact[i].search(i);
	std::cout  << std::endl << "\033[36m Enter contact Index:\033[0m "
        << std::endl;
	while (!(std::cin >> index) || std::cin.peek() != '\n'
		|| (!this->_isFull && index >= this->_nContact)
		|| (this->_isFull && index >= this->N_MAX)) 
	{
        if (std::cin.eof())
			throw std::exception();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " ❌ \033[31mInvalid input! retry:\033[0m" << std::endl;
    }
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->_contact[index].displayItem();
}
