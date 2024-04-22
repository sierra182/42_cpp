/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:57:14 by svidot            #+#    #+#             */
/*   Updated: 2024/04/22 16:24:04 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

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
