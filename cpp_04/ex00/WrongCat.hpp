/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:49:30 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 15:25:09 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

#undef CNS
#define CNS "\033[33m"

class WrongCat : public WrongAnimal
{
    public:
        
        WrongCat( void );
        virtual ~WrongCat ( void );
        WrongCat( const WrongCat & src );
        WrongCat & operator=( const WrongCat & rhs );

        void makeSound ( void ) const;
};
