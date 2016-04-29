/*********************************************************************
** Author: Elizabeth Poore
** Date: May 15, 2015
** Description: FILO.hpp is the FILO class specification file
*********************************************************************/
#ifndef FILO_HPP
#define FILO_HPP

#include "Character.hpp"

class FILO
{
	protected:
	struct ListNode
	{
		Character *character;
		ListNode *next;
		ListNode(Character *c, ListNode *n = NULL)
		{
			character = c;
			next = n;
		}
	};

	ListNode *head;

	public:
	FILO();
	~FILO();	
	void add(Character *);
	void displayList();
	Character* removeNode();
	bool endNode();
};
#endif




