/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Damage.cpp is the Damage class implementation file
** The damage class allows both the attack value rolled and whether or not
** a character has a cut achilles tendon to be communicated to the 
** strength function of the Character class.
*********************************************************************/
#include "Damage.hpp"

Damage::Damage() 
{ attackTotal = 0, achilles = false;}

Damage::Damage(int attack, bool aHeel)
{
	attackTotal = attack;
	achilles = aHeel;
}

int Damage::getAttackTotal()
{
	return attackTotal;
}

bool Damage::getAchilles()
{
	return achilles;
}

