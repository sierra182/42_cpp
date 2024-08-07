/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:49:30 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 16:08:21 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

#undef CNS
#define CNS "\033[35m"

class Cat : public Animal
{
    public:
        
        Cat( void );
        virtual ~Cat ( void );
        Cat( const Cat & src );
        Cat & operator=( const Cat & rhs );

        virtual void makeSound ( void ) const;
};
