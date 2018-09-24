 /*
 *PROGRAMMER:         
 *William Hampton
 *Assignment:         
 *CLA17 
 *Class:             
 *CSCI 2170-005
 *Course Instructor:  
 *Dr. Li
 *Due Date:           
 *Midnight 4/20/2018
 *Description:        
 *This is the header file for a program that reads book info from a file,
 * and creates a sorted array-based list with that info
 */
 
#include <string>
using namespace std;

const int MAX_SIZE=50;

#ifndef SLIST_H
#define SLIST_H

struct Book
{
	string title;
	string author;
	int publicationYear;
	
	bool operator <= (const Book & rhs){return (title <= rhs.title);}
	
	bool operator != (const Book & rhs){return (title != rhs.title || author != rhs.author);}
	
	bool operator < (const Book & rhs){return (title < rhs.title);}
	
	bool operator > (const Book & rhs){return (title > rhs.title);}
	
	bool operator == (const Book & rhs){return (title == rhs.title || author == rhs.author);}
};

typedef Book BookType;

class SortedList
{
public:
	SortedList();		//default constructor
	
	void Insert(BookType book);
	//Pre- the book is not in the list
	//Post- the book is in the list
	
	void Delete(BookType book);
	//Pre- the book is in the list
	//Post- the book is not in the list
	
	bool IsEmpty() const;
	//Post- returns true if there are no books in the list, false otherwise
	
	bool IsFull() const;
	//Post- returns true if the list is full, false otherwise
	
	int Size() const;
	//Post- returns the current size of the list
	
	bool IsThere(BookType book);
	//Post- returns true if the book is in the list, false otherwise
	
	BookType GetNextBook();
	//Pre- HasNext is true
	//Post- retuns the next book in the list, and advances currPos up one node
	
	void SelSort();
	//Post- sorts the list in ascending order
	
	void Reset();
	//Post- resets currPos to the beginning of the list
	
	void Replace(BookType oldbook, BookType newbook);
	//Pre- the old book is in the list, and the new book is not in the list
	//Post- replaces an book in the list with a new book
	
	void PrintList() const;
	//Post- outputs the list to the screen
	
	bool BinarySearch(BookType book) const;
	//Post- performs a binary search. returns true if the book is in the list, false otherwise
	
private:
	int size;		//number of values currently stored
	BookType aList[MAX_SIZE];		//an array of structs that holds the book information
	int currPos;			//used in iterations
};

#endif