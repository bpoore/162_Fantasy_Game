/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Barbarian.cpp is the Barbarian class implementation file
*********************************************************************/
#include <cstdlib>
#include <iostream>

#include "Character.hpp"
#include "Barbarian.hpp"

Barbarian::Barbarian(std::string n) : Character()
{
	numAttackDice = 2; 
	numAttackSides = 6; 
	numDefenseDice = 2; 
	numDefenseSides = 6;
	armor = 0;
	strengthPoints = 12;
	name = n;
	charType = "Barbarian";
}

Barbarian::~Barbarian() {}

/*********************************************************************
**                Barbarian::attack Function
** Description: This function simulates rolling attack dice.
** Parameters: No input parameters. The function returns a Damage object.
*********************************************************************/	
Damage Barbarian::attack() 
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
	return Damage(attackTotal, false);
}


/*********************************************************************
**                Barbarian::defense Function
** Description: This function simulates rolling defense dice.
** Parameters: No input parameters. The function returns an int representing defense.
*********************************************************************/		
int Barbarian::defense() 
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
