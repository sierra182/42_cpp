/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:22:58 by svidot            #+#    #+#             */
/*   Updated: 2024/07/29 15:34:11 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"
#undef CNS
#define CNS "\033[35m"
#define INV 4

class Character : public ICharacter
{
    public:
    
        Character( void );
        virtual ~Character( void );
        Character( const Character & src );
		Character( const std::string & name );
        Character & operator=( const Character & rhs );
                
        virtual std::string const & getName( void ) const;
        virtual void                equip( AMateria * m );
        virtual void                unequip( int idx );
        virtual void                use( int idx, ICharacter& target );    
		
    private: 
		
		AMateria * inventory[INV];
		std::string name;	
}; 