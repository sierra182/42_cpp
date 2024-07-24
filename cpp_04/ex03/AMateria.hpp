/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:03:33 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 14:39:17 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>

#undef CNS
#define CNS "\033[36m"
#define RST "\033[0m"

class AMateria
{
    protected:
    // [...]
    
    public:
    
        AMateria( void );
        virtual ~AMateria( void );
        AMateria( const AMateria & );
        AMateria & operator=( const AMateria & rhs );
        

    AMateria(std::string const & type);
    // [...]
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone( void ) const = 0;
    virtual void use(ICharacter& target);
};