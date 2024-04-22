/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:03:38 by svidot            #+#    #+#             */
/*   Updated: 2024/04/22 15:23:43 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>

PhoneBook::PhoneBook(void) : _jacque(42)
{    
    return ;
}

PhoneBook::PhoneBook(PhoneBook const & src)
{
    *this = src;
    return ;
}

PhoneBook &PhoneBook::operator=(PhoneBook const & rhs)
{    
    this->_jacque = rhs._jacque;   
    return (*this);
}

PhoneBook::~PhoneBook(void)
{  
    return ;
}
