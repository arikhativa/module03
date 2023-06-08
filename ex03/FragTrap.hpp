/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:23:48 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/08 15:58:29 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>
# include <string>

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap( FragTrap const & src );
		explicit FragTrap(const std::string &name);
		~FragTrap();

		FragTrap &		operator=( FragTrap const & rhs );

		void	highFivesGuys(void);

	protected:
		FragTrap();
};

#endif /* ******************************************************** FRAGTRAP_H */
