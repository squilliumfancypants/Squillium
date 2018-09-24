#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;


struct Node;
//forward declaration

typedef Node *NodePtr;
//used to point to next node in the list

typedef int ItemType;

struct Node{
	ItemType item;
	//holds data of struct
	
	char marked;
	
	NodePtr next;
	//points to next node
	
	NodePtr previous;
	//points to the previous node
};



class List{
	
public :

	List();
	//default constructor
	
	List(const List& otherList);
	//copy constructor
	//Makes a deep copy of otherList
	
	void Insert(ItemType newItem);
	//Pre- the item is not already in the list
	//Post- the item is in the list
	
	void Delete(ItemType delItem);
	//Pre- Item is in the list
	//Post- Item is not in the list
	
	void Reset();
	//Post- resets the current position to the first item in the list
	
	void MarkNode();
	
	ItemType GetNextItem();
	//Assumptions- No transformers are called during an iteration.
	//There is an item to be returned, that is, HasNext is true when this 
	//method is involved.
	//Post- returns the next item in the list
	
	ItemType GetPreviousItem();
	//Assumptions- No transformers are called during an iteration.
	//There is an item to be returned, that is, HasPrevious is true when this 
	//method is involved.
	//Post- returns the next item in the list
	
	ItemType GetCurrentItem();
	//returns current item
	
	int GetLength() const;
	//Post- returns the current length of the list as an int
	
	char GetMark() const;
	//Post - returns the marked status of the node
	
	bool HasNext() const;
	//Post- returns true if there is another item to be returned, false otherwise
	
	bool HasPrevious() const;
	//Post - returns true if ther is another item before, false otherwise
	
	~List();
	//destructor
	//Post- deletes the entire list
	
private:
	NodePtr head;		//pointer that points to the beginning of the list
	NodePtr tail;		//pointer that points to the end of the list
	int length;		//holds the value of the current length of the list
	NodePtr currPos;		//pointer that points to the current position in the list during traversal
	
};
#endif