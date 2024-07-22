/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:49:30 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 12:59:43 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : Animal
{
    public:
        
        Cat( void );
        virtual ~Cat ( void );
        Cat( const Cat & src );
        Cat & operator=( const Cat & rhs );
};
