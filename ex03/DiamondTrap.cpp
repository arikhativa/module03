/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:56:42 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/08 16:34:10 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : 
	ClapTrap(name + "_clap_name"),
	ScavTrap(this->ClapTrap::_name),
	FragTrap(this->ClapTrap::_name),
	_name(name)
{
	this->_type = "DiamondTrap";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	_printPrefix() << "Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : 
	ClapTrap(src.ClapTrap::_name),
	ScavTrap(src.ClapTrap::_name),
	FragTrap(src.ClapTrap::_name),
	_name(src._name)
{
	*this = src;
	_printPrefix() << "Copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	_printPrefix() << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
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

std::ostream	&DiamondTrap::_printPrefix(void)
{
	return ClapTrap::_printPrefix(this->_type, this->_name);
}


void	DiamondTrap::whoAmI(void)
{
	_printPrefix() << "My name is " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << std::endl;
}


/* ************************************************************************** */