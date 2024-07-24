/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:19:34 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 16:05:01 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

#undef CNS
#define CNS "\033[31m"

class Cure : public AMateria
{
    public:

        Cure(std::string const & type);
        Cure( void );
        virtual ~Cure( void );
        Cure( const Cure & src );
        Cure & operator=( const Cure & rhs);
      
        virtual AMateria* clone( void ) const;
};