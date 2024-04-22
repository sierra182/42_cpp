/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:12:02 by svidot            #+#    #+#             */
/*   Updated: 2024/04/22 16:21:27 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact
{
    public:
        
        Contact(void);
        Contact(Contact const &src);
        Contact &operator=(Contact const &rhs);
        virtual ~Contact(void);
};

#endif