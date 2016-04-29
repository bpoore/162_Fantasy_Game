/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Character.hpp is the Character class specification file
*********************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Damage.hpp"

#include <string>

class Character
{
	protected:
	int numAttackDice, numAttackSides, numDefenseDice, numDefenseSides;
	int armor, strengthPoints, battlePoints, points;
	bool achillesHeel, inPlay;
	std::string name;
	std::string charType;
	std::string player;

	public:
	Character();
	~Character(); 
	virtual Damage attack() = 0;
	virtual int defense() = 0;
	int calcNewStrength(int, bool);
	void setBattlePoints(int);
	void setPlayer(std::string);
	void setStrengthPoints(int);
	bool getInPlay();
	int getStrengthPoints();
	std::string getName();
	std::string getCharType();
	int getBattlePoints();
	std::string getPlayer();
};
#endif

