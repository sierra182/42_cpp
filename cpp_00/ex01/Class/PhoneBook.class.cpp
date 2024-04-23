/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:03:38 by svidot            #+#    #+#             */
/*   Updated: 2024/04/23 22:14:10 by seblin           ###   ########.fr       */
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
	this->_contact[_nContact].add();
	this->_nContact = (this->_nContact + 1) % (this->N_MAX);
	if (!this->_nContact)
		this->_isFull = true;
}

#include <sstream>
void	stoi(std::string )
{		
    std::istringstream iss(input);
    int num;

    iss >> num;
    if (iss.fail() || !iss.eof()) {  // Vérifiez si la conversion a échoué ou si la chaîne n'a pas été complètement consommée
        std::cout << "Erreur de conversion ou données en excès." << std::endl;
    } else {
        std::cout << "Nombre lu avec succès: " << num << std::endl;
    }
}

void    PhoneBook::search() const
{
	unsigned int	index;	
	int				max_contact;
	
	if (!this->_nContact && !this->_isFull)
	{
		std::cout << "no friends :(" << std::endl;
		return ;
	}
	max_contact = this->_isFull ? this->N_MAX : this->_nContact;
	for (int i = 0; i < max_contact; i++)
    	this->_contact[i].search(i);
	std::cout << "enter contact index:" << std::endl;
	while (!(std::cin >> index)
		|| (!this->_isFull && index >= this->_nContact)
		|| (this->_isFull && index >= this->N_MAX)) 
	{
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! retry:" << std::endl;
    }
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->_contact[index].displayItem();
}
