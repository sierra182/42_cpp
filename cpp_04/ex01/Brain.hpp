/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:01:45 by seblin            #+#    #+#             */
/*   Updated: 2024/07/23 17:35:03 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#undef CNS
#define CNS "\033[34m"
#define RST "\033[0m"

class Brain
{
	public:
		
		Brain( void );
		virtual ~Brain( void );
		Brain( const Brain & src );
		Brain & operator=( const Brain & rhs );				
	
		std::string ideas[100];
};