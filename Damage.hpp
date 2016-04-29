/*********************************************************************
** Author: Elizabeth Poore
** Date: May 5, 2015
** Description: Damage.hpp is the Damage class specification file
*********************************************************************/
#ifndef DAMAGE_HPP
#define DAMAGE_HPP

class Damage
{	
	private:
	int attackTotal;
	bool achilles;

	public:
	Damage();
	Damage(int attack, bool aHeel);
	int getAttackTotal();
	bool getAchilles();
};
#endif

