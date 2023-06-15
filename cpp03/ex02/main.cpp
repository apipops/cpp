#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
    ScavTrap jim( "Jim" );
    FragTrap bob( "Bob" );
    

    jim.attack( "Claude" );
    jim.takeDamage( 10 );
    jim.beRepaired( 10 );
    jim.guardGate();

    bob.attack( "Germaine" );
    bob.takeDamage( 10 );
    bob.beRepaired( 10 );
    bob.highFiveGuys();

    return 0;
}