/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:34:30 by seblin            #+#    #+#             */
/*   Updated: 2024/07/28 17:54:29 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include<ostream>

class Bureaucrat
{
	const std::string	_name;
	int 				_grade;
	
	public:

		const std::string &	getName( void ) const;
		int  				getGrade( void ) const;

};