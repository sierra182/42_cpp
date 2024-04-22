/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:23:21 by svidot            #+#    #+#             */
/*   Updated: 2024/04/22 16:52:34 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class PhoneBook
{
    public:
    
        PhoneBook(void);
        PhoneBook(PhoneBook const &src);
        PhoneBook &operator=(PhoneBook const &rhs);
        virtual ~PhoneBook(void);
        
        void    add(void);
        void    search(void);
        
    private: 

        Contact _contact[8];              
};

#endif