/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:03:38 by svidot            #+#    #+#             */
/*   Updated: 2024/04/24 10:29:29 by seblin           ###   ########.fr       */
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
// int	ft_isoverflow(char *str)
// {
// 	long	nbr;
// 	int		isneg;

// 	nbr = 0;
// 	isneg = 0;
// 	if (*str == '-' && ++isneg)
// 		str++;
// 	else if (*str == '+')
// 		str++;
// 	while (*str)
// 	{
// 		nbr = nbr * 10 + *str++ - 48;
// 		if (nbr - isneg > INT_MAX)
// 			return (1);
// 	}
// 	return (0);
// }

// int	ft_isoverflow(const std::string &str)
// {
// 	long	nbr;
// 	int		isneg;

// 	nbr = 0;
// 	isneg = 0;
// 	if (*str == '-' && ++isneg)
// 		str++;
// 	else if (*str == '+')
// 		str++;
// 	while (*str)
// 	{
// 		nbr = nbr * 10 + *str++ - 48;
// 		if (nbr - isneg > INT_MAX)
// 			return (1);
// 	}
// 	return (0);
// }

// #include <sstream>
// unsigned int	stoui(const std::string &str )
// {		
//     std::istringstream iss(str);
//     unsigned int num;

//     iss >> num;
//     if (iss.fail() || !iss.eof())   // Vérifiez si la conversion a échoué ou si la chaîne n'a pas été complètement consommée    	
// 		throw (std::invalid_argument("Erreur de conversion ou données en excès."));
// 	return (num)
// }

void	parse_int()
{
	
}
void    PhoneBook::search() const
{
	unsigned int	index;	
	int				max_contact;
	
	if (!this->_nContact && !this->_isFull)
	{
		std::cout << std::endl << " No friends! 😭, choose ADD..." << std::endl;
		return ;
	}
	max_contact = this->_isFull ? this->N_MAX : this->_nContact;
	for (int i = 0; i < max_contact; i++)
    	this->_contact[i].search(i);
	std::cout  << std::endl << "\033[36m Enter contact Index:\033[0m " << std::endl;
	while (!(std::cin >> index)
		|| (!this->_isFull && index >= this->_nContact)
		|| (this->_isFull && index >= this->N_MAX)) 
	{
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " ❌ \033[31mInvalid input! retry:\033[0m" << std::endl;
    }
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->_contact[index].displayItem();
}
