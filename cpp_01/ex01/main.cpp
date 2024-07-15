#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name );

int main( void )
{
    int N = 10;
    Zombie* zombie = zombieHorde(N, "seb");
    for (int i = 0; i < N; i++)
        zombie[i].announce();
    delete[] zombie;
}