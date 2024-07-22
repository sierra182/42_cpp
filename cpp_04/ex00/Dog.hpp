/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:52:57 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 15:25:58 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

#undef CNS
#define CNS "\033[34m"

class Dog : public Animal
{
    public:
        
        Dog( void );
        virtual ~Dog( void );
        Dog( const Dog & src );
        Dog & operator=( const Dog & rhs );

        void makeSound ( void ) const; 
};
