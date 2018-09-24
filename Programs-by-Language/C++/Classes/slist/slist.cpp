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
 *This is the implemmentation file for a program that reads book info from a file,
 * and creates a sorted array-based list with that info
 */
#include "slist.h"
#include <iostream>
using namespace std;

//********************************************************************************

//default constructor
SortedList::SortedList()
{
	size=0;
}

//********************************************************************************

//Pre- the book is not in the list
//Post- the book is in the list
void SortedList::Insert(BookType book)
{
	int index=size-1;		//set the index to the last index of the list
	
	//shift the books in the list up one to make room for the new book, as long as the 
	//new book is alphabetically before the current book in the list
	while (index >= 0 && book < aList[index])
	{
		aList[index+1]=aList[index];
		index--;
	}
	aList[index+1]=book;
	size++;
	
	return;
}

//********************************************************************************

//Pre- the book is in the list
//Post- the book is not in the list
void SortedList::Delete(BookType book)
{
	int index=size-1;
	
	//find the book in the list
	if (aList[index]!=book && index >=0)
		index--;
	else
		for (int i=index; i<size-1; i++)
		{
			aList[index]=aList[index+1];
		}
	return;
}
//********************************************************************************


//Post- returns true if there are no books in the list, false otherwise
bool SortedList::IsEmpty() const
{
	if (size==0)
		return true;
	
	else
		return false;
}
//********************************************************************************

//Post- returns true if the list is full, false otherwise
bool SortedList::IsFull() const
{
	if (size==MAX_SIZE)
		return true;
	
	else
		return false;
}
//********************************************************************************

//Post- returns the current size of the list
int SortedList::Size() const
{
	return size;
}
//********************************************************************************
bool SortedList::IsThere(BookType book)
//Post- returns true if the book is in the list, false otherwise
{
	int index;
	
	index = currPos;
	
	while (index<size && book!=aList[index])
	{
		index++;
	}
	
	if (index==size)
		return false;
	
	return true;
}

//********************************************************************************

//Pre- HasNext is true
//Post- retuns the next book in the list, and advances currPos up one node
BookType SortedList::GetNextBook()
{
	BookType book;
	
	book=aList[currPos];		//store the value of the book in the current index of the list
	
	//if the current position is at the end of the list, return to the begining of the list
	//else advance the current position by one
	if (currPos==size-1)
		currPos=0;
	
	else 
		currPos++;
		
	return book;
}
//********************************************************************************

//Post- sorts the list in ascending order
void SortedList::SelSort()
{
	int mindex=0;
	BookType temp;
	
	for (int i=0; i<size-1; i++)
	{
		for (int j=0; j<size; j++)
		{
			if (aList[mindex] > aList[j])
				aList[mindex]=aList[j];
		}
		
		if (aList[mindex]!=aList[i])
		{
			temp=aList[i];
			aList[i]=aList[mindex];
			aList[mindex]=temp;
		}
	}
	
	return;
}
//********************************************************************************

//Post- resets currPos to the beginning of the list
void SortedList::Reset()
{
	currPos=0;
}
//********************************************************************************

//Pre- the old book is in the list, and the new book is not in the list
//Post- replaces an book in the list with a new book
void SortedList::Replace(BookType oldbook, BookType newbook)
{
	while (aList[currPos]!=oldbook)
	{
		currPos++;
	}
	
	aList[currPos]=newbook;
	
	return;
}
//********************************************************************************

//outputs the list to the screen
void SortedList::PrintList() const
{
	int index=currPos;
	
	while (index!=size)
	{
		cout<<aList[index].title<<endl<<aList[index].author<<endl
			<<aList[index].publicationYear<<endl<<endl;
		index++;
	}
	
	return;
}

//********************************************************************************
bool SortedList::BinarySearch(BookType book) const
{
	int middle;
	int first=currPos;
	int last=size-1;
	
	while (last!=first)
	{
		middle=(size-1)/2;
		
		if (book==aList[middle])
			return true;
			
		else if (book > aList[middle])
			first=middle;
		
		else if (book <aList[middle])
			last=middle;
	}
	
	return false;
}
