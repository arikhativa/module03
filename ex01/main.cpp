
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
	std::cout << "Constructor Test:" << std::endl;
	std::cout << std::endl << " ----- ClapTrap ----- " << std::endl << std::endl;
	{
		ClapTrap	obj("Yellow");
		ClapTrap	obj2("Red");
		ClapTrap	obj3(obj);

		obj2 = obj;
	}
	std::cout << std::endl << " ----- ScavTrap ----- " << std::endl << std::endl;
	{
		ScavTrap	sp("Yellow");
		ScavTrap	sp2("Red");
		ScavTrap	sp3(sp);

		sp2 = sp;
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

void	defaultCtorTest(void)
{
	// ClapTrap cp;
	// ScavTrap cp;
}

void	HPTest(void)
{
	std::cout << "Hit points Test:" << std::endl;
	std::cout << std::endl << " ----- ClapTrap ----- " << std::endl << std::endl;
	{
		ClapTrap cp("Max");

		cp.beRepaired(-20);
		cp.beRepaired(10);
		cp.beRepaired(10);
	}
	std::cout << std::endl << " ----- ScavTrap ----- " << std::endl << std::endl;
	{
		ScavTrap sp("McDonalds");

		sp.takeDamage(5);
		sp.beRepaired(1);
		sp.takeDamage(50000);
		sp.takeDamage(1);
		sp.attack("Yoda");
		sp.beRepaired(10);
		sp.guardGate();
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

void	energyTest(void)
{
	std::cout << "Energy Test:" << std::endl << std::endl;
	{
		ScavTrap sp("Guess");

		for (int i = 0; i < 50; ++i)
			sp.attack("Yoda");
		sp.attack("Yoda");
		sp.beRepaired(10);
		sp.guardGate();
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

void	pointerDtorTest(void)
{
	std::cout << "Constructor Test:" << std::endl;
	std::cout << std::endl << " ----- ScavTrap ----- " << std::endl << std::endl;
	{
		ClapTrap	*trap = new ScavTrap("Hidden!");
		delete trap;
	}
	std::cout << std::endl << " -------- End  ------ " << std::endl << std::endl;
}

int main( void )
{
	simpleTest();
	ctorTest();
	HPTest();
	energyTest();
	pointerDtorTest();
	return 0;
}