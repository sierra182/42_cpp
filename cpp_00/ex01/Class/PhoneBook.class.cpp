/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:03:38 by svidot            #+#    #+#             */
/*   Updated: 2024/04/23 14:16:44 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _nContact(-1)
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
    (void) rhs;
    //this->_jacque = rhs._jacque;
    return (*this);
}

PhoneBook::~PhoneBook(void)
{
    return ;
}

void	PhoneBook::add()
{  
	this->_nContact = (this->_nContact + 1) % (this->N_MAX - 1);
	this->_contact[_nContact].add();
	this->_nContact++;
}

void    PhoneBook::search()
{
	int	index;
	
	for (int i = 0; i < this->N_MAX; i++)
    	this->_contact[i].search(4);
	std::cout << "enter contact index:" << std::endl;
	while (!(std::cin >> index))
	{
		
	}	
}