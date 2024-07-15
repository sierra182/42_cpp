#include "Zombie.hpp"
#include <iostream>

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main( void )
{
    Zombie *zombie = newZombie("Heapman");
    zombie->announce();
    delete zombie;
    randomChump("Stackman");
}