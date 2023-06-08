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
	_printPrefix() << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	*this = src;
	_printPrefix() << "Copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	_printPrefix() << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	_printPrefix() << "Copy assignment operator called.";
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
		std::cout << " rhs: [ClapTrap](" + rhs._name + ")";
	}
	std::cout << std::endl;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::ostream	&ClapTrap::_printPrefix(void)
{
	return _printPrefix("ClapTrap", _name);
}

std::ostream	&ClapTrap::_printPrefix(const std::string &type, const std::string &name)
{
	std::string	t = type;
	std::string	n = name;

	if (t.empty())
		t = "...";
	if (n.empty())
		n = "...";
	return std::cout << std::left << std::setw(35) << "[" + t + "](" + n + ") ";
}

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
		_printPrefix() << "is dead. can't attack..." << std::endl;
		return ;
	}
	if (!_takeEnergy())
	{
		_printPrefix() << "failed to attack " << target << 
			" because it has no energy!" << std::endl;
		return ;
	}
	_printPrefix() << "attacks " << target << 
		", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_isAlive())
	{
		_printPrefix() << "is dead. can't lose hit points..." << std::endl;
		return ;
	}
	if (_hitPoints < amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	_printPrefix() << "lost " << amount << " hit points. " << 
		"current hit points: " << _hitPoints << std::endl;
	if (0 == _hitPoints)
		_printPrefix() << "has died!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_isAlive())
	{
		_printPrefix() << "is dead. can't gain hit points..." << std::endl;
		return ;
	}
	if (!_takeEnergy())
	{
		_printPrefix() << "failed to repair " << 
			"because it has no energy!" << std::endl;
		return ;
	}

	unsigned int	tmp = _hitPoints;

	_hitPoints += amount;
	if (tmp > _hitPoints)
	{
		_hitPoints = -1;
		_printPrefix() << "gained " << _hitPoints - tmp << " hit points. " << 
			"current hit points: " << _hitPoints << std::endl;
		return ;
	}
	_printPrefix() << "gained " << amount << " hit points. " << 
		"current hit points: " << _hitPoints << std::endl;
}

/* ************************************************************************** */
