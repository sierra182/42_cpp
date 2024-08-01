/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:46:45 by seblin            #+#    #+#             */
/*   Updated: 2024/08/01 18:15:19 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>


class ScalarConverter
{
	ScalarConverter( void );
	
	public:

		virtual ~ScalarConverter( void );
		ScalarConverter( const ScalarConverter & src );
		ScalarConverter & operator=( const ScalarConverter & rhs );

		static void convert( std::string const & entry ); 
};
