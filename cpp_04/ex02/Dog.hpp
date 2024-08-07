/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:52:57 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 09:43:25 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

#undef CNS
#define CNS "\033[34m"

class Dog : public AAnimal
{
	Brain * brain;
	
    public:
	
        Dog( void );
    	virtual ~Dog( void );
        Dog( const Dog & src );
        Dog & operator=( const Dog & rhs );
		
        virtual void makeSound ( void ) const;
		Brain & getBrain( void ) const;		
};
