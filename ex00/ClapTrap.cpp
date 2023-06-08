#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor(" << name << ") called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "Copy constructor(" << src._name << ") called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor(" << _name << ") called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "Copy assignment operator (" << rhs._name << ") called" << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool	ClapTrap::_takeEnergy(void)
{
	if (0 == _energyPoints)
		return false;
	--_energyPoints;
	return true;
}

bool	ClapTrap::_isAlive(void)
{
	return (_hitPoints);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!_isAlive())
	{
		std::cout << "ClapTrap(" << _name << ") is dead. can't attack..." << std::endl;
		return ;
	}
	if (!_takeEnergy())
	{
		std::cout << "ClapTrap(" << _name << ") failed to attack " << target << 
			" because it has no energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap(" << _name << ") attacks " << target << 
		", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_isAlive())
	{
		std::cout << "ClapTrap(" << _name << ") is dead. can't lose hit points..." << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap(" << _name << ") lost " << amount << " hit points. " << 
		"current hit points: " << _hitPoints << std::endl;
	if (0 == _hitPoints)
		std::cout << "ClapTrap(" << _name << ") has died!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_isAlive())
	{
		std::cout << "ClapTrap(" << _name << ") is dead. can't gain hit points..." << std::endl;
		return ;
	}
	if (!_takeEnergy())
	{
		std::cout << "ClapTrap(" << _name << ") failed to repair " << 
			"because it has no energy!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	std::cout << "ClapTrap(" << _name << ") gained " << amount << " hit points. " << 
		"current hit points: " << _hitPoints << std::endl;
}

/* ************************************************************************** */
