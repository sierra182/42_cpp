/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:19:34 by svidot            #+#    #+#             */
/*   Updated: 2024/08/16 23:01:00 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

#undef CNS
#define CNS "\033[31m"

class Cure : public AMateria
{
    Cure & operator=( const Cure & rhs);
	
    public:

	    Cure( void );
        Cure(std::string const & type);
        virtual ~Cure( void );
        Cure( const Cure & src );
      
        virtual AMateria* clone( void ) const;
		virtual void use(ICharacter& target) const;
};