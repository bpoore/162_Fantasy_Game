/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Goblin.cpp is the Gobline class implementation file
*********************************************************************/
#include <cstdlib>
#include <iostream>

#include "Character.hpp"
#include "Goblin.hpp"

Goblin::Goblin(std::string n) : Character()
{
	numAttackDice = 2; 
	numAttackSides = 6; 
	numDefenseDice = 1; 
	numDefenseSides = 6;
	armor = 3;
	strengthPoints = 8;
	name = n;
	charType = "Goblin";
}

Goblin::~Goblin() {}

/*********************************************************************
**                Barbarian::attack Function
** Description: This function simulates rolling attack dice. This function
** has extra functionality to include an achilles tendon cut to an oppoenent
** if a 12 is rolled.
** Parameters: No input parameters. The function returns a Damage object.
*********************************************************************/	
Damage Goblin::attack() 
{
	int attackTotal = 0;
	for (int i=0; i<numAttackDice; i++)
	{
		int rollVal;
		rollVal = (rand() % numAttackSides + 1);
		//std::cout << "Attack Roll " << i+1 << " = " << rollVal << std::endl;
		attackTotal += rollVal;
	}
	//std::cout << "Attack Total: " << attackTotal << std::endl;

	if (attackTotal == 12)
	{
		this->achillesHeel = true;
	}	 
	return Damage(attackTotal, achillesHeel);
}

/*********************************************************************
**                Goblin::defense Function
** Description: This function simulates rolling defense dice.
** Parameters: No input parameters. The function returns an int representing defense.
*********************************************************************/		
int Goblin::defense() 
{
	int defenseTotal = 0;
	for (int i=0; i<numDefenseDice; i++)
	{
		int rollVal;
		rollVal = (rand()%numDefenseSides + 1);
		//std::cout << "Defense Roll " << i+1 << " = " << rollVal << std::endl;
		defenseTotal += rollVal;
	}
	//std::cout << "Defense Total: " << defenseTotal << std::endl;
	return defenseTotal;
} 



