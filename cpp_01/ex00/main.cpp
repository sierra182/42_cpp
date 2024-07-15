#include "Zombie.hpp"

Zombie* newZombie( std::string name );
int main( void )
{
    Zombie zombie("test");
    Zombie *zombies = newZombie("moncul");
    delete(zombies);
}