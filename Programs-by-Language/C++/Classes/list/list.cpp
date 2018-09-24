/* Author- William Hampton
 * Date- 4/21/2018
 * Purpose- this is the imlplementation file for a program that takes in data from
 * 			 a file and creates an unsorted linked list with the data
*/ 


//this is the implementation file for creating an unsorted linked list
#include "list.h"
#include <cstddef>
using namespace std;

//***********************************************************************
//default constructor
List::List()
{
	head=NULL;
	length=0;
	currPos=NULL;
	tail=NULL;
}

//***********************************************************************

//copy constructor
List::List(const List& otherList)
{
	NodePtr fromPtr;		//pointer that points to the list being copied from
	NodePtr	toPtr;		//points to the list being copied to
	
	//this is case if the list passed in to the copy constructor is empty
	if (otherList.head==NULL)
	{
		head=NULL;
		tail=NULL;
		length=0;
		currPos=NULL;
		return;
	}
	
	//copy the first node
	fromPtr=otherList.head;		//set the pointer used to copy from to the head of the other list
	head=new Node;		//create a new node, and point the head pointer to it
	head->item=fromPtr->item;		//set the item in the new node equal to the item in the list being copied from
	
	//copy the remaining nodes
	toPtr=head;		//set the new lists pointer to the head of the new list
	fromPtr=fromPtr->next;		//advance fromPtr one position so that is now pointing to whatever heads next is pointing to
	
	while (fromPtr!=NULL)
	{
		toPtr->next=new Node;		//create a new node, and set the current nodes pointer to it
		toPtr=toPtr->next;		//set toPtr to the new node created
		toPtr->item=fromPtr->item;		//set the new nodes item equal to the copied lists item
		fromPtr=fromPtr->next;		//advance the copied lists pointer one node
	}
	
	toPtr->next=NULL;
	tail=toPtr;

}

//***********************************************************************

//insert function
void List::Insert(ItemType item)
{
	NodePtr newNodePtr= new Node;
	newNodePtr->item=item;
	newNodePtr->next=NULL;
	
	if (IsFull())
		return;
	
	if (tail==NULL)
		head=newNodePtr;
	
	else
		tail->next=newNodePtr;
	
	tail=newNodePtr;
	length++;
	
	return;
}

//***********************************************************************

ItemType List::GetNextItem()
{
	ItemType item;
	
	item=currPos->item;		//set the value of the item equal to the item in the current node of the linked list
	currPos=currPos->next;		//advance curr pos one node in the linked list
	
	return item;
}

bool List::HasNext() const
{
	if (currPos!=NULL)
		return true;
	
	else
		return false;
}

//***********************************************************************

//destructor
List::~List()
{
	NodePtr tmpPtr;
	NodePtr currPtr=head;
	
	while (currPtr!=NULL)
	{
		tmpPtr=currPtr;
		currPtr=currPtr->next;
		head=currPtr;
		tmpPtr=NULL;
		delete tmpPtr;
	}
}

//***********************************************************************

//resets the currPos to the beginning of the list. this is neccessary after inserting new nodes
void List::Reset()
{
	currPos=head;
	return;
}

//***********************************************************************

//check the list to see if it is empty

bool List::IsEmpty() const
{
	if (head==NULL)
		return true;
		
	else 
		return false;
}

//***********************************************************************

//check the list to see if it has reached the MAX_LENGTH

bool List::IsFull() const
{
	if (length==MAX_LENGTH)
		return true;
		
	else 
		return false;
}

//***********************************************************************

//check the list to see if the item is there
bool List::IsThere(ItemType item) const
{
	NodePtr currPtr=head;
	
	while (currPtr!=NULL)
	{
		if (currPtr->item==item)
			return true;
		
		currPtr=currPtr->next;
	}
	
	return false;
}

//***********************************************************************

//returns the current length of the list
int List::GetLength() const
{
	return length;
}

//***********************************************************************

//deletes an item from the List
void List::Delete(ItemType item)
{
	NodePtr currPtr=head;
	NodePtr prevPtr;
	
	if (currPtr->item==item)
	{
		head=head->next;
		currPtr->next=NULL;
		delete currPtr;
	}
	
	while (currPtr!=NULL)
	{
		if (currPtr->next->item==item)
		{
			prevPtr=currPtr;
			currPtr=currPtr->next;
			prevPtr->next=currPtr->next;
			currPtr->next=NULL;
			delete currPtr;
			return;
		}
		currPtr=currPtr->next;
	}
	return;
}