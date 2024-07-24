/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:16:30 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 16:04:49 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <istream>

#undef CNS
#define CNS "\033[31m"

class Ice : public AMateria
{
    public:
    
        Ice(std::string const & type);
        Ice( void );
        virtual ~Ice( void );
        Ice( const Ice & src );
        Ice & operator=( const Ice & rhs);
      
        virtual AMateria* clone( void ) const;
        
};