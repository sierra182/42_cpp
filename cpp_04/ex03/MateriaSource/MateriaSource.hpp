/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:18:05 by svidot            #+#    #+#             */
/*   Updated: 2024/08/16 16:43:45 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"
#define INV 4

class MateriaSource : public IMateriaSource
{
    public:
        
        MateriaSource( void );
        MateriaSource( const MateriaSource & src );
        virtual ~MateriaSource();
        MateriaSource & operator=( const MateriaSource & rhs );
        
        virtual void learnMateria( AMateria* );
        virtual AMateria* createMateria( std::string const & type );
		
        AMateria  * const * getInventory( void ) const;
        
	private:
	
		AMateria * inventory[INV];
};