/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Shadow.hpp is the Shadow class specification file
*********************************************************************/
#ifndef SHADOW_HPP
#define SHADOW_HPP

class Shadow : public Character
{
	public:
	Shadow(std::string);
	~Shadow();
	virtual Damage attack();
	virtual int defense();
};
#endif


