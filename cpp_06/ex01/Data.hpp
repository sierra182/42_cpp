/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:26:12 by seblin            #+#    #+#             */
/*   Updated: 2024/08/04 18:30:34 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

struct Data
{
	Data( void );
	virtual ~Data( void );
	Data( const Data & src );
	Data & operator=( const Data & rhs );		
};