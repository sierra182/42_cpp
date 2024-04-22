/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:12:02 by svidot            #+#    #+#             */
/*   Updated: 2024/04/22 22:05:03 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>

class Contact
{
    public:
        
        Contact(void);
        Contact(Contact const &src);
        Contact &operator=(Contact const &rhs);
        virtual ~Contact(void);
		
        void    add(void);

    private:

        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        int			_phoneNumber;
        std::string _darkestSecret;
		
		void	getEntry(const std::string &str, std::string &entry);
};

#endif