/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:55:39 by svidot            #+#    #+#             */
/*   Updated: 2024/07/15 16:38:11 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie
{
    public:    
        
        Zombie( std::string name );
        ~Zombie( void );
        void announce( void ); 
        
    private:
    
        Zombie( void );
        std::string _name;        
};