/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Shadow.cpp is the Shadow class implementation file
*********************************************************************/
#include <cstdlib>
#include <iostream>

#include "Character.hpp"
#include "Shadow.hpp"

Shadow::Shadow(std::string n) : Character()
{
	numAttackDice = 2; 
	numAttackSides = 10; 
	numDefenseDice = 1; 
	numDefenseSides = 6;
	armor = 0;
	strengthPoints = 12;
	name = n;
	charType = "Shadow";
}

Shadow::~Shadow() {}

/*********************************************************************
**                Shadow::attack Function
** Description: This function simulates rolling attack dice.
** Parameters: No input parameters. The function returns a Damage object.
*********************************************************************/	
Damage Shadow::attack() 
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
**                Shadow::defense Function
** Description: This function simulates rolling defense dice. Includes functionality
** to determine if the Shadow was present at the time of the attack represented by randomly
** determining if present is 0 or 1. If 0, the value is treated as false for present and a 
** value of 0 is returned to be dealt with in battle as a special scenario.
** Parameters: No input parameters. The function returns an int representing defense.
*********************************************************************/	
int Shadow::defense()
{
	int presentVal = rand() % 2; // Will randomly be 0 or 1

	if (!presentVal) // If value is 0, Shadow was not present
	{
		return presentVal; // Return 0
	}

	else
	{
		int defenseTotal = 0;
		for (int i=0; i<numDefenseDice; i++)
		{
			int rollVal;
			rollVal = (rand()%numDefenseSides + 1);
			defenseTotal += rollVal;
		}
		return defenseTotal;
	}
} 


