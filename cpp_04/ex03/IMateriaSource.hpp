/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:20:20 by svidot            #+#    #+#             */
/*   Updated: 2024/07/26 09:56:53 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class IMateriaSource
{
    public:
		
        virtual ~IMateriaSource() {};
        virtual void learnMateria( AMateria* ) = 0;
        virtual AMateria* createMateria( std::string const & type ) = 0;
};