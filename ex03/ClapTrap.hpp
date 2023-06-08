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
		virtual ~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		ClapTrap();
		bool					_isAlive(void);
		bool					_takeEnergy(void);
		virtual std::ostream	&_printPrefix(void);
		std::ostream			&_printPrefix(const std::string &type, const std::string &name);

		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif /* ******************************************************** CLAPTRAP_H */
