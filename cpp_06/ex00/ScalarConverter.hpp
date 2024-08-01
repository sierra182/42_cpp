/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:46:45 by seblin            #+#    #+#             */
/*   Updated: 2024/08/01 16:50:23 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class ScalarConverter
{
	public:
	
		ScalarConverter( void );
		virtual ~ScalarConverter( void );
		ScalarConverter( const ScalarConverter & src );
		ScalarConverter & operator=( const ScalarConverter & rhs );
};