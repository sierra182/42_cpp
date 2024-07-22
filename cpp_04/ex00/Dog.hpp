/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:52:57 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 12:59:52 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : Animal
{
    public:
        
        Dog( void );
        virtual ~Dog( void );
        Dog( const Dog & src );
        Dog & operator=( const Dog & rhs );

    private:
};
