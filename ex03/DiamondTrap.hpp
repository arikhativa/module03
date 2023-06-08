#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap( DiamondTrap const & src );
		explicit DiamondTrap(const std::string &name);
		~DiamondTrap();

		DiamondTrap &		operator=( DiamondTrap const & rhs );

		using   ScavTrap::attack;
		void    whoAmI(void);
	private:
		DiamondTrap();
		std::ostream	&_printPrefix(void);

		std::string _name;
};

#endif /* ***************************************************** DIAMONDTRAP_H */
