/*********************************************************************
** Author: Elizabeth Poore
** Date: May 15, 2015
** Updated: May 18, 2015
** Description: FIFO.hpp is the FIFO class specification file
*********************************************************************/
#ifndef FIFO_HPP
#define FIFO_HPP

#include "Character.hpp"

class FIFO
{
	protected:
	struct ListNode
	{
		Character *character;
		ListNode *next;
		ListNode *prev;
		ListNode(Character *c, ListNode *p = NULL, ListNode *n = NULL)
		{
			character = c;
			prev = p;
			next = n;
		}
	};
	ListNode *head, *tail;

	public:
	FIFO();
	~FIFO();	
	void add(Character *);
	void displayList();
	Character* removeNode();
	bool endNode();
};
#endif




