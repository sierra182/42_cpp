/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:42:55 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 13:53:22 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Animal
{
    public:
        
        Animal( void );
        virtual ~Animal( void );
        Animal( const Animal & src );
        Animal & operator=( const Animal & rhs );   
        
        virtual void    makeSound ( void ) const;
        std::string     getType( void ) const;
        
    protected:
        
        std::string type;
};