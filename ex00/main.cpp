
# include "ClapTrap.hpp"

void	simpleTest(void)
{
	ClapTrap cp("Martin");

	cp.attack("Yoda");
	cp.takeDamage(5);
	cp.beRepaired(5);
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
	cp.takeDamage(10);
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
	std::cout << "Basic Test:" << std::endl << std::endl;
	simpleTest();
	std::cout << std::endl << " ----- " << std::endl << std::endl;

	std::cout << "Constructor Test:" << std::endl << std::endl;
	ctorTest();
	std::cout << std::endl << " ----- " << std::endl << std::endl;

	std::cout << "Hit points Test:" << std::endl << std::endl;
	HPTest();
	std::cout << std::endl << " ----- " << std::endl << std::endl;

	std::cout << "Energy Test:" << std::endl << std::endl;
	energyTest();
	std::cout << std::endl << " ----- " << std::endl << std::endl;

	return 0;
}