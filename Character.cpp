/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Character.cpp is the Character class implementation file
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Character.hpp"

Character::Character()
{ 
	name = "";
	charType = "";
	inPlay = true;
	setBattlePoints(0);
	setPlayer("");
} 

Character::~Character() {}

/*********************************************************************
**             Character::calcNewStrength Function
** Description: This function determines the updated strength points after
** a character is attacked by another character.
** Parameters: The function has parameters of an integer, the attack value total
** and a bool representing if there is a cut achilles tendon or not. 
** The function returns an int, the updated strength points.
*********************************************************************/	
int Character::calcNewStrength(int attackTotal, bool aHeel)
{
	//std::cout << "Attack value = " << attackTotal << std::endl;
	int defense = this->defense();
	
	if (defense == 0 && charType == "Shadow") // Case of Shadow not present for attack
	{
		//std::cout << this->getName() << " was not present at the time of attack. No damage received." << std::endl;
		return strengthPoints;
	}

	if (aHeel && charType != "Goblin")
	{
		//std::cout << "The character is suffering from a cut achilles tendon!! Defense is half!" << std::endl;
		defense /= 2;
	}

	//std::cout << this->getName() << "'s defense =  " << defense << std::endl;
	//std::cout << this->getName() << "'s armor = " << armor << std::endl;
	int damage = attackTotal - (defense + armor);

	if (damage < 0)
	{
		//std::cout << this->getName() << " did not experience damage!" << std::endl;
		return strengthPoints;
	}	
	else if (strengthPoints - damage > 0)
	{
		//std::cout << this->getName() << " experienced " << damage << " damage points." << std::endl;
		strengthPoints -= damage;
		return strengthPoints;
	}
	else
	{
		inPlay = false;
		return 0;
	}
}

void Character::setBattlePoints(int points)
{
	this->battlePoints = points;
}

void Character::setPlayer(std::string p)
{
	this->player = p;
}

void Character::setStrengthPoints(int s)
{
	this->strengthPoints = s;
}



/*********************************************************************
**             get functions
*********************************************************************/
int Character::getStrengthPoints()
{
	return strengthPoints;
}

bool Character::getInPlay()
{
	return inPlay;
}

std::string Character::getName()
{
	return name;
}

std::string Character::getCharType()
{
	return charType;
}

int Character::getBattlePoints()
{
	return battlePoints;
}

std::string Character::getPlayer()
{
	return player;
}


