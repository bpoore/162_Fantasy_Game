/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: BlueMen.cpp is the BlueMen class implementation file
*********************************************************************/
#include <cstdlib>
#include <iostream>

#include "Character.hpp"
#include "BlueMen.hpp"

BlueMen::BlueMen(std::string n) : Character()
{
	numAttackDice = 2; 
	numAttackSides = 10; 
	numDefenseDice = 3; 
	numDefenseSides = 6;
	armor = 3;
	strengthPoints = 12;
	name = n;
	charType = "BlueMen";
}

BlueMen::~BlueMen() {}

/*********************************************************************
**                BlueMen::attack Function
** Description: This function simulates rolling attack dice.
** Parameters: No input parameters. The function returns a Damage object.
*********************************************************************/	
Damage BlueMen::attack() 
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
**                BlueMen::defense Function
** Description: This function simulates rolling defense dice.
** Parameters: No input parameters. The function returns an int representing defense.
*********************************************************************/		
int BlueMen::defense() 
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

