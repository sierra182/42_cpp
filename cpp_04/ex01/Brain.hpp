/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:01:45 by seblin            #+#    #+#             */
/*   Updated: 2024/07/24 07:14:53 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#undef CNS
#define CNS "\033[36m"
#define RST "\033[0m"
#define BR 100

class Brain
{
	public:
		
		Brain( void );
		virtual ~Brain( void );
		Brain( const Brain & src );
		Brain & operator=( const Brain & rhs );				
	
		std::string ideas[BR];
};