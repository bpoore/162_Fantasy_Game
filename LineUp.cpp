/*********************************************************************
** Author: Elizabeth Poore
** Date: May 23, 2015
**              createLineup Function
** Description: This function allows the user to select how many creatures will 
** be fighting on each team, then allows the players to select which kinds of creatures to 
** create as well as provide it them wiht names to identify them from other creatures.
** Parameters: A pointer to character and two linked lists representing the queues for 
** the two players are input parameters. The function doesn't return anything.
** Pre-Conditions: A valid pointer to character object as well as valid FIFO class
** objects to pass to the function.
** Post-Conditions: After executing the function, the FIFO class objects will be added to.
*********************************************************************/	
#include <iostream>

#include "LineUp.hpp"

void createLineup(Character *characPtr, FIFO &player1, FIFO &player2)
{
	int teamSize;
	std::cout << "How many characters are there to be on each team?" << std::endl;
	std::cin >> teamSize;

	for (int x=1; x <=2; x++)
	{
		std::cout << "\n\nPlayer " << x << ", select your lineup of characters in order: \n\n" << std::endl;
		for(int i=0; i < teamSize; i++)
		{
			std::cout << "Select character #" << (i+1) << " for your team from the following character types:" << std::endl;
			std::cout << "1. Goblin" <<  std::endl;
			std::cout << "2. Barbarian" << std::endl;
			std::cout << "3. Reptile People" << std::endl;
			std::cout << "4. Blue Men" << std::endl;
			std::cout << "5. The Shadow" << std::endl;

			int selection;
			std::cin >> selection;

			while (selection < 1 || selection > 5)
			{
				std::cout << "Invalid selection. Please make a selection from 1-5." << std::endl;
				std::cin >> selection;
			}

			std::string name;
			std::cout << "Select a unique name for this creature: " << std::endl;
			std::cin >> name;
			
			FIFO *player;
			std::string team;

			if (x == 1)
			{
				player = &player1;
				team = "Team 1";
			}
			else
			{
				player = &player2;
				team = "Team 2";
			}
			switch(selection)
			{
				case 1:
					characPtr = new Goblin(name);
					break;
				case 2:
					characPtr = new Barbarian(name);
					break;
				case 3:
					characPtr = new Reptile(name);
					break;
				case 4:
					characPtr = new BlueMen(name);
					break;
				case 5:
					characPtr = new Shadow(name);
					break; 
			}
			characPtr->setPlayer(team);
			player->add(characPtr);
		}
	}	
}
