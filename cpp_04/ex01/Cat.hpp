/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:49:30 by svidot            #+#    #+#             */
/*   Updated: 2024/07/23 22:54:58 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

#undef CNS
#define CNS "\033[35m"

class Cat : public Animal
{
	Brain * brain;
	
    public:
        
        Cat( void );
        virtual ~Cat ( void );
        Cat( const Cat & src );
        Cat & operator=( const Cat & rhs );

        virtual void makeSound ( void ) const;	
		Brain & getBrain( void ) const;	
};
