/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:22:58 by svidot            #+#    #+#             */
/*   Updated: 2024/07/26 16:50:05 by seblin           ###   ########.fr       */
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
                
        virtual std::string const & getName( void ) const; //? acces ?
        virtual void                equip( AMateria * m );
        virtual void                unequip( int idx );
        virtual void                use( int idx, ICharacter& target );    
		
    private: 
		
		AMateria * inventory[INV];
		std::string name;	
}; 