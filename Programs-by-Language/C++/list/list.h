/* Author- William Hampton
 * Date- 4/21/2018
 * Purpose- this is the header file for a program that takes in data from
 * 			 a file and creates an unsorted linked list with the data
*/

const int MAX_LENGTH=100;

#ifndef LIST_H
#define LIST_H

struct Node;		//forward declaration
typedef Node* NodePtr;		//pointer that points to the Node
typedef int ItemType;		//holds the value of the data in the node 

struct Node
{
	ItemType item;
	NodePtr next;
};

//define the List class that will be used to create new nodes in the linked list
class List
{
public:
	List();			//default constructor
	
	List(const List& otherList);		//copy constructor
	//Makes a deep copy of otherList
	
	void Insert(ItemType item);
	//Pre- the item is not already in the list
	//Post- the item is in the list
	
	void Delete(ItemType item);
	//Pre- Item is in the list
	//Post- Item is not in the list
	
	void Reset();
	//Post- resets the current position to the first item in the list
	
	ItemType GetNextItem();
	//Assumptions- No transformers are called during an iteration.
	//				There is an item to be returned, that is, HasNext is true when this 
	//				method is involved.
	//Post- returns the next item in the list
	
	bool IsEmpty() const;
	//Post- returns true if the list is empty, false otherwise
	
	bool IsFull() const;
	//Post- returns true if the list is full, false otherwise
	
	int GetLength() const;
	//Post- returns the current length of the list as an int
	
	bool HasNext() const;
	//Post- returns true if there is another item to be returned, false otherwise
	
	bool IsThere(ItemType item) const;
	//Post- returns true if the item is in the list, false otherwise
	
	~List();		//destructor
	//Post- deletes the entire list
	
private:
	NodePtr head;		//pointer that points to the beginning of the list
	NodePtr tail;		//pointer that points to the end of the list
	int length;		//holds the value of the current length of the list
	NodePtr currPos;		//pointer that points to the current position in the list during traversal
	
}; 

#endif 