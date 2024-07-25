/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:11:27 by svidot            #+#    #+#             */
/*   Updated: 2024/07/25 17:16:26 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>

class AMateria;

class ICharacter
{
    public:
    
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip( AMateria * m ) = 0;
        virtual void unequip( int idx ) = 0;
        virtual void use( int idx, ICharacter& target ) = 0;
};