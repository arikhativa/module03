/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:22:24 by yrabby            #+#    #+#             */
/*   Updated: 2023/09/20 15:54:42 by yrabby           ###   ########.fr       */
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
		virtual ~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );

		void	guardGate(void);

	private:
		ScavTrap();


};

#endif /* ******************************************************** SCAVTRAP_H */
