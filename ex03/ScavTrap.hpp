/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:22:24 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/08 17:05:08 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>
# include <string>

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap( ScavTrap const & src );
		explicit ScavTrap(const std::string &name);
		virtual ~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );

		void	attack(const std::string& target);
		void	guardGate(void);

	protected:
		ScavTrap();
		std::ostream	&_printPrefix(void);

};

#endif /* ******************************************************** SCAVTRAP_H */
