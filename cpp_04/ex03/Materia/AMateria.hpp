/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:03:33 by svidot            #+#    #+#             */
/*   Updated: 2024/08/16 23:04:43 by seblin           ###   ########.fr       */
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
    	AMateria( void );
    	const std::string type;
        AMateria & operator=( const AMateria & rhs );
    
    public:
    
        AMateria( std::string const & type );
        virtual ~AMateria( void );
        AMateria( const AMateria & );
        
   		std::string const & getType() const;

    	virtual AMateria* clone( void ) const = 0;    
    	virtual void use( ICharacter & ) const {};
};