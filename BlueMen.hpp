/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: BlueMen.hpp is the BlueMen class specification file
*********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Character
{
	public:
	BlueMen(std::string n);
	~BlueMen();
	virtual Damage attack();
	virtual int defense();
};
#endif

