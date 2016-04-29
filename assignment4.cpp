/*********************************************************************
** Author: Elizabeth Poore
** Date: May 20, 2015
** Description: This program simulates a D&D style fantasy game where
** two teams of creatures are created, each in order into a linked list. 
** Creatures battle to the'death' at which time the dying creature is 
** added to the loser pile and the winner is added to the back of the line
** for additional combat. After one team has no more surviving members, 
** the tournament ceases. A winning team is determined by total number of 
** points (additional bonus points for surviving members) and the top three
** individual finishers regardless of team are announced.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Character.hpp"
#include "Battle.hpp"
#include "LineUp.hpp"
#include "Tournament.hpp"



int main()
{
	unsigned seed; // Assign seed for random number generation
	seed = time(0);
	srand(seed);

	FIFO player1, player2;
	FILO losers;
	Character *characPtr = NULL;

	createLineup(characPtr, player1, player2);

	//std::cout << "Team 1 Roster: " << std::endl;
	//player1.displayList();
	
	//std::cout << "\n\nTeam 2 Roster: " << std::endl;
	//player2.displayList();

	tournament(player1, player2, losers);

	//losers.displayList();

	std::cout << "\n\nThe top three finishers are... " << std::endl;
	Character *finisher;
	for (int x=0; x<3; x++)
	{
		if(!losers.endNode())
		{
			finisher = losers.removeNode();
			std::cout << (x+1) << " = " << finisher->getName() << " from team " << finisher->getPlayer() << std::endl;
		} 
	}

	return 0;
}




