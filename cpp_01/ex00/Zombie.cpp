/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:48:36 by svidot            #+#    #+#             */
/*   Updated: 2024/07/15 15:39:17 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
  
}

Zombie::Zombie( std::string name ) : _name(name)
{
    //  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
     Zombie::announce();
}

Zombie::~Zombie( void )
{
    std::cout << this->_name << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}