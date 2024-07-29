/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:49:22 by seblin            #+#    #+#             */
/*   Updated: 2024/07/29 17:18:36 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>

class Form
{	
	Form( void );
	
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeForSign;
	const int			_gradeForExec;

	public:
		
		virtual ~Form( void );
		Form( const Form & src);
		Form & operator=( const Form & rhs );

		const std::string &	getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getGradeForSign( void ) const;
		int 	 			getGradeForExec( void ) const;		
};

std::ostream & operator<<( std::ostream & lhs, const Form & rhs ); 