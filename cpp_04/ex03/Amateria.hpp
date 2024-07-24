/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:03:33 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 12:03:49 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class AMateria
{
    protected:
    [...]
    
    public:
    
    AMateria(std::string const & type);
    [...]
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};