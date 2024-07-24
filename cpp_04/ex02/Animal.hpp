/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:42:55 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 07:38:32 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define CNS "\033[32m"
#define RST "\033[0m"

class Animal
{
    public:
        
        Animal( void );
       	virtual ~Animal( void );
        Animal( const Animal & src );
        Animal & operator=( const Animal & rhs );   
        
        virtual void    makeSound ( void ) const;
        std::string     getType( void ) const;
        void		    setType( std::string );
		
    protected:
        
        std::string type;
};