/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:55:39 by svidot            #+#    #+#             */
/*   Updated: 2024/07/15 18:12:00 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie
{
    public:    
              
        Zombie( void );
        ~Zombie( void );
        void    announce( void );
        void    set_name(std::string name);
        
    private:
    
        std::string _name;        
};