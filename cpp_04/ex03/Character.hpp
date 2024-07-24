/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:22:58 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 17:07:54 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"

#undef CNS
#define CNS "\033[35m"

class Character : public ICharacter
{
    public:
    
        Character( void );
        virtual ~Character( void );
        Character( const Character & src );
        Character & operator=( const Character & rhs );
        
    private: //?
        
        virtual std::string const & getName() const;
        virtual void                equip(AMateria* m);
        virtual void                unequip(int idx);
        virtual void                use(int idx, ICharacter& target);        
}; 