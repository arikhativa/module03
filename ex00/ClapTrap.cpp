#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(const std::string &name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap ctor" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap dtor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ClapTrap::attack(const std::string& target)
{
	if (0 == _energyPoints)
	{
		std::cout << "ClapTrap failed to attack " << target << 
			" because it has no energy!" << std::endl;
		return ;
	}
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " attacks " << target << 
		", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (0 == _hitPoints)
	{
		std::cout << "ClapTrap is dead, can't lose hit points..."<< std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap lost " << amount << " hit points. " << 
		"current hit points: " << _hitPoints << std::endl;
	if (0 == _hitPoints)
		std::cout << "ClapTrap has died!"<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (0 == _energyPoints)
	{
		std::cout << "ClapTrap failed to repair " << 
			"because it has no energy!" << std::endl;
		return ;
	}
	--_energyPoints;
	_hitPoints += amount;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */