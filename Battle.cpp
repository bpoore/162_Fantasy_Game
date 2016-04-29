/*********************************************************************
** Author: Elizabeth Poore
** Date: May 23, 2015
** Description: Battle.cpp is the Battle fucntion implementation file
*********************************************************************/	
#include <iostream>

#include "Battle.hpp"

/*********************************************************************
**               Battle Function
** Description: This function performs the task of a battle! 
** Parameters: This fucntion has input parameters of two pointer to Character
** objects. The funciton doesn't return a value, though the updated
** Character objects are used throughout the tournament function.
*********************************************************************/	
void battle(Character *fighter1, Character *fighter2)
{

		int fighter1InitialStrength = fighter1->getStrengthPoints();
		int fighter2InitialStrength = fighter2->getStrengthPoints();

		Character *winner = NULL;

		std::cout << fighter1->getName() << " and " << fighter2->getName() << " are now fighting to the death." << std::endl;
		while (fighter1->getInPlay() && fighter2->getInPlay())
		{
			//std::cout << fighter1->getName() << " has attacked " << fighter2->getName() << '.' << std::endl;
			Damage aDamage = fighter1->attack();
			fighter2->calcNewStrength(aDamage.getAttackTotal(), aDamage.getAchilles());
			if (!fighter2->getInPlay())
			{
				break;
			}
			//std::cout << fighter2->getName() << "'s current strength points =  " << fighter2->getStrengthPoints() << "\n\n" << std::endl;

			//std::cout << fighter2->getName() << " has attacked " << fighter1->getName() << '.' << std::endl;
			Damage dDamage = fighter2->attack();
			fighter1->calcNewStrength(dDamage.getAttackTotal(), dDamage.getAchilles());
			if (!fighter1->getInPlay())
			{
				break;
			}
			//std::cout << fighter1->getName() << "'s current strengthPoints = " << fighter1->getStrengthPoints() << "\n\n" << std::endl;
		}
		
		int winnerInitialStrength, loserInitialStrength;

		if (fighter1->getInPlay())
		{
			winner = fighter1;
			winnerInitialStrength = fighter1InitialStrength;
			loserInitialStrength = fighter2InitialStrength;
		}
		else
		{
			winner = fighter2;
			winnerInitialStrength = fighter2InitialStrength;
			loserInitialStrength = fighter1InitialStrength;
		}
			
		std::cout << winner->getName() << " has won the battle!\n" << std::endl;
		if (winner->getStrengthPoints() < winnerInitialStrength)
		{
			std::cout << winner->getName() << " incurred damage during the battle." << std::endl;
			std::cout << "If " << winner->getName() << " flips heads on a two-sided coin, half of the damage will be recovered!" << std::endl;
			bool restored = !(rand() % 2);
			if (!restored)
			{
				std::cout << winner->getName() << "'s damage was not resotred." << std::endl;
			}
			else
			{
				int restoredStrength = winner->getStrengthPoints() + (winnerInitialStrength - winner->getStrengthPoints())/2;
				std::cout << winner->getName() << " has restored strength! Strength points = " << restoredStrength << std::endl;
				winner->setStrengthPoints(restoredStrength);
			}
		}
	
		winner->setBattlePoints(loserInitialStrength);

		std::cout << winner->getName() << " is being awarded " << loserInitialStrength << " battle points" << std::endl;
}
