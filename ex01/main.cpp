
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

void	simpleTest(void)
{
	std::cout << "Basic Test:" << std::endl ;
	std::cout << std::endl << " ----- ClapTrap ----- " << std::endl << std::endl;
	{
		ClapTrap cp("Martin");

		cp.attack("Yoda 1");
		cp.takeDamage(5);
		cp.beRepaired(5);
	}
	std::cout << std::endl << " ----- ScavTrap ----- " << std::endl << std::endl;
	{
		ScavTrap sp("Bob");

		sp.attack("Yoda 2");
		sp.takeDamage(5);
		sp.beRepaired(5);
		sp.guardGate();
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

void	ctorTest(void)
{
	ClapTrap cp("Josh");
	ClapTrap cp2(cp);
	ClapTrap cp3("Timmy");

	cp2 = cp3;
}

void	defaultCtorTest(void)
{
	// ClapTrap cp;
}

void	HPTest(void)
{
	ClapTrap cp("McDonalds");

	cp.takeDamage(5);
	cp.beRepaired(1);
	cp.takeDamage(5);
	cp.takeDamage(1);
	cp.attack("Yoda");
	cp.beRepaired(10);
}

void	energyTest(void)
{
	ClapTrap cp("Guess");

	cp.attack("Yoda");
	cp.attack("Dude");
	cp.attack("Yona");
	cp.attack("Glover");
	cp.attack("Papi");
	cp.attack("Tiffany");
	cp.attack("Lulu");
	cp.attack("Bliss");
	cp.attack("Age Of Empires");
	cp.attack("Cub3d");
	cp.attack("Cub3DD");
	cp.attack("Cub2D");
	cp.beRepaired(10);
}

int main( void )
{
	simpleTest();
	// std::cout << "Constructor Test:" << std::endl << std::endl;
	// ctorTest();
	// std::cout << std::endl << " ----- " << std::endl << std::endl;

	// std::cout << "Hit points Test:" << std::endl << std::endl;
	// HPTest();
	// std::cout << std::endl << " ----- " << std::endl << std::endl;

	// std::cout << "Energy Test:" << std::endl << std::endl;
	// energyTest();
	// std::cout << std::endl << " ----- " << std::endl << std::endl;

	return 0;
}