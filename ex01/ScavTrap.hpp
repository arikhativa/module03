/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:22:24 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/08 13:23:26 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( ScavTrap const & src );
		explicit ScavTrap(const std::string &name);
		~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );

		// void	attack(const std::string& target);
		void	guardGate();

	private:
		ScavTrap();


};

#endif /* ******************************************************** SCAVTRAP_H */
