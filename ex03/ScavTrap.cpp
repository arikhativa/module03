/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:22:29 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/08 16:36:10 by yrabby           ###   ########.fr       */
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
	this->_type = "ScavTrap";
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
	this->_type = "ScavTrap";
	_printPrefix() << "Destructor called" << std::endl;
	this->_type = "ClapTrap";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	_printPrefix() << "Copy assignment operator called.";
	if ( this != &rhs )
	{
		this->_type = rhs._type;
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		std::cout << " rhs: [" + rhs._type + "](" + rhs._name + ")";
	}
	std::cout << std::endl;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScavTrap::attack(const std::string& target)
{
	std::string tmp = this->_type;
	this->_type = "ScavTrap";
	ClapTrap::attack(target);
	this->_type = tmp;
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