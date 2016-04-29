/*********************************************************************
** Author: Elizabeth Poore
** Date: May 15, 2015
** Updated: May 18, 2015
** Description: FIFO.cpp is the FIFO class implementation file
** This first in, last out list class adds new obejcts to the tail
** of the list.
*********************************************************************/
#include <iostream>

#include "FIFO.hpp"


FIFO::FIFO() // Constructor
{ head = NULL, tail = NULL;}
	
FIFO::~FIFO() // Destructor
{
	ListNode *nodePtr = head; // Start at head of list
	while (nodePtr != NULL)
	{
		// Garbage keeps track of the node to be deleted
		ListNode *garbage = nodePtr;
		// Move on to the next node, if any
		nodePtr = nodePtr->next;
		// Delete the "garbage" node
		delete garbage;
	}
}

/*********************************************************************
**                   FIFO::add Function
** Description: This function adds a ListNode object to the tail of the list.
** Parameters: An integer value to be added to the list is passed as an argument.
** The function does not return a value.
*********************************************************************/	
void FIFO::add(Character *c)
{
	if (head == NULL)
	{
		head = new ListNode(c);
	}
	else if (tail == NULL)
	{
		tail = new ListNode(c, head, NULL);
		head->next = tail;
	} 
	else
	{
		ListNode *nodePtr = tail;
		tail = new ListNode(c, nodePtr, NULL); // Places new value to tail
		nodePtr->next = tail;
	}
}

/*********************************************************************
**                 FIFO::displayList Function
** Description: This function displays to screen the contents of the list
** Parameters: The function has no input parameters and does not return
** a value.
*********************************************************************/	
void FIFO::displayList()
{
	ListNode *nodePtr = head;
	if (!nodePtr)
	{
		std::cout << "List is empty. No list to display." << std::endl;
	}
	else
	{
		while (nodePtr)
		{
			std::cout << "Character Type: " << nodePtr->character->getCharType() << std::endl;
			std::cout << "Character Name: " << nodePtr->character->getName() << std::endl;
			std::cout << "Character's Current Strength Points = " << nodePtr->character->getStrengthPoints() << std::endl;
			std::cout << "\n\n";
			nodePtr = nodePtr->next;
		}
	}
} 

/*********************************************************************
**                 FIFO::removeNode Function
** Description: This function removes the node at the head of the list and
** returns the value being removed.
** Parameters: The function has no input parameters and returns an int, the 
** value being removed from the list.
*********************************************************************/	
Character* FIFO::removeNode()
{
	ListNode *nodePtr;
	Character *val;

	if (!head)
	{
		return NULL;
	}
	else
	{
		nodePtr = head;
		head = head->next;
		val = nodePtr->character;
		delete nodePtr;
		return val;
	}
}

/*********************************************************************
**                 FILO::endNode Function
** Description: This function returns true if the head is an empty node 
** and false otherwise.
** Parameters: The function has no input parameters and returns a bool.
*********************************************************************/
bool FIFO::endNode()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

