/*********************************************************************
** Author: Elizabeth Poore
** Date: May 15, 2015
** Description: FILO.cpp is the FILO class implementation file
** This first in, last out list class adds new obejcts to the head
** of the list.
*********************************************************************/
#include <iostream>

#include "FILO.hpp"


FILO::FILO() // Constructor
{ head = NULL;}

FILO::~FILO() // Destructor
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
**                   FILO::add Function
** Description: This function adds a ListNode object to the head of the list.
** Parameters: An integer value to be added to the list is passed as an argument.
** The function does not return a value.
*********************************************************************/		
void FILO::add(Character *c)
{
	if (head == NULL)
	{
		head = new ListNode(c);
	}
	else
	{
		ListNode *nodePtr = head;
		head = new ListNode(c, nodePtr); // Places new value at head of list
	}
}

/*********************************************************************
**                 FILO::displayList Function
** Description: This function displays to screen the contents of the list
** Parameters: The function has no input parameters and does not return
** a value.
*********************************************************************/	
void FILO::displayList()
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
			std::cout << nodePtr->character->getPlayer() << std::endl;
			std::cout << "Character Type: " << nodePtr->character->getCharType() << std::endl;
			std::cout << "Character Name: " << nodePtr->character->getName() << std::endl;
			std::cout << "\n\n";
			nodePtr = nodePtr->next;
		}
	}
}	

/*********************************************************************
**                 FILO::removeNode Function
** Description: This function removes the node at the head of the list and
** returns the value being removed.
** Parameters: The function has no input parameters and returns an int, the 
** value being removed from the list.
*********************************************************************/	
Character* FILO::removeNode()
{
	ListNode *nodePtr;
	Character *c = NULL;

	if (head)
	{
		nodePtr = head;
		head = head->next;
		c = nodePtr->character;
		delete nodePtr;
		return c;
	}
	else
	{
		return c;
	}
} 

/*********************************************************************
**                 FILO::endNode Function
** Description: This function returns true if the head is an empty node 
** and false otherwise.
** Parameters: The function has no input parameters and returns a bool.
*********************************************************************/	
bool FILO::endNode()
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

