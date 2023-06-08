
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
	std::cout << std::endl << " ----- DiamondTrap ----- " << std::endl << std::endl;
	{
		DiamondTrap	trap("Yellow");
		DiamondTrap	trap2("Red");

		std::cout << std::endl << " ----- Copy ctor test ----- " << std::endl << std::endl;
		DiamondTrap	trap3(trap);
		std::cout << std::endl << " ----- Copy ctor test end ----- " << std::endl << std::endl;

		std::cout << std::endl << " ----- Assign test ----- " << std::endl << std::endl;
		trap.whoAmI();
		trap2.whoAmI();
		trap2 = trap;
		trap.whoAmI();
		trap2.whoAmI();
		trap = trap;
		std::cout << std::endl << " ----- Assign test end ----- " << std::endl << std::endl;
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

void	pointerDtorTest(void)
{
	std::cout << "pointerDtorTest Test:" << std::endl;
	std::cout << std::endl << " ----- Create Destroy ----- " << std::endl << std::endl;
	{
		ClapTrap	*trap = new DiamondTrap("Hidden!");
		delete trap;
	}
	std::cout << std::endl << " ----- Use Methods ----- " << std::endl << std::endl;
	{
		ClapTrap	*trap = new DiamondTrap("method");
		trap->attack("Yoda");
		trap->takeDamage(5);
		trap->beRepaired(5);
		delete trap;
	}
	std::cout << std::endl << " ----- Use Methods as FragTrap ----- " << std::endl << std::endl;
	{
		FragTrap	*trap = new DiamondTrap("method");
		trap->attack("Yoda");
		trap->takeDamage(5);
		trap->beRepaired(5);
		trap->highFivesGuys();
		delete trap;
	}
	std::cout << std::endl << " ----- Use Methods as ScavTrap ----- " << std::endl << std::endl;
	{
		ScavTrap	*trap = new DiamondTrap("method");
		trap->attack("Yoda");
		trap->takeDamage(5);
		trap->beRepaired(5);
		trap->guardGate();
		delete trap;
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

void	defaultCtorTest(void)
{
	// ClapTrap trap;
	// FragTrap trap;
	// ScavTrap trap;
	// DiamondTrap trap;
}

void	HPTest(void)
{
	std::cout << "Hit points Test:" << std::endl;
	std::cout << std::endl << " ----- DiamondTrap ----- " << std::endl << std::endl;
	{
		DiamondTrap trap("Max");

		trap.beRepaired(-20);
		trap.beRepaired(10);
		trap.beRepaired(10);
	}
	{
		DiamondTrap trap("McDonalds");

		trap.takeDamage(5);
		trap.beRepaired(1);
		trap.takeDamage(50000);
		trap.takeDamage(1);
		trap.attack("Yoda");
		trap.beRepaired(10);
		trap.highFivesGuys();
		trap.guardGate();

	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

void	energyTest(void)
{
	std::cout << "Energy Test:" << std::endl;
	std::cout << std::endl << " ----- DiamondTrap ----- " << std::endl << std::endl;
	{
		DiamondTrap trap("Guess");

		for (int i = 0; i < 100; ++i)
			trap.attack("Yoda");
		trap.attack("Yoda");
		trap.beRepaired(10);
		trap.highFivesGuys();
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

int main( void )
{
	simpleTest();
	ctorTest();
	pointerDtorTest();
	HPTest();
	energyTest();

	return 0;
}