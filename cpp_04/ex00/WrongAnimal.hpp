/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:42:55 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 14:11:05 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class WrongAnimal
{
    public:
        
        WrongAnimal( void );
        virtual ~WrongAnimal( void );
        WrongAnimal( const WrongAnimal & src );
        WrongAnimal & operator=( const WrongAnimal & rhs );   
        
        void    makeSound ( void ) const;
        std::string     getType( void ) const;
        
    protected:
        
        std::string type;
};