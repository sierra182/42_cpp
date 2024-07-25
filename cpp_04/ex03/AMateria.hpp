/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:03:33 by svidot            #+#    #+#             */
/*   Updated: 2024/07/25 15:20:50 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>
#include "ICharacter.hpp"

#undef CNS
#define CNS "\033[36m"
#define RST "\033[0m"

class AMateria
{
    protected:
    // [...] //? type
    	AMateria( void );
    	const std::string type;
    
    public:
    
        AMateria( std::string const & type );// pub?
        // [...] //? cano
        virtual ~AMateria( void );
        AMateria( const AMateria & );
        AMateria & operator=( const AMateria & rhs );
        
   		std::string const & getType() const; // Returns the materia type

    	virtual AMateria* clone( void ) const = 0;    
    	virtual void use( ICharacter& target ) {};//? {}
};