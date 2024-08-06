/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:51:53 by seblin            #+#    #+#             */
/*   Updated: 2024/08/06 17:21:14 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main (void )
{
	#define LEN 5
	std::string arr[LEN] = {"salut", "ca", "va", "?"};
	iter(arr, LEN, myfunct);
	return (0);
}