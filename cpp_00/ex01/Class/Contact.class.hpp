/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:12:02 by svidot            #+#    #+#             */
/*   Updated: 2024/04/23 15:01:27 by seblin           ###   ########.fr       */
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
		void    search(int index) const;
		void	displayItem(void) const;
		
    private:

		static const int	WIDTH_COL = 10;
		
        std::string			_firstname;
        std::string			_lastname;
        std::string			_nickname;
        int					_phoneNumber;
        std::string			_darkestSecret;
		
		void	getEntry(const std::string &str, std::string &entry);
		void	displayEntry(const std::string &entry) const;		
};

#endif