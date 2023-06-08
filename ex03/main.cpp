
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "DiamondTrap.hpp"

void	simpleTest(void)
{
	std::cout << "Basic Test:" << std::endl ;
	std::cout << std::endl << " ----- DiamondTrap ----- " << std::endl << std::endl;
	{
		DiamondTrap trap("Complex");

		trap.attack("Snake");
		trap.takeDamage(5);
		trap.beRepaired(5);
		trap.highFivesGuys();
		trap.guardGate();
		trap.whoAmI();
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

void	ctorTest(void)
{
	std::cout << "Constructor Test:" << std::endl;
	std::cout << std::endl << " ----- FragTrap ----- " << std::endl << std::endl;
	{
		FragTrap	sp("Yellow");
		FragTrap	sp2("Red");
		FragTrap	sp3(sp);

		sp2 = sp;
		sp = sp;
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

void	defaultCtorTest(void)
{
	// ClapTrap cp;
	// FragTrap cp;
	// ScavTrap cp;
}

void	HPTest(void)
{
	std::cout << "Hit points Test:" << std::endl;
	std::cout << std::endl << " ----- FragTrap ----- " << std::endl << std::endl;
	{
		FragTrap cp("Max");

		cp.beRepaired(-20);
		cp.beRepaired(10);
		cp.beRepaired(10);
	}
	{
		FragTrap sp("McDonalds");

		sp.takeDamage(5);
		sp.beRepaired(1);
		sp.takeDamage(50000);
		sp.takeDamage(1);
		sp.attack("Yoda");
		sp.beRepaired(10);
		sp.highFivesGuys();
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

void	energyTest(void)
{
	std::cout << "Energy Test:" << std::endl;
	std::cout << std::endl << " ----- FragTrap ----- " << std::endl << std::endl;
	{
		FragTrap sp("Guess");

		for (int i = 0; i < 100; ++i)
			sp.attack("Yoda");
		sp.attack("Yoda");
		sp.beRepaired(10);
		sp.highFivesGuys();
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

int main( void )
{
	simpleTest();
	// ctorTest();
	// HPTest();
	// energyTest();

	return 0;
}