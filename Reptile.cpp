/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Reptile.cpp is the Reptile class implementation file
*********************************************************************/
#include <cstdlib>
#include <iostream>

#include "Character.hpp"
#include "Reptile.hpp"

Reptile::Reptile(std::string n) : Character()
{
	numAttackDice = 3; 
	numAttackSides = 6; 		
	numDefenseDice = 1; 
	numDefenseSides = 6;
	armor = 7;
	strengthPoints = 18;
	name = n;
	charType = "Reptile";
}

Reptile::~Reptile() {}

/*********************************************************************
**                Reptile::attack Function
** Description: This function simulates rolling attack dice.
** Parameters: No input parameters. The function returns a Damage object.
*********************************************************************/	
Damage Reptile::attack() 
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
**                Reptile::defense Function
** Description: This function simulates rolling defense dice.
** Parameters: No input parameters. The function returns an int representing defense.
*********************************************************************/		
int Reptile::defense() 
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

