/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:22:29 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/08 15:36:40 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name)
{
	this->_type = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	_printPrefix() << "Constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap & src )
	: ClapTrap(src)
{
	*this = src;
	_printPrefix() << "Copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	_printPrefix() << "Destructor called" << std::endl;
	this->_type = "ClapTrap";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
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

void    FragTrap::highFivesGuys() {
	if (!_isAlive())
	{
		_printPrefix() << "is dead. can't  high five..." << std::endl;
		return ;
	}
	if (!_takeEnergy())
	{
		_printPrefix() << "failed to high five because it has no energy!" << std::endl;
		return ;
	}
	_printPrefix() << "high five! 🙏" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */