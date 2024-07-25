/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:19:34 by svidot            #+#    #+#             */
/*   Updated: 2024/07/25 14:10:03 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

#undef CNS
#define CNS "\033[31m"

class Cure : public AMateria
{
    public:

	    Cure( void );
        Cure(std::string const & type);
        virtual ~Cure( void );
        Cure( const Cure & src );
        Cure & operator=( const Cure & rhs);
      
        virtual AMateria* clone( void ) const;
		virtual void use(ICharacter& target);//? const ?
};