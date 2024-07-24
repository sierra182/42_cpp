/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:16:30 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 14:38:42 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

#undef CNS
#define CNS "\033[31m"

class Ice : public AMateria
{
    public:
        Ice( void );
        virtual ~Ice( void );
        Ice( const Ice & src );
        Ice & operator=( const Ice & rhs);
      
        virtual AMateria* clone( void ) const;
};