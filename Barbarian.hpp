/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Barbarian.hpp is the Barbarian class specification file
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian : public Character
{
	public:
	Barbarian(std::string n);
	~Barbarian();
	virtual Damage attack();
	virtual int defense();
};
#endif


