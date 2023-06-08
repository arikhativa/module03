/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:22:29 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/08 16:50:33 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	_printPrefix() << "Constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src )
	: ClapTrap(src)
{
	*this = src;
	_printPrefix() << "Copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	_printPrefix() << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	_printPrefix() << "Copy assignment operator called.";
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		std::cout << " rhs: [ScavTrap](" + rhs._name + ")";
	}
	std::cout << std::endl;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::ostream	&ScavTrap::_printPrefix(void)
{
	return ClapTrap::_printPrefix("ScavTrap", this->_name);
}


void	ScavTrap::attack(const std::string& target)
{
	if (!_isAlive())
	{
		ScavTrap::_printPrefix() << "is dead. can't attack..." << std::endl;
		return ;
	}
	if (!_takeEnergy())
	{
		ScavTrap::_printPrefix() << "failed to attack " << target << 
			" because it has no energy!" << std::endl;
		return ;
	}
	ScavTrap::_printPrefix() << "attacks " << target << 
		", causing " << _attackDamage << " points of damage!" << std::endl;
}

void    ScavTrap::guardGate() {
	if (!_isAlive())
	{
		_printPrefix() << "is dead. can't  activated Gate keeper mode...." << std::endl;
		return ;
	}
	if (!_takeEnergy())
	{
		_printPrefix() << "failed to activated Gate keeper mode. because it has no energy!" << std::endl;
		return ;
	}
	_printPrefix() << "activated Gate keeper mode." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */