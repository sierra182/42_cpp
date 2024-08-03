/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:46:45 by seblin            #+#    #+#             */
/*   Updated: 2024/08/03 17:51:26 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>


class ScalarConverter
{
	ScalarConverter( void );
	static bool isSpecialCase( std::string entry );
	static void specialCase( std::string const & entry );
	static void displayAllImpossible( void );
	static void floatCase( std::string entry );
	static void doubleCase( std::string entry );
	static void charCase( std::string entry );
	static void intCase( std::string entry );
	
	public:

		virtual ~ScalarConverter( void );
		ScalarConverter( const ScalarConverter & src );
		ScalarConverter & operator=( const ScalarConverter & rhs );

		static void convert( std::string const & entry ); 
};
