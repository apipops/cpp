#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap jim( "Jim" );
    ScavTrap jim2(jim);
    

    jim.attack( "Claude" );
    jim.takeDamage( 10 );
    jim.beRepaired( 10 );
    jim.guardGate();

    return 0;
}