/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:12:02 by svidot            #+#    #+#             */
/*   Updated: 2024/04/22 16:34:09 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <ostream>

class Contact
{
    public:
        
        Contact(void);
        Contact(Contact const &src);
        Contact &operator=(Contact const &rhs);
        virtual ~Contact(void);
    
    private:

        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
};

#endif