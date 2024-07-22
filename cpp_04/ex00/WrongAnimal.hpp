/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:42:55 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 15:50:50 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#undef CNS
#define CNS "\033[36m"
#define RST "\033[0m"

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