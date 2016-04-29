/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Reptile.hpp is the Reptile class specification file
*********************************************************************/
#ifndef REPTILE_HPP
#define REPTILE_HPP

class Reptile : public Character
{
	public:
	Reptile(std::string n);
	~Reptile();
	virtual Damage attack();
	virtual int defense();
};
#endif


