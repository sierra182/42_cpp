/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:23:21 by svidot            #+#    #+#             */
/*   Updated: 2024/04/22 22:35:22 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# define N_CT 2

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

        Contact _contact[N_CT]; 
		int		_nContact;            
};

#endif