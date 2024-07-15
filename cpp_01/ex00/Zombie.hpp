/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:55:39 by svidot            #+#    #+#             */
/*   Updated: 2024/07/15 15:21:07 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//! canoniq
class Zombie
{
    public:
    
        Zombie( void );
        Zombie( std::string name );
        ~Zombie( void );
        
    private:
    
        std::string _name;
        
        void announce( void ); 
};