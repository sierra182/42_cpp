/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:03:38 by svidot            #+#    #+#             */
/*   Updated: 2024/04/22 22:30:55 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _nContact(0)
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
	this->_nContact = (this->_nContact + 1) % (N_CT - 1);
	this->_contact[_nContact].add();
	this->_nContact++;
}

void    PhoneBook::search()
{
    
}