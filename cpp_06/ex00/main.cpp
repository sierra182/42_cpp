/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:28:49 by seblin            #+#    #+#             */
/*   Updated: 2024/08/02 11:45:17 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"
int	main( int argc, char * argv[] )
{
	(void) argc, (void)argv;
	ScalarConverter::convert("4m2");
	return (0);
}