/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:55:39 by svidot            #+#    #+#             */
/*   Updated: 2024/07/15 14:57:30 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>>
//! canoniq
class Zombie
{
    public:
        Zombie( void );
        ~Zombie( void );
        
    private:
        std::string name;
        
        void announce( void ); 
};