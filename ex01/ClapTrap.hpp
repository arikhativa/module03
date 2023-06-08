#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <iomanip>

class ClapTrap
{
	public:
		explicit ClapTrap(const std::string &name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		ClapTrap();
		bool			_takeEnergy(void);
		bool			_isAlive(void);
		std::ostream	&_printPrefix(void);

		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		std::string		_type;
};

#endif /* ******************************************************** CLAPTRAP_H */
