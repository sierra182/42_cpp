/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:26:21 by seblin            #+#    #+#             */
/*   Updated: 2024/08/13 09:00:50 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <algorithm>

template <typename T>
int easyfind(T cont, int nbr)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), nbr);
	if (it != cont.end())
		return (1);
	return (0);
}
