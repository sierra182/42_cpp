/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:16:30 by svidot            #+#    #+#             */
/*   Updated: 2024/08/17 08:50:17 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <istream>

#undef CNS
#define CNS "\033[31m"

class Ice : public AMateria
{
    Ice & operator=( const Ice & rhs);
	
    public:
    
        Ice( void );
        virtual ~Ice( void );
        Ice( const Ice & src );
      
        virtual AMateria* clone( void ) const;
		virtual void use(ICharacter& target) const;    	
};