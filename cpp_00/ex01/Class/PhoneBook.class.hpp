/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:23:21 by svidot            #+#    #+#             */
/*   Updated: 2024/04/24 13:54:15 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>

class PhoneBook
{
    public:
    
        PhoneBook(void);
        PhoneBook(PhoneBook const &src);
        PhoneBook &operator=(PhoneBook const &rhs);
        virtual ~PhoneBook(void);

        void    add(void);
        void    search(void) const;

    private: 
		
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
		 
		static const unsigned int	N_MAX = 8;
		unsigned int				_nContact;
		bool						_isFull;
        Contact 					_contact[N_MAX]; 
};

#endif