/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Barbarian.hpp is the Barbarian class specification file
*********************************************************************/
#ifndef GOBLIN_HPP
#define GOBLIN_HPP

class Goblin : public Character
{
	public:
	Goblin(std::string n);
	~Goblin();
	virtual Damage attack();
	virtual int defense();
};
#endif



