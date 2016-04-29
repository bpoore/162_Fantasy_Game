/*********************************************************************
** Author: Elizabeth Poore
** Date: May 23, 2015
** Description: Tournament.cpp is the tournament function implementation file
*********************************************************************/	
#include <iostream>

#include "Tournament.hpp"

/*********************************************************************
**               Tournament Function
** Description: This function performs the task of implementing a complete tournament
** between two teams of characters. The tournament ends after a final winner has been 
** determined. If necessary, players from the same team will fight one another after 
** the first team has been eliminated in order to determine rankings.
** Parameters: This fucntion has input parameters of references to the player1 and player2
** queues as well as the loser list. The function does not return a value, though
** because the lists are reference parameters, they are changed.
*********************************************************************/	
void tournament(FIFO &player1, FIFO &player2, FILO &losers)
{
	int player1Score = 0;
	int player2Score = 0;
	bool switchStart = true;
	Character *fighter1 = player1.removeNode();
	Character *fighter2 = player2.removeNode();

	do
	{
		if (switchStart)
		{
			battle(fighter1, fighter2);
		}
		else
		{
			battle(fighter2, fighter1);
		}

		if (fighter1->getInPlay())
		{
			player1.add(fighter1);
			player1Score += fighter1->getBattlePoints(); // Add players score to team score

			std::cout << fighter2->getName() << " is now out of play.\n" << std::endl;
			losers.add(fighter2); 
		}
		else
		{
			player2.add(fighter2);
			player2Score += fighter2->getBattlePoints();

			std::cout << fighter1->getName() << " is now out of play.\n" << std::endl;
			losers.add(fighter1); 
		}

		// Check if teams have additional players remaining. If not, set fighter to NULL to break out of loop
		// otherwise set fighters to the next characters in the queue
	    if (player1.endNode() || player2.endNode()) 
		{
			fighter1 = NULL;
		} 
		else
		{ 
			fighter1 = player1.removeNode();
			fighter2 = player2.removeNode();
			
			if (switchStart) // Change order of fighter team initiating battle
			{
				switchStart = false;
			}
			else
			{
				switchStart = true;
			}
		}		
	} while (fighter1 != NULL);

	// Add players still living after combat to the "loser" pile in order to be considered for top places
	while (!player1.endNode()) 
	{
		fighter1 = player1.removeNode();

		if(!player1.endNode())
		{
			std::cout << "Team 1 has multiple players remaining! Fighting to determine final rankings." << std::endl;
			fighter2 = player1.removeNode();
			battle(fighter1, fighter2);

			if (fighter1->getInPlay())
			{
				player1.add(fighter1);
				player1Score += fighter1->getBattlePoints();

				std::cout << fighter2->getName() << " is now out of play.\n" << std::endl;
				losers.add(fighter2); 
			}
			else
			{
				player1.add(fighter2);
				player1Score += fighter2->getBattlePoints();

				std::cout << fighter1->getName() << " is now out of play.\n" << std::endl;
				losers.add(fighter1); 
			}
		}
		else
		{
			losers.add(fighter1);	
		}
	}

	while (!player2.endNode())
	{
		fighter1 = player2.removeNode();

		if(!player2.endNode())
		{
			std::cout << "Team 2 has multiple players remaining! Fighting to determine final rankings." << std::endl;
			fighter2 = player2.removeNode();
			battle(fighter1, fighter2);

			if (fighter1->getInPlay())
			{
				player2.add(fighter1);
				player2Score += fighter1->getBattlePoints();

				std::cout << fighter2->getName() << " is now out of play.\n" << std::endl;
				losers.add(fighter2); 
			}
			else
			{
				player2.add(fighter2);
				player2Score += fighter2->getBattlePoints();

				std::cout << fighter1->getName() << " is now out of play.\n" << std::endl;
				losers.add(fighter1); 
			}
		}
		else
		{
			losers.add(fighter1);	
		}
	}

	if (player1Score < player2Score)
	{
		std::cout << "\n\nPlayer 2 Wins " << player2Score << " points to " << player1Score << " points." << std::endl;
	}
	else if (player2Score < player1Score)
	{
		std::cout << "\n\nPlayer 1 Wins " << player1Score << " points to " << player2Score << " points." << std::endl;
	}
	else
	{
		std::cout << "There was a tie for points! The winner is to be determined by a coin flip..." << std::endl;
		bool player1Wins = !(rand() % 2);
		if (player1Wins)
		{
			std::cout << "\n\nPlayer 1 has won the battle by coin flip!" << std::endl;
		}
		else
		{
			std::cout << "\n\nPlayer 2 has won the battle by coin flip!" << std::endl;
		}
	}
}

