#include "linkedlist.h"

#include <iostream>
using namespace std;

int MAXLENGTH = 250;


List::List()
//default constructor
{
	head = NULL;
	tail = NULL;
	currPos = NULL;
	length = 0;
}

List::List(const List &otherList)
//copy constructor. makes a deep copy of the otherList
{
	NodePtr fromPtr;
	NodePtr toPtr;
	
	if(otherList.head == NULL){
		head = NULL;
		tail = NULL;
		currPos = NULL;
		length = 0;
	}
	
	//copy the first node
	fromPtr = otherList.head;
	head = new Node;
	head->item = fromPtr->item;
	
	//copy the remaining nodes
	toPtr = head;
	
	fromPtr = fromPtr->next;
	
	//traverse the otherList and copy its data
	while(fromPtr != NULL){
		toPtr = new Node;
		toPtr->item = fromPtr->item;
		fromPtr = fromPtr->next;
	}
	
	tail = toPtr;
	
	return;
}

void List::Insert(ItemType newItem){
	
	//create a new node and store its data in the node
	NodePtr newNodePtr = new Node;
	newNodePtr->item = newItem;
	newNodePtr->marked = 'n';
	newNodePtr->next = NULL;
	newNodePtr->previous = NULL;
	
	//check if item is first in list
	if(length == 0){
		head = newNodePtr;
	}
	
	else{
		newNodePtr->previous = tail;
		tail->next = newNodePtr;
	}
	
	tail = newNodePtr;
	length++;
	
	return;
}

void List::Delete(ItemType delItem){
	//create temp ptrs to delete the node
	NodePtr before;
	NodePtr after;
	
	//set currPos to the front of the list
	currPos = head;
	
	//traverse the list, checking for the item 
	while(currPos != NULL){
		
		after = currPos->next;
		
		if(currPos->item == delItem){
			before = currPos;
			currPos = currPos->next;
			after = currPos->next;
			before->next = after;
			delete currPos;
		}
		currPos = currPos->next;
	}
	
	cout<<"The item was not in the list"<<endl;
	
}

void List::Reset(){
	
	//resets currPos to the beginning of the list
	currPos = head;
	return;
}

void List::MarkNode(){
	
	currPos->marked = 'y';
	
	return;
}

ItemType List::GetNextItem(){
	
	ItemType tempItem;
	
	tempItem = currPos->item;
	currPos = currPos->next;
	
	return tempItem;
}

ItemType List::GetPreviousItem(){
	
	ItemType tempItem;
	
	tempItem = currPos->item;
	
	//move backward one position after checking HasPrevious. return item
	currPos = currPos->previous;
	
	return tempItem;
	
}

ItemType List::GetCurrentItem(){
	return currPos->item;
}

int List::GetLength() const{
	
	//returns length of the list
	return length;
}

char List::GetMark() const{
	
	//returns node markd status
	return currPos->marked;
}

bool List::HasNext() const{
	
	//check if the current node is connected to any other nodes
	if(currPos->next != NULL){
		return true;
	}
	
	else{
		return false;
	}
}

bool List::HasPrevious() const{
	
	//check if the current node is the head
	if(currPos != head){
		return true;
	}
	
	else{
		return false;
	}
}

List::~List(){
	
	currPos = head;
	
	while(currPos != NULL){
		currPos = currPos->next;
		delete head;
		head = currPos;
	}
	
	delete currPos;
	
}