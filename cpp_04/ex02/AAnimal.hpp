/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:42:55 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 09:42:20 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define CNS "\033[32m"
#define RST "\033[0m"

class AAnimal
{
    public:
        
        AAnimal( void );
       	virtual ~AAnimal( void );
        AAnimal( const AAnimal & src );
        AAnimal & operator=( const AAnimal & rhs );   
        
        virtual void    makeSound ( void ) const = 0;
        std::string     getType( void ) const;
        void		    setType( std::string );
		
    protected:
        
        std::string type;
};